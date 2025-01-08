#include <list>
#include <iostream>
#include <unistd.h>

#include "thread/thread.h"
using namespace melon::thread;

class TaskQueue : public Thread
{
public:
  TaskQueue()
  {
    pthread_mutexattr_t mutex_attr;
    pthread_mutexattr_init(&mutex_attr);
    pthread_mutexattr_settype(&mutex_attr, PTHREAD_MUTEX_ERRORCHECK);

    pthread_mutex_init(&m_mutex, &mutex_attr);
    pthread_mutexattr_destroy(&mutex_attr);

    pthread_condattr_t cond_attr;
    pthread_condattr_init(&cond_attr);

    pthread_cond_init(&m_cond, &cond_attr);
    pthread_condattr_destroy(&cond_attr);
  }

  virtual void run()
  {
    while (true)
    {
      pthread_mutex_lock(&m_mutex);
      while (m_tasks.empty())
      {
        std::cout << "waiting for comming task ... " << '\n';
        pthread_cond_wait(&m_cond, &m_mutex);
      }
      
      int num = m_tasks.front();
      m_tasks.pop_front();

      pthread_mutex_unlock(&m_mutex);
      std::cout << "num: " << num << '\n';
    }
  }

  void push(int num)
  {
    pthread_mutex_lock(&m_mutex);
    
    m_tasks.push_back(num);
    
    pthread_cond_signal(&m_cond);
    pthread_mutex_unlock(&m_mutex);
  }

private:
  pthread_mutex_t m_mutex;
  pthread_cond_t m_cond;
  std::list<int> m_tasks;
};

int main()
{
  TaskQueue queue;

  queue.start();

  for (int i = 0; i <= 7; ++ i)
  {
    ::sleep(2);
    queue.push(i);
  }

  std::getchar();

  return 0;
}



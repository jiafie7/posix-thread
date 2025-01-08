#include <list>
#include <iostream>
#include <unistd.h>

#include "thread/thread.h"
#include "thread/cond.h"

using namespace melon::thread;

class TaskQueue : public Thread
{
  public:
    TaskQueue() = default;
    ~TaskQueue() = default;

    virtual void run()
    {
      while (true)
      {
        m_mutex.lock();
        while (m_tasks.empty())
        {
          std::cout << "waiting for coming task ... " << '\n';
          m_cond.wait(&m_mutex);
        }

        int num = m_tasks.front();
        m_tasks.pop_front();

        m_mutex.unlock();
        std::cout << "num: " << num << '\n';
      }
    }

    void push(int num)
    {
      m_mutex.lock();
      m_tasks.push_back(num);
      m_cond.signal();
      m_mutex.unlock();
    }


  private:
    Mutex m_mutex;
    Cond m_cond;
    std::list<int> m_tasks;
};

int main()
{
  TaskQueue task;

  task.start();

  for (int i = 0; i <= 7; ++ i)
  {
    ::sleep(2);
    task.push(i);
  }

  return 0;
}

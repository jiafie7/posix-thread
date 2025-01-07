#include <iostream>
#include <pthread.h>

int g_num = 1;

int main()
{

  pthread_mutexattr_t attr;
  pthread_mutexattr_init(&attr);
  pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_ERRORCHECK);

  pthread_mutex_t mutex;
  pthread_mutex_init(&mutex, &attr);
  pthread_mutexattr_destroy(&attr);

  pthread_mutex_lock(&mutex);
  g_num = 2;
  pthread_mutex_unlock(&mutex);

  pthread_mutex_destroy(&mutex);

  std::getchar();

  return 0;
}


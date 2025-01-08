#pragma once

#include <pthread.h>

namespace melon
{
  namespace thread
  {
    class Mutex
    {
    public:
      Mutex();
      ~Mutex();

      void lock();
      bool tryLock();
      void unlock();

    private:
      pthread_mutex_t m_mutex;
    };
  }
}

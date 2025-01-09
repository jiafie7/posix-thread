#pragma once

#include "thread/auto_lock.h"
#include "thread/worker_thread.h"

using namespace melon::thread;

#include "thread/singleton.h"
using namespace melon::utility;

namespace melon
{
  namespace thread
  {
    class ThreadPool
    {
      SINGLETON(ThreadPool);
    public:
      void create(int threads);
      bool empty();
      void assign(Task* task);

      WorkerThread* get();
      void push(WorkerThread* thread);

    private:
      int m_threads;
      Mutex m_mutex;
      Cond m_cond;
      std::list<WorkerThread*> m_pool;
    };
  }
}

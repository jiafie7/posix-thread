#pragma once

#include <iostream>
#include "thread/task.h"

using namespace melon::thread;

namespace melon
{
  namespace task
  {
    class PrintTask : public Task
    {
    public:
      PrintTask(int* data)
        : Task((void*)data)
      {}
      ~PrintTask() = default;

      virtual void run();

      virtual void destroy();
    };
  }
}

#pragma once

#include <iostream>
#include "thread/task.h"

using namespace melon::thread;

namespace melon
{
  namespace task
  {
    class TestTask : public Task
    {
    public:
      TestTask(int* data)
        : Task((void*)data)
      {}
      ~TestTask() = default;

      virtual void run();

      virtual void destroy();
    };
  }
}

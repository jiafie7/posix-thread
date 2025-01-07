#include <iostream>

#include "thread/thread.h"

using namespace melon::thread;

class TestThread : public Thread
{
  virtual void run()
  {
    std::cout << "test thread run ... " << '\n';
  }
};

int main()
{
  TestThread test_thread;
  test_thread.start();

  std::getchar();

  return 0;
}

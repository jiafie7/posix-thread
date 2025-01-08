#include "thread/auto_lock.h"

using namespace melon::thread;

int g_num = 0;

int main()
{
  // Mutex mutex;
  // mutex.lock();
  // g_num = 1;
  // mutex.unlock();

  Mutex mutex;
  AutoLock autolock(&mutex);
  g_num = 1;

  return 0;
}

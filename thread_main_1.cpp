#include <iostream>
#include <pthread.h>

void* foo(void* data)
{
  std::cout << "data: " << *((int*)data) << '\n'; 

  return nullptr;
}

int main()
{
  int a = 7;

  pthread_attr_t attr;
  pthread_attr_init(&attr);
  pthread_attr_setscope(&attr, PTHREAD_SCOPE_SYSTEM);
  pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);

  pthread_t tid;
  pthread_create(&tid, &attr, foo, (void*)&a);

  pthread_attr_destroy(&attr);

  std::getchar();
  return 0;
}

#include "task/print_task.h"

using namespace melon::task;

void PrintTask::run()
{  
  std::cout << "task run." << '\n';
  int* data = static_cast<int*>(m_data);
  std::cout << "data: " << *data << '\n';
}
 
void PrintTask::destroy()
{
  std::cout << "task destroy." << '\n';
  delete static_cast<int*>(m_data);
  delete this;
}

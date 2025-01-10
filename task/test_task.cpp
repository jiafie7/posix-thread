#include "task/test_task.h"

using namespace melon::task;

void TestTask::run()
{  
  std::cout << "task run." << '\n';
  int* data = static_cast<int*>(m_data);
  std::cout << "data: " << *data << '\n';
}
 
void TestTask::destroy()
{
  std::cout << "task destroy." << '\n';
  delete static_cast<int*>(m_data);
  delete this;
}

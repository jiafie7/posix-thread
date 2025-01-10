# posix-thread

This C++ Thread Pool Framework efficiently manages concurrent task execution by encapsulating low-level thread operations using pthread. It features a modular design consisting of Task, TaskDispatcher, WorkerThread, and ThreadPool classes, providing a scalable and high-performance solution for multi-threaded applications.

## Features

- **Thread Pool Management**: Efficient reuse of threads to minimize overhead.
- **Task Scheduling**: Automatic task distribution through a dispatcher.
- **Synchronization Primitives**: Encapsulation of pthread mutex and condition variables.
- **Flexible Task Execution**: Easy extension through custom task definitions.
- **Scalable Architecture**: Supports configurable thread pool sizes.

## Workflow Overview

- **Task Creation**: User creates a custom task by inheriting from the Task class and implementing the run() method.
- **Task Dispatching**: Tasks are added to the TaskDispatcher, which manages the task queue.
- **Thread Pool Management**: ThreadPool provides idle WorkerThread instances to execute tasks.
- **Task Execution**: WorkerThread executes the task and returns to the pool upon completion.

## Getting Started

1. Prerequisites

   - C++ 11 or later

2. Clone the Repository

```bash
git clone https://github.com/jiafie7/posix-thread.git
cd posix-thread
```

## Usage

1. Example Code

```c
#include "thread/task_dispatcher.h"
using namespace melon::thread;

#include "task/print_task.h"
using namespace melon::task;

int main()
{
  Singleton<LogSystem>::getInstance()->open("./../main.log");
  Singleton<LogSystem>::getInstance()->setConsole(false);

  int threads = 4;
  Singleton<TaskDispatcher>::getInstance()->init(threads);

  for (int i = 0; i < 10; ++ i)
  {
    int* data = new int;
    *data = i;

    PrintTask* task = new PrintTask(data);

    Singleton<TaskDispatcher>::getInstance()->push(task);
  }

  std::getchar();

  return 0;
}
```

2. Build the Project

```bash
mkdir build
cd build
cmake ..
make
./main
```

3. Output

```bash
task run.
data: 0
task destroy.
task run.
data: 1
task destroy.
task run.
data: 2
task destroy.
task run.
data: 3
task destroy.
task run.
data: 4
task destroy.
task run.
data: 5
task destroy.
task run.
data: 6
task destroy.
task run.
data: 8
task destroy.
task run.
data: 9
task destroy.
task run.
data: 7
task destroy.
```

## API Reference

### Thread Class

- `void start()`: Starts the thread and runs run().
- `void stop()`: Stops the thread gracefully.
- `virtual void run()`: Pure virtual function for task logic.

### Mutex Class

- `void lock()`: Locks the mutex.
- `bool tryLock()`: Tries to lock without blocking.
- `void unlock()`: Unlocks the mutex.

### Cond Class

- `void wait(Mutex*)`: Waits for the condition to be signaled.
- `void signal()`: Wakes up one waiting thread.
- `void broadcast()`: Wakes up all waiting threads.

### Task Class

- `void* getData()`: Retrieves task data.
- `void setData(void*)`: Sets task data.
- `virtual void run()`: Pure virtual method to execute logic.
- `virtual void destroy()`: Cleans up task resources.

### WorkerThread Class

- `void assign(Task*)`: Assigns a task to the worker thread.
- `void run()`: Executes the assigned task.

### ThreadPool Class

- `void create(int n)`: Initializes the pool with n threads.
- `bool empty()`: Checks if the thread pool is empty.
- `void assign(Task*)`: Assigns a task to an available worker.
- `WorkerThread* get()`: Retrieves an idle worker thread.
- `void push(WorkerThread*)`: Returns a worker back to the pool.

### TaskDispatcher Class

- `void init(int threads)`: Initializes the dispatcher with a thread pool.
- `bool empty()`: Checks if the task queue is empty.
- `void push(Task*)`: Adds a task to the queue.
- `void run()`: Continuously dispatches tasks to the pool.

## License

This project is licensed under the MIT License. See the LICENSE file for details.

## Contributions

Contributions, bug reports, and feature requests are welcome. Feel free to fork the repository, open issues, or submit pull requests.

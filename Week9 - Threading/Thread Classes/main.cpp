//! THREAD CLASSES
/*
Thread Classes: 
_ Defines an obj that represents a single thread of execution in a process.
_ A thread obj is either joinable or not-joinable. A joinable represents an actual thread
of execution with a unique ID. A not-joinable represents a potential thread of execution


Future Classes:
_ Support category facilitates efficient transfer of values between tasks through shared states.
_ Retrives a value that a provider has stored in a shared state. Each provider-future pair
establishes a synchronization point for two tasks that are executing concurrently
_ A future obj is either valid or not-valid, a valid obj is assiciated with a shared state and
can retrieve the value of that shared state once it is ready

Promise Obj:
_ Creates or acquires a shared state in which it can store a value

Package_task Obj:
+ Consists of two components: A stored task and a shared state

Async Function:
+ Provides an extremely simple pair that spawns a thread to execute a task and creates
a future for retrieving the return value from that task.


*/

// Asynchronous Launch
// async.cpp

#include <iostream>
#include <thread>
#include <future>

double task(double x) { return x * 2; }

int main()
{
    std::future<double> f = std::async(task, 10);
    double r = f.get();
    std::cout << "Result = " << r << std::endl;
}
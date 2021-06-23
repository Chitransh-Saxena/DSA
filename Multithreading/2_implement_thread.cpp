#include <iostream>
#include <thread>

void printSomething()
{
    std::cout << "Something\n";
}

int main()
{
	std::thread t1(printSomething);          // thread 1 starts running
	// t1.join();                          	 // Main thread waits for the t1 to finish and once finishes, exits from main

	//If we want that t1 indepently works freely on it's own, then we should detach it from the main process
	t1.detach();			// Now it has become a daemon process

	// But above implementation can also cause one issue, that,
	// main process finishes before the thread, so the ouput of the thread is not logged on the stdout that was ran by the main process

	return 0;
}

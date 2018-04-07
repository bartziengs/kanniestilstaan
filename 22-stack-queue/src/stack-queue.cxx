/**
 * \file stack-queue.cxx
 *
 * This file is part of the course tw3720tu:
 * Object Oriented Scientific Programming with C++
 *
 * \author Matthias Moller
 *
 */

// Include header file for standard input/output stream library
#include <iostream>

// Include container classes
#include<stack>
#include<queue>

// The global main function that is the designated start of the program
int main(){

    const std::size_t size = 10;
    //typedef std::stack<int> container;
    typedef std::queue<int> container;

    container C;

    for (auto i=0; i<size; i++)
        C.push(i);

    while (!C.empty())
    {
        std::cout << C.front() << std::endl;
        C.pop();        
    }
    
    // Return code 0 to the operating system (=no error)
    return 0;
}

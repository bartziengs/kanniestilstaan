/**
 * \file reverse=engineering.cxx
 *
 * This file is part of the course tw3720tu:
 * Object Oriented Scientific Programming with C++
 *
 */

// Include header file for standard input/output stream library
#include <iostream>

// The global main function that is the designated start of the program
int main(){

    int a = 1;  
    int b = 2;
    int c = 3;
    const int d = 42;

    {
        auto b = ++a + c++; // a = 2, c= 4 (only after evaluation) b = 5
        auto e = b; //e = 5
        c += ++b; //b =66
    }

    int *p = &a; //adress of a
    int *q = &b;  //adress b

    ++(*q); //b =  7
    *p += a++ + (*p)++; //a = 2 + 3 + 4 = 9 (i guess)

    int A[] = {1, 2, 3, 4, 5};
    int *r = A;

    int e(*(r+3)); //5*4 = 20

    double f = 0;
    int g;
    for (g = 0; g < 5; g++) //f = a+5/5 = 1.0000 g = 5
        f += A[g] / 5;
    
    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
    std::cout << "c = " << c << std::endl;
    std::cout << "d = " << d << std::endl;
    std::cout << "e = " << e << std::endl;
    std::cout << "f = " << f << std::endl;
    std::cout << "g = " << g << std::endl;
    
    // Return code 0 to the operating system (=no error)
    return 0;
}

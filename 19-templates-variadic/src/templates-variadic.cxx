/**
 * \file templates-variadic.cxx
 *
 * This file is part of the course tw3720tu:
 * Object Oriented Scientific Programming with C++
 *
 * \author Matthias Moller
 *
 */

// Include header file for standard input/output stream library
#include <iostream>

// Inlcude header file for type traits
#include <type_traits>

/**
 * Demo for fixed return type double
 */

// specialisation for one parameter
template<typename A>
double static sum_double(A a)
{
    return a;
}

// generic implementation
template<typename T, typename ... Ts>
double static sum_double(T arg, Ts ... args)
{
    return arg+sum_double(args...);
}

/**
 * Demo for automatically deduced return type
 */

// specialisation for one parameter
template<typename A>
auto static sum_auto(A a) -> decltype(a)
{
    return a;
}

// generic implementation
template<typename T, typename ... Ts>
auto static sum_auto(T arg, Ts ... args) -> typename std::common_type<T, Ts...>::type
{
    return arg+sum_auto(args...);
}

// The global main function that is the designated start of the program
int main(){

    std::cout << sum_double(1.0) << std::endl;
    std::cout << sum_double(1.0, (int)1) << std::endl;
    std::cout << sum_double(1.0, (int)1, float(1.3)) << std::endl;

    std::cout << sum_auto(1.0) << std::endl;
    std::cout << sum_auto(1.0, (int)1) << std::endl;
    std::cout << sum_auto(1.0, (int)1, float(1.3)) << std::endl;
    
    // Return code 0 to the operating system (=no error)
    return 0;
}

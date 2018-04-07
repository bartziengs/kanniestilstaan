/**
 * \file linalg.cxx
 *
 * This file is part of the course tw3720tu:
 * Object Oriented Scientific Programming with C++
 *
 * \author Matthias Moller
 *
 */

#include <iostream>
#include "LALib.h"
#include "LAETLib.h"

int main() {

    {
        using namespace lalib;
        vector<double> x(10), y(10), z(10);

        x = 1.0;
        y = 2.0;
        z = 2 * x + y / (x - 3);

        std::cout << z << std::endl;
    }

    {
        using namespace laetlib;

        vector<double> x(10), y(10), z(10);

        x = 1.0;
        y = 2.0;
        z = 2 * x + y / (x - 3);
        std::cout << z << std::endl;

    }
    return 0;
}

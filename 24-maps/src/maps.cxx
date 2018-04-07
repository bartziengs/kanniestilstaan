/**
 * \file maps.cxx
 *
 * This file is part of the course tw3720tu:
 * Object Oriented Scientific Programming with C++
 *
 * \author Matthias Moller
 *
 */

// Include header file for standard input/output stream library
#include <iostream>

// Include header file for std::map type
#include <map>

// The global main function that is the designated start of the program
int main(){

    enum class Color { red, green, blue };
    
    std::map<Color, std::string> ColorMap = {
        {Color::red,   "red"},
        {Color::green, "green"},
        {Color::blue,  "blue"}
    };
    
    std::cout << (int)Color::green
              << " = "
              << ColorMap[Color::green] << "\n";
    
    std::map<std::string, Color> ColorMapReverse = {
        {"red",   Color::red},
        {"green", Color::green},
        {"blue",  Color::blue}
    };
    
    auto it = ColorMapReverse.find("green");
    std::cout << it->first        // key
              << " = "
              << (int)it->second  // value
              << "\n";
    
    // Return code 0 to the operating system (=no error)
    return 0;
}

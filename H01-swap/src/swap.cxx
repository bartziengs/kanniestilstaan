/**
 * \file swap.cxx
 *
 * This file is part of the course tw3720tu:
 * Object Oriented Scientific Programming with C++
 *
 */

// Include header file for standard input/output stream library
#include <iostream>
using namespace std;
void swapByValue(int i1, int i2);
void swapByReference(int& i1, int& i2);
void swapByAdress(int* i1, int* i2);

// The global main function that is the designated start of the program
int main(){


    // Read two integer values
    int i1,i2;
    cout << "Start by specifiying two nice integer numbers separated by a space" << endl;
    cin >> i1;     
    cin >> i2;
    cout << "Start of the program.\nValue of i1 is: " << i1 << " and value of i2 is: " << i2 << endl;

    // Start here...
    swapByValue(i1,i2);
    cout << "After swapping by value:\nValue of i1 is: " << i1 << " and value of i2 is: " << i2 << endl;

    swapByReference(i1, i2);
    cout << "After swapping by reference:\nValue of i1 is: " << i1 << " and value of i2 is: " << i2 << endl;

    swapByAdress(&i1,&i2);
    cout << "After swapping by adress:\nValue of i1 is: " << i1 << " and value of i2 is: " << i2 << endl;
    // Return code 0 to the operating system (=no error)
    return 0;
}

// void restore(int &1, int &i1o, int &i2, int &i20){

// }

void swapByValue(int i1, int i2){
    int temp = i1;
    i1=i2;
    i2=temp;
}

void swapByReference(int& i1, int& i2){
    int temp = i1;
    i1=i2;
    i2=temp;
}

void swapByAdress(int* i1, int* i2){
    int z = *i1;
    *i1 = *i2;
    *i2 = z;
}
    



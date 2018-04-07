/**
 * \file arrays.cxx
 *
 * This file is part of the course tw3720tu:
 * Object Oriented Scientific Programming with C++
 *
 */

// Include header file for standard input/output stream library
#include <iostream>
using namespace std;
void printArray(char name, int a[], int l);
void addArrays(int a[], int n1, int b[], int n2);

// The global main function that is the designated start of the program
int main(){

    // Start here...
    int n1, n2;
    cout << "Enter an integer value that specifies the size of the first array:" << endl;
    cin >> n1;
    cout << "Enter an integer value that specifies the size of the first array:" << endl;
    cin >> n2;

    int *a =  new int[n1];
    int *b =  new int[n2]; 
    // Return code 0 to the operating system (=no error)

    //fill all array entries with numbers between 1 and 10. No need to do all this from the keyboard.
    for(int i = 0; i < n1; i++){
        a[i] = rand() % 10 + 1;
    }

    for(int i = 0; i < n2; i++){
        b[i] = rand() % 10 + 1;
    }

    printArray('a',a,n1);
    printArray('b',b, n2);

    addArrays(a,n1,b,n2);

    return 0;
}


void printArray(char name, int a[], int l){
    cout << "This is the array named: " << name << endl;
    for(int i = 0; i < l; i ++){
        cout << name<< "["<<i<< "] = " << a[i] << endl;
    }
}

void addArrays(int a[], int n1, int b[], int n2){
    int length = n1;
    if(n1 < n2){
        int* temp = a;
        a = b;
        b = temp;
        int templength = n1;
        length = n2;
        n1 = n2;
        n2 = templength;
    }
    int * c = new int[length];
    for(int i = 0; i < n2; i++){
        c[i] = a[i] + b[i];
    }
    for(int i = n2; i < n1; i++){
        c[i] = a[i];
    }

    printArray('c',c,n1);
}
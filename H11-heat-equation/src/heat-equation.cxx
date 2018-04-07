#include <iostream>
#include <string.h>
#include <typeinfo>
#define PRINT_EXPRESSION(expr) std::cout << #expr << ": " << (expr) \
                                         << " (type: " << typeid(expr).name() << ")" << std::endl

//4.  Create a class template `Number` with one public `const` attribute `value` of type `T`
template <typename T>
class Vector
{
  public:
    // constructors
    Vector()
        : elements(new T[0]),
          size(0)
    {
    }

    Vector(int n) // create vector with n default elements
        : elements(new T[n]),
          size(n)
    {
    }

    Vector(T list[]) 
        : elements(list),
          size(sizeof(list)/sizeof(list[0]))
    {
    }



  private:
    T * elements;
    int size;
};

//5.  Create a [Fibonacci number] generator with templates but without functions

int main()
{

    std::cout << "test" << std::endl;
    Vector<int> a = 5;
    // Vector<int> c = { 1, 2, 3, 4 };
    int b[] = { 1, 2, 3, 4 };
    Vector<int> c = b;
    // std::cout << b[3] << std::endl;
    return 0;
}
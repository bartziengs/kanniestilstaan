#include <iostream>
#include <memory>
#include <typeinfo>
// #define PRINT_EXPRESSION(expr) std::cout << #expr << ": " << (expr) \
//                                          << " (type: " << typeid(expr).name() << ")" << std::endl

//4.  Create a class template `Number` with one public `const` attribute `value` of type `T`
template <typename T>
class Vector
{
public:
  // empty constructor
  Vector()
      : elements(nullptr),
        size(0)
  {
  }

  //constructor with size parameter
  Vector(int n) // create vector with n default elements
      : elements(new T[n]),
        size(n)
  {
  }

  //constructor with initialization list
  Vector(std::initializer_list<T> list)
      : Vector((int)list.size())
  {
    std::uninitialized_copy(list.begin(), list.end(), elements);
  }

  //copy constructor
  Vector(const Vector &v)
      : Vector(v.size)
  {
    for (auto i = 0; i < v.size; i++)
    {
      elements[i] = v.elements[i];
    }
  }

  //move constructor
  Vector(Vector &&v)
      : size(v.size),
        elements(v.elements)
  {
    v.elements = 0;
    v.data = nullptr;
  }

private:
  T *elements;
  int size;
};

//5.  Create a [Fibonacci number] generator with templates but without functions

int main()
{

  std::cout << "test" << std::endl;
  Vector<int> a(4);
  Vector<int> b = {1, 2, 3, 4};
  Vector<int> c = b;
  return 0;
}
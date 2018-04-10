#include <iostream>
#include <memory>
#include <typeinfo>
#include <stdexcept>

// PART 1 ###################################################################

template <typename T>
class Vector
{
public:
  T *elements;
  int size;
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

  //move constructor, callable with std::move
  Vector(Vector &&v)
      : size(v.size),
        elements(v.elements)
  {
    v.size = 0;
    v.elements = nullptr;
  }

  //copy assignment that calls copy constructor
  Vector &operator=(const Vector &other)
  {
    if (this != &other)
    {
      delete[] elements;
      size = other.size;
      elements = new T[other.size];
      for (auto i = 0; i < other.size; i++)
        elements[i] = other.elements[i];
    }
    return *this;
  }

  //Move assignment, call with std::move
  Vector &operator=(Vector &&other)
  {
    if (this != &other)
    {
      delete[] elements;
      size = other.size;
      elements = other.elements;
      other.size = 0;
      other.elements = nullptr;
    }
    return *this;
  }

  //minus operator, automatically determines return type
  template <typename U>
  auto operator-(const Vector<U> &other)
  {
    if (size != other.size)
      throw std::invalid_argument("Vectors are of unequal length");

    auto rtype = elements[0] - other.elements[0];
    Vector<decltype(rtype)> res(size);
    for (auto i = 0; i < size; i++)
      res.elements[i] = elements[i] - other.elements[i];

    return res;
  }

  //addition operator, automatically determines return type
  template <typename U>
  auto operator+(const Vector<U> &other)
  {
    if (size != other.size)
      throw std::invalid_argument("Vectors are of unequal length");

    auto rtype = elements[0] + other.elements[0];
    Vector<decltype(rtype)> res(size);
    for (auto i = 0; i < size; i++)
      res.elements[i] = elements[i] + other.elements[i];

    return res;
  }

  //scalar multiplication (still incomplete, workds only for same types)
  Vector<T> &operator*=(T scalar)
  {
    for (auto i = 0; i < size; i++)
      elements[i] *= scalar;
    return *this;
  }


  //dot implementation, other than in descripton but shorter and functionally equivalent
  T dot(const Vector<T> &v){
    if (size != v.size)
      throw std::invalid_argument("Vectors are of unequal length");
    T res = 0;
    for(int i = 0; i < size; i++)
    {
      res += elements[i]*v.elements[i];
    }
    return res;
  }

  //Print function, for debugging purposes
  void info()
  {
    std::cout << "Length of vector:  " << size << std::endl;
    std::cout << "Entries: [";
    for (int i = 0; i < size - 1; i++)
    {
      std::cout << elements[i] << ", ";
    }
    std::cout << elements[size - 1] << "]" << std::endl;
  }
};

//scalar multiplication (still incomplete, works only for same types)
template(scalarmultiplication)<typename T>
  Vector<T> &operator*=(T scalar, Vector<T>& vector )
  {
        return vector*=scalar;
  };

// Part 2 ####################################################################
template <typename T>
class Matrix {
private:
	T* data;
	int rows, columns, a, b;
	double x;
public:
		Matrix() //default construct
    	: data(nullptr), rows(0), columns(0) {} 

    	Matrix(int rows, int columns) //dimensions specified
    	: data(new T[rows, columns]), rows(rows), columns(columns) {}
		
		// Attributes
		// Initialize elements
		//double 
		//Matrix[{a,b}] = 

};


int main() {
  std::cout << "test" << std::endl;
  Vector<int> a = {2, 4, 6, 122};
  Vector<int> V(3);
  Vector<double> doubleVector = {1.5, 2.5, 3.5, 4.5};
  Vector<double> anotherDouble(doubleVector);
  // auto e = std::move(a);
  // a.info();
  Vector<int> b = {1, 2, 3, 4};
  Vector<int> c(b); //copy assignment
  // Vector<int> d(std::move(b)); //move assignment
  // c.info();
  auto n = a - doubleVector;
  // n.info();
  auto w = a + b;
  // w.info();
  auto res = a + doubleVector;
  // res.info();
  b.info();
  auto z = 4 * 5.6;
  std::cout << z << std::endl;

  int y = a.dot(c);
  std::cout << y << std::endl;

	Matrix<double> M(3,4);
  std::cout << z << std::endl;
  return 0;
}

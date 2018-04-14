#include <iostream>
#include <string>
#include <memory>
#include <typeinfo>
#include <stdexcept>
#include <map>
#include <array>
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
      for (auto i = 0; i < size; i++)
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

  //scalar multiplication with other type
  template <typename S>
  auto &multiply(S scalar)
  {
    for (auto i = 0; i < size; i++)
      elements[i] *= scalar;
    return *this;
  }

  //multiply with same type
  Vector<T> &multiply(T scalar)
  {
    for (auto i = 0; i < size; i++)
      elements[i] *= scalar;
    std::cout << "testHUH" << std::endl;

    return *this;
  }

  //dot product
  T dot(const Vector<T> &l, const Vector<T> &r)
  {
    if (l.size != r.size)
      throw std::invalid_argument("Vectors are of unequal length");
    T res = 0;
    for (int i = 0; i < size; i++)
    {
      res += l.elements[i] * r.elements[i];
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

template <typename T>
class Matrix
{
public:
  std::map<std::array<int, 2>, T> M;
  const int rows, columns;

  Matrix() //default constructor
      : rows(0), columns(0)
  {
  }

  Matrix(int rows, int columns) //dimensions specified
      : rows(rows), columns(columns)
  {
  }

  //matrix vector product with check for appropriate dimensions
  Vector<T> matvec(Vector<T> &v)
  {
    if (columns != v.size)
      throw std::invalid_argument("Vectors are of unequal length");
    Vector<T> res(columns);
    for (int i = 0; i < rows; i++)
    {
      for (int j = 0; j < columns; j++)
      {
        res.elements[i] += M[{i, j}] * v.elements[j];
      }
    }
    return res;
  }
};

// PART 3 ######################################################
template <typename T>
int cg(const Matrix<T> &A, const Vector<T> &b, Vector<T> &x, T tol, int maxiter)
{
  Vector<T> q;
  T rrold;
  T rrnew;
  T beta;
  T alpha;

  auto r = b - A.matvec(x);
  auto p = r;
  for (auto k = 0; k < maxiter - 1; k++)
  {
    q = A.matvec(p);
    alpha = r.dot(r, r) / p.dot(q, p);
    x += alpha;
    rrold = r.dot(r, r);
    r += r - alpha * q;
    rrnew = r.dot(r, r);
    if (rrnew < tol * tol)
      break;
    beta = rrnew / rrold;
    p = r + beta * p;
  }
};

// PART 4 ######################
template <typename T>
class Heat1D
{

public:

Matrix<T> M;
T alpha;
int dim;
double dt;
double dx;
double c;

  Heat1D(T alpha, int dim, double dt)
      : alpha(alpha), dim(dim), dt(dt)
  {
    dx = 1 / (1 + dim);
    c = (alpha * dt) / (dx * dx);
    for (auto i = 0; i < dim; i++)
    {
      for (auto j = 0; j < dim; j++)
      {
        if (i == j)
        {
          M[{i, j}] = 1 + 2 * c;
        }
        else if (j = i + 1)
        {
          if (i = 0)
            break;
          M[{i, j}] = -c;
        }
        else if (i = j + 1)
        {
          if (i = dim)
            break;
          M[{i, j}] = c;
        }
      }
    }
  }

};

int main()
{
  // auto Heat1D<double> solve(0, 222, 3, 0, 2);

  Vector<int> a = {2, 4, 6, 122};
  Vector<double> v = {1, 2, 3, 4, 5, 5, 4, 3, 2, 1};
  Vector<double> doubleVector = {1.5, 2.5, 3.5, 4.5};
  Vector<double> anotherDouble(doubleVector);

  Matrix<double> M(10, 10);
  M.M[{0, 0}] = 1.0;
  M.M[{1, 2}] = 2.0;

  // std::cout << M.M[{1,2}] << std::endl;
  auto mv = M.matvec(v);

  // a.info();
  Vector<int> b = {1, 2, 3, 4};
  b.multiply<double>(4.4);
  b.info();
  Vector<int> c(0);
  c = b;
  double co = 4.4;
  // Vector<int> nnnn = 4.4 * b;
  // c.info();
  // c = std::move(b); //move assignment
  // c.info();
  auto n = a - doubleVector;
  // n.info();
  auto w = a + b;
  // w.info();
  auto res = a + doubleVector;
  // res.info();
  // b.info();

  // doubleVector.info();

  int y = a.Vector<int>::dot(a, b);
  std::cout << y << std::endl;

  return 0;
}

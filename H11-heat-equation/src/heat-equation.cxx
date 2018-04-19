#include <iostream>
#include <string>
#include <memory>
#include <typeinfo>
#include <stdexcept>
#include <map>
#include <math.h>
#include <array>

double tol = 0.0001;
int maxIter = 10000;
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

    Vector<typename std::common_type<T, U>::type> res(size);

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

    Vector<typename std::common_type<T, U>::type> res(size);

    for (auto i = 0; i < size; i++)
      res.elements[i] = elements[i] + other.elements[i];

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

//dot product
template <typename T>
T dot(const Vector<T> &l, const Vector<T> &r)
{
  if (l.size != r.size)
    throw std::invalid_argument("Vectors are of unequal length");
  T res = 0;
  for (int i = 0; i < l.size; i++)
  {
    res += l.elements[i] * r.elements[i];
  }
  return res;
}

// Left scalar multiplication
template <typename T, typename U>
auto operator*(const T s1, const Vector<U> &v2)
{
  Vector<typename std::common_type<T, U>::type> res(v2.size);
  for (int i = 0; i < v2.size; i++)
  {
    res.elements[i] = s1 * v2.elements[i];
  }
  return res;
};

// Right scalar multiplication
template <typename T, typename U>
auto operator*(const Vector<T> &v1, const U s2)
{
  Vector<typename std::common_type<T, U>::type> res(v1.size);
  for (int i = 0; i < v1.size; i++)
  {
    res.elements[i] = v1.elements[i] * s2;
  }
  return res;
};

template <typename T>
class Matrix
{
public:
  std::map<std::array<int, 2>, T> M;
  int rows, columns;

  Matrix() //default constructor
      : rows(0), columns(0)
  {
  }

  Matrix(int rows, int columns) //dimensions specified
      : rows(rows), columns(columns)
  {
  }

  //matrix vector product with check for appropriate dimensions
  Vector<T> matvec(const Vector<T> &v) const
  {
    if (columns != v.size)
      throw std::invalid_argument("Vectors are of unequal length");
    Vector<T> res(columns);
    for (int i = 0; i < rows; i++)
    {
      for (int j = 0; j < columns; j++)
      {
        res.elements[i] += (M.at({i, j}) * v.elements[j]);
      }
    }
    return res;
  }

  T &operator[](std::initializer_list<int> list)
  {
    Vector<int> res = list;
    return M[{res.elements[0], res.elements[1]}];
  }

  void info()
  {
    std::cout << "Size of matrix:  " << rows << " x " << columns << std::endl;
    std::cout << "Entries:" << std::endl;
    for (int j = 0; j < rows; j++)
    {
      std::cout << "[";
      for (int i = 0; i < columns - 1; i++)
      {
        std::cout << M.at({j, i}) << ", ";
      }
      std::cout << M.at({j, rows - 1}) << "]" << std::endl;
    }
  }
};

// PART 3 ######################################################
template <typename T>
int cg(const Matrix<T> &A, const Vector<T> &b, Vector<T> &x, T tolcg, int maxiter)
{
  T beta;
  T alpha;
	T c;
  int iter = -1;
  auto r_i = b;
  auto r_iPlusOne = b;

  r_i = std::move(r_i - A.matvec(x));
  auto p = r_i;
  for (int i = 0; i < maxiter - 1; i++)
  {
    Vector<T> AP = A.matvec(p);
		c = dot(r_i, r_i);
    alpha = c / dot(AP, p);
    x = std::move(x + p * alpha);
    r_iPlusOne = (r_i - AP * alpha);
    double res = dot(r_iPlusOne, r_iPlusOne);
    if (res < tolcg * tolcg)
    {
      return i;
			break;
    }
    beta = res / c;
    p = std::move(r_iPlusOne + p * beta);
		r_i = r_iPlusOne;
  }
  return iter;
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
    M = Matrix<T>(dim, dim);
    dx = (double)1 / (1 + dim);
    c = (alpha * dt) / (dx * dx);
    for (int i = 0; i < dim; i++)
    {
      for (int j = 0; j < dim; j++)
      {
        if (i == j)
        {
          M.M[{i, j}] = 1 + 2 * c;
        }
        else if (j == i - 1)
        {
          M.M[{i, j}] = -c;
        }
        else if (j == i + 1)
        {
          M.M[{i, j}] = -c;
        }
        else
        {
          M.M[{i, j}] = 0;
        }
      }
    }
  }

  T &operator[](std::initializer_list<int> list)
  {
    return M[list];
  }

  Vector<double> exact(double t) const
  {
    Vector<double> w_i(dim);
    for (int i = 0, j = 1; i < dim; j++, i++)
    {
      w_i.elements[i] = sin(j * M_PI * dx);
    }
    return w_i * exp(-M_PI * M_PI * alpha * t);
  }

  Vector<double> solve(double t_end) const
  {
    Vector<double> w_i(dim);
    Vector<double> w_iPlusOne(dim);
    for (int i = 0, j = 1; i < dim; j++, i++)
    {
      w_i.elements[i] = sin(j * M_PI * dx);
    }

    int tt = (int)ceil(t_end / dt);
    for (int i = 0; i < tt; i++)
    {
      cg(M, w_i, w_iPlusOne, tol, maxIter);
      w_i = w_iPlusOne;
    }
    return w_i;
  }
};

template <typename T>
class Heat2D
{
public:
  Matrix<T> M;
  T alpha;
  int dim;
  double dt;
  double dx;
  double c;
  int dim2;

  Heat2D(T alpha, int dim, double dt)
      : alpha(alpha), dim(dim), dt(dt)
  {
    dx = (double)1 / (1 + dim);
    c = (alpha * dt) / (dx * dx);
    dim2 = dim * dim;
    M.rows = dim2;
    M.columns = dim2;
    for (auto i = 0; i < dim2; i++)
    {
      for (auto j = 0; j < dim2; j++)
      {
        if (i == j)
        {
          M.M[{i, j}] = 1 + 4 * c;
        }
        else if (j == i - 1)
        {
          M.M[{i, j}] = -c;
        }
        else if (j == i + 1)
        {
          M.M[{i, j}] = -c;
        }
        else if (j == i + dim)
        {
          M.M[{i, j}] = -c;
        }
        else if (j == i - dim)
        {
          M.M[{i, j}] = -c;
        }
        else
        {
          M.M[{i, j}] = 0;
        }
      }
    }
  }
  Vector<double> exact(double t) const
  {
    Vector<double> w_i(dim2);
    for (int j = 1; j < dim + 1; j++)
    {
			for (int i = 1; i < dim + 1; i++)
			{
      		w_i.elements[i + (j - 1) * dim - 1] = sin(j * M_PI * dx)*sin(i * M_PI * dx);
			}
    }
    return w_i * exp(-2 * M_PI * M_PI * alpha * t);
  }

  Vector<double> solve(double t_end) const
  {
    Vector<double> w_iPlusOne(dim2);
    Vector<double> w_i(dim2);
    for (int j = 1; j < dim + 1; j++)
    {
			for (int i = 1; i < dim + 1; i++)
			{
      		w_i.elements[i + (j - 1) * dim - 1] = sin(j * M_PI * dx)*sin(i * M_PI * dx);
			}
    }
    int tt = (int)ceil(t_end / dt);
    for (int i = 0; i < tt; i++)
    {
      int res = cg(M, w_i, w_iPlusOne, tol, maxIter);
      w_i = w_iPlusOne;
    }
    return w_i;
  }
};

template <typename T>
class Heat
{

public:
  Matrix<T> M;
  T alpha;
  int dim, n, dimn;
  double dt;
  double dx;
  double c;

  Heat(T alpha, int dim, double dt, int n)
      : alpha(alpha), dim(dim), dt(dt), n(n)
  {
    dimn = pow(dim, n);
    M.rows = dimn;
    M.columns = dimn;
    dx = (double)1 / (1 + dim);
    c = (alpha * dt) / (dx * dx);
    for (int i = 0; i < dimn; i++)
    {
      for (int j = 0; j < dimn; j++)
      {
        for (int k = 0; k < n; k++)
        {
          if (i == j)
          {
            M.M[{i, j}] = 1 + n * 2 * c;
          }
          else if (j == i + pow(dim, k))
          {
            M.M[{i, j}] = -c;
          }
          else if (j == i - pow(dim, k))
          {
            M.M[{i, j}] = -c;
          }
          else if (j == i + 1)
          {
            M.M[{i, j}] = -c;
          }
          else if (j == i - 1)
          {
            M.M[{i, j}] = -c;
          }
          else
          {
            M.M[{i, j}] = 0;
          }
        }
      }
    }
  }
  Vector<double> exact(double t) const
  {
    Vector<double> w_i(dimn);
    for (int i = 0, j = 1; i < dimn; j++, i++)
    {
      w_i.elements[i] = sin(j * M_PI * dx);
    }
    return w_i * exp(-n * M_PI * M_PI * alpha * t);
  }

  Vector<double> solve(double t_end) const
  {
    Vector<double> w_i(dimn);
    Vector<double> w_iPlusOne(dimn);
    for (int i = 0, j = 1; i < dimn; i++, j++)
    {
      w_i.elements[i] = sin(j * M_PI * dx);
    }
    int tt = (int)ceil(t_end / dt);
    for (int i = 0; i < tt; i++)
    {
      int res = cg(M, w_i, w_iPlusOne, tol, maxIter);
      w_i = w_iPlusOne;
    }
    return w_i;
  }
};

int main()
{
  double alpha = 0.3125;
  int dim = 3;
  double dt = 0.001;
  double t_end = 1;

  std::cout << "Evaluating the solution for:" << std::endl;
  std::cout << "Alpha = " << alpha << std::endl;
  std::cout << "dim = " << dim << std::endl;
  std::cout << "dt = " << dt << "s" << std::endl;
  std::cout << "At t = " << t_end << "s" << std::endl;

  Heat1D<double> sol(alpha, dim, dt);
  sol.M.info();
  Vector<double> U1 = sol.exact(t_end);
  std::cout << "Vector U1D (exact result)" << std::endl;
  U1.info();
  auto W1 = sol.solve(t_end);
  std::cout << "Vector W1D (solved result)" << std::endl;
  W1.info();
	std::cout << " " << std::endl;

	std::cout << "difference U1D - W1D = " << std::endl;
	Vector<double> R1 = U1 - W1;
	R1.info();

  Heat2D<double> sol2(alpha, dim, dt);
  auto U2 = sol2.exact(t_end);
  auto W2 = sol2.solve(t_end);
	std::cout << "Matrix M2D: " << std::endl;
  sol2.M.info();
  std::cout << "Vector U2D (exact result)" << std::endl;
  U2.info();
  std::cout << "Vector W2D (solved result)" << std::endl;
	W2.info();
	std::cout << "difference U2D - W2D = " << std::endl;
	Vector<double> R2 = U2 - W2;
	R2.info();
	std::cout << " " << std::endl;

	//Heat<double> soln(alpha, dim, dt, 2);
	//std::cout << "Matrix MnD: " << std::endl;
	//soln.M.info();
  //auto Un = soln.exact(t_end);
  //auto Wn = soln.solve(t_end);
  //std::cout << "Vector UnD (exact result)" << std::endl;
  //Un.info();
  //std::cout << "Vector WnD (solved result)" << std::endl;
  //Wn.info();

  return 0;
}

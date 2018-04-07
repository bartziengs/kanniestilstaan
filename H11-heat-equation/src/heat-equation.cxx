#include <iostream>
#include <memory>
#include <typeinfo>
// #define PRINT_EXPRESSION(expr) std::cout << #expr << ": " << (expr) \
//                                          << " (type: " << typeid(expr).name() << ")" << std::endl

// PART 1 ###################################################################
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
    v.size = 0;
    v.elements = nullptr;
  }

  private:
    T * elements;
    int size;
};

// PART 2 ###################################################################
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

// Matrix vector multiplication function
// double MVmult(const Matrix& A, const Vector& b)
// {
//		int rows = b.length;
	//	int columns = A.columns
      //  double x=0;
        //for (auto i=0; i<rows; i++)
			//for(auto j=0; j<columns; j++)
				//x[i] += A[i,j]*b[j];
      //  return x;
//}


// PART 3 ###################################################################
    //template<typename T>
    //int cg(
    //    const Matrix<T> &A, const Vector<T> &b, Vector<T> &x, T tol, I maxiter)
    //{
	
    //}

// MAIN #####################################################################
int main()
{
    std::cout << "test" << std::endl;
    Vector<int> a = 5;
    // Vector<int> c = { 1, 2, 3, 4 };
    int b[] = { 1, 2, 3, 4 };
    // std::cout << b[3] << std::endl;
	Matrix<double> M(10,20);
	//M[{1,1}] = 69;
return 0;
}


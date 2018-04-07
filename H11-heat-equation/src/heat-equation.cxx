#include <iostream>
#include <string.h>
#include <typeinfo>
#define PRINT_EXPRESSION(expr) std::cout << #expr << ": " << (expr) \
                                         << " (type: " << typeid(expr).name() << ")" << std::endl

// PART 1 ###################################################################
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
    Vector<int> c = b;
    // std::cout << b[3] << std::endl;
	Matrix<double> M(10,20);
	//M[{1,1}] = 69;
return 0;
}



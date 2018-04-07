#include <iostream>
#include <math.h>

template <int value>
struct ConstInt
{
    static const double eval(double x)
    {
        return value;
    };
    typedef ConstInt<0> derivative;
};

template <typename F, typename G>
struct Add
{
    static const double eval(double x)
    {
        return F::eval(x) + G::eval(x);
    }
    typedef Add<typename F::derivative, typename G::derivative> derivative;
};

template <typename F, typename G>
struct Mul
{
    static const double eval(double x)
    {
        return F::eval(x) * G::eval(x);
    }
    typedef Add<Mul<typename F::derivative, G>, Mul<F, typename G::derivative>> derivative;
};

template <int exponent>
struct Monomial
{
    static const double eval(double x)
    {
        return pow(x, exponent);
    }
    typedef Mul<ConstInt<exponent>, Monomial<(exponent - 1)>> derivative;
};

template <typename F>
struct Neg
{
    static const double eval(double x)
    {
        return F::eval(x) * 1;
    }
    typedef Neg<typename F::derivative> derivative;
};

struct Cos;
struct Sin
{
    static const double eval(double x)
    {
        return sin(x);
    }
    typedef Cos derivative;
};

struct Cos
{
    static const double eval(double x)
    {
        return cos(x);
    }
    typedef Neg<Sin> derivative;
};

int main()
{

    std::cout << ConstInt<8>::derivative::eval(8) << std::endl;
    std::cout << Add<ConstInt<7>, ConstInt<3>>::eval(20) << std::endl;
    std::cout << Add<ConstInt<7>, ConstInt<3>>::derivative::eval(245) << std::endl;
    std::cout << Mul<ConstInt<7>, ConstInt<3>>::eval(1) << std::endl;
    std::cout << Neg<ConstInt<7>>::derivative::eval(99) << std::endl;
    std::cout << Monomial<3>::eval(2) << std::endl;
    std::cout << Neg<Monomial<3>>::derivative::eval(2) << std::endl;
    std::cout << Sin::eval(0) << "  " << Cos::eval(1) << std::endl;

    return 0;
}

#include <iostream>
#include <string.h>
#include <typeinfo>
#define PRINT_EXPRESSION(expr) std::cout << #expr << ": " << (expr) \
                                         << " (type: " << typeid(expr).name() << ")" << std::endl

//1.  Create a function template `add_simple`
template <typename T>
T add_simple(T a, T b)
{
    return a + b;
}

//2.  Create a function template `add` that takes two arguments
template <typename A, typename B>
auto add(A a, B b)
{
    return a + b;
}

//3.  Create a function template `is_int` that takes one argument makes uses of template specialization
template <typename A>
bool is_int(A a)
{
    return false;
}

template <>
bool is_int<int>(int a)
{
    return true;
}

//4.  Create a class template `Number` with one public `const` attribute `value` of type `T`
template <typename T>
class Number
{
  public:
    const T value;

    Number(T value)
        : value(value)
    {
    }

    template <typename U>
    auto operator+(const Number<U> &u) 
    {
        auto res = value + u.value;
        return Number<decltype(res)>(res);
    }

    template <typename U>
    auto operator-(const Number<U> &u) 
    {
        auto res = value - u.value;
        return Number<decltype(res)>(res);
    }

    template <typename U>
    auto operator*(const Number<U> &u) 
    {
        auto res = value * u.value;
        return Number<decltype(res)>(res);
    }

    template <typename U>
    auto operator/(const Number<U> &u) 
    {
        auto res = value / u.value;
        return Number<decltype(res)>(res);
    }
};

//5.  Create a [Fibonacci number] generator with templates but without functions

template <int n>
struct fibonacci
{
    static const int value = fibonacci<n-1>::value + fibonacci<n-2>::value;
};

template <>
struct fibonacci<0>
{
    static const int value = 1;
};

template <>
struct fibonacci<1>
{
    static const int value = 1;
};

int main()
{
    PRINT_EXPRESSION(add_simple(1, 2));
    PRINT_EXPRESSION(add_simple(1.5, 2.2));
    PRINT_EXPRESSION((add<double, int>(1.5, 2)));
    PRINT_EXPRESSION((add<int, double>(1, 2.65)));
    PRINT_EXPRESSION(is_int(3));
    PRINT_EXPRESSION(is_int(3.54658748));
    auto a = Number<int>(2);
    auto b = Number<double>(3.5);
    auto c = a + b;
    auto d = a - b;
    auto e = a * b;
    auto f = a / b;
    PRINT_EXPRESSION(c.value);
    PRINT_EXPRESSION(d.value);
    PRINT_EXPRESSION(e.value);
    PRINT_EXPRESSION(f.value);
    PRINT_EXPRESSION((Number<int>(2) * Number<int>(2)).value);
    std::cout << fibonacci<7>::value << std::endl;
    return 0;
}
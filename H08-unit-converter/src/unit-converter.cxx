#include <iostream>

//Implement the above enumeration `Unit`.
enum class Unit
{
    km = 1,
    m = 2,
    cm = 3
};

//2.  Implement a `Measure` trait with two template parameters one for the length `value` (stored as integer) and one for the `Unit`

template <int v, Unit u>
struct Measure
{
    const static int value = v;
    const static Unit unit = u;
};

//Basic template
template<Unit, Unit>
struct conversion{
    static const int a = 1;
    static const int b = 1;
};

//Measurement-specific templates
template<>
struct conversion<Unit::cm, Unit::m>{
    static const int a = 1;
    static const int b = 100;
};

template<>
struct conversion<Unit::cm, Unit::km>{
    static const int a = 1;
    static const int b = 10000;
};

template<>
struct conversion<Unit::m, Unit::km>{
    static const int a = 1;
    static const int b = 1000;
};

template<>
struct conversion<Unit::m, Unit::cm>{
    static const int a = 100;
    static const int b = 1;
};

template<>
struct conversion<Unit::km, Unit::cm>{
    static const int a = 10000;
    static const int b = 1;
};

template<>
struct conversion<Unit::km, Unit::m>{
    static const int a = 1000;
    static const int b = 1;
};

template<typename M1 ,typename M2>
struct smallest{
    static const Unit u = (int)M1::unit < (int) M2::unit ? (M1::unit) : (M2::unit);
};


//3.  Write a `Measure_add` trait that takes two `Measure` traits as template parameters,
template <typename M1, typename M2>
struct Measure_add
{
    const static int value = conversion<M1::unit,M2::unit>::a*M1::value + conversion<M1::unit,M2::unit>::b*M2::value;
    const static Unit unit = smallest<M1,M2>::u;
};

//4.  Test your implementation for different measures, e.g.,

int main()
{
    using M1 = Measure<10, Unit::cm>;
    using M2 = Measure<20, Unit::cm>;

    std::cout << M1::value << std::endl;

    using Sum = Measure_add<M1, M2>;

    std::cout << Sum::value << std::endl;
    //
    std::cout << Measure_add< Measure<10,Unit::m>, Measure<20,Unit::m> >::value  << std::endl;
    std::cout << Measure_add< Measure<10,Unit::km>, Measure<20,Unit::cm> >::value << std::endl;
    std::cout << Measure_add< Measure<100,Unit::cm>, Measure<20,Unit::m> >::value << std::endl;
    
}
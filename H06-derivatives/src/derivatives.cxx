#include <iostream>
#include <functional>

class Derivative
{
  public:
    virtual double differentiate(
            std::function<double(double)> func, double x) = 0;
    
    Derivative(double h)
    : h(h)
    {}

    Derivative()
    :h(1e-8)
    {}

    protected:
    double h;
};

class CentralDifference : public Derivative
{
  public:
    using Derivative::Derivative;
    virtual double differentiate(
            std::function<double(double)> func, double x){
        return (func(x+h) - func(x-h)) / (2*h);
    }
};

class ForwardDifference : public Derivative
{
  public:
    using Derivative::Derivative;
    virtual double differentiate(
            std::function<double(double)> func, double x){
        return (func(x+h) - func(x)) / h;
    }
};

//classical function
double test1(double x)
        {
            return 2*x + 9;
        };

//lambda function
auto test2 = [](double x) { return 3*x*x-6; };

int main()
{
   std::cout << "Testing" << std::endl;

    CentralDifference CD;
    std::cout << "Central Diffrence of test1: " << CD.differentiate(test1, 3) << std::endl;
    std::cout << "Central Diffrence of test2: " << CD.differentiate(test2, 4) << std::endl;

    ForwardDifference FD;
    std::cout << "Forward Diffrence of test2: " << FD.differentiate(test1, 3) << std::endl;
    ForwardDifference FD1(1e-10); //try with other spacing parameter
    std::cout << "Forward Diffrence of test2: " << FD1.differentiate(test2, 3) << std::endl;

    return 0;
}
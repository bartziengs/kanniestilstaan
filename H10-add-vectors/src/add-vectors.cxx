#ifdef _MSC_VER
#define NOINLINE __declspec(noinline)
#else
#define NOINLINE __attribute__((noinline))
#endif

#include <vector>
#include <iostream>

/*********
 * results:
    testing simple

    real    0m1.140s
    user    0m0.768s
    sys     0m0.364s

    testing singleloop

    real    0m0.347s
    user    0m0.328s
    sys     0m0.008s
 * 
 * The difference between the single loop and simple version of the add_vectors can be explained 
 * because of the single loop having less intermediate computations because in the add_elem method the eventual 
 * compuation is just one big summation of every i-th element. Whereas in the simple version there are for n vectors n+1 intermediate vectors
 * which is worse in terms of time and memory
 **************/

//base case for add_elem
template <typename V>
V add_elem(int i, const std::vector<V> &head)
{
    return head[i];
}

//2.  Create a function template `add_elems(i, ...)` that adds all `i`-th elements of the vector arguments.
template <typename V, typename... T>
V add_elem(int i, const std::vector<V> &head, const T &... tail)
{
    return head[i] + add_elem(i, tail...);
}

//3.  Implement a function template `add_vectors_singleloop` that adds the `std::vector` arguments in a single loop.
// TODO: Replace the following function template.  You may change the template
// arguments and function arguments if necessary.
template <typename V, typename... T>
std::vector<V> add_vectors_singleloop(
    const std::vector<V> &head, const T &... tail)
{
    std::vector<V> result(head.size());
    for (auto i = 0; i < head.size(); i++)
    {
        result[i] = add_elem(i, head, tail...);
    }
    return result;
}

//1.  Create function template `add_vectors_simple` that takes two or more `std::vector<V>` arguments,
// TODO: Replace the following function template.  You may change the template
// arguments and function arguments if necessary.
template <typename V>
V add_vectors_simple(const V &head, const V &tail)
{
    V result(head.size());
    for (auto i = 0; i < head.size(); i++)
    {
        result[i] = head[i] + tail[i];
    }
    return result;
}

template <typename V, typename... T>
V add_vectors_simple(
    const V &head, const V &second, const T &... tail)
{
    V result(head.size());
    return add_vectors_simple(head, add_vectors_simple(second, tail...));
}

NOINLINE std::vector<double> test_add_vectors_singleloop(
    const std::vector<double> &a, const std::vector<double> &b,
    const std::vector<double> &c, const std::vector<double> &d)
{
    return add_vectors_singleloop(a, b, c, d);
}

NOINLINE std::vector<double> test_add_vectors_simple(
    const std::vector<double> &a, const std::vector<double> &b,
    const std::vector<double> &c, const std::vector<double> &d)
{
    return add_vectors_simple(a, b, c, d);
}

#include <cstring>

int main(int argc, char **argv)
{
    int n = 1000000;
    std::vector<double> a(n);
    std::vector<double> b(n);
    std::vector<double> c(n);
    std::vector<double> d(n);
    if (argc == 2)
    {
        if (strcmp(argv[1], "simple") == 0)
        {
            std::cout << "testing simple" << std::endl;
            for (int i = 0; i < 100; i++)
                test_add_vectors_simple(a, b, c, d);
            return 0;
        }
        else if (strcmp(argv[1], "singleloop") == 0)
        {
            std::cout << "testing singleloop" << std::endl;
            for (int i = 0; i < 100; i++)
                test_add_vectors_singleloop(a, b, c, d);
            return 0;
        }
    }
    std::cout << "USAGE: " << argv[0] << " simple|singleloop" << std::endl;
}

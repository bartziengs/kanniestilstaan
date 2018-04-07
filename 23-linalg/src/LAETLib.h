/**
 * \file LAETLib.h
 *
 * This file is part of the course tw3720tu:
 * Object Oriented Scientific Programming with C++
 *
 * \author Matthias Moller
 *
 */

// Include safeguard
#ifndef LAETLIB_H
#define LAETLIB_H

// Include header file for standard input/output stream library
#include <iostream>

// Make separate namespace
namespace laetlib {

// Common base class of all vector expressions
class vectorBase {};


template<typename T>
class vector : public vectorBase {
public:
    // Default constructor
    vector()
    : n(0), data(nullptr) {}

    // Size constructor
    vector(std::size_t n)
    : n(n), data(new T[n]) {}

    // Copy constructor
    vector(const vector<T> &other)
    : vector(other.size()) {
        for (std::size_t i = 0; i < other.size(); i++)
            data[i] = other.data[i];
    }

    // Move constructor
    vector(vector<T> &&other) {
        data = other.data;
        other.data = nullptr;
        n = other.n;
        other.n = 0;
    }

    // Destructor
    ~vector() {
        delete[] data;
        data = nullptr;
        n = 0;
    }

    // Assignment operator (scalar value)
    const vector<T>& operator=(const T& value) {
        for (std::size_t i = 0; i < size(); i++)
            data[i] = value;
        return *this;
    }

    // Copy assignment operator
    const vector<T>& operator=(const vector<T> &other)  {
        if (this != &other) {
            delete[] data;
            n = other.size();
            data = new T[n];
            for (std::size_t i = 0; i < other.size(); i++)
                data[i] = other.data[i];
        }
        return *this;
    }

    // Move assignment operator
    const vector<T>& operator=(vector<T> &&other) {
        if (this != &other) {
            std::swap(this->data, other.data);
            std::swap(this->n, other.n);
            other.n = 0;
            delete[] other.data;
            other.data = nullptr;
        }
        return *this;
    }

    // Assignment operator (vector expression)
    template <typename E>
    vector<T>& operator=(const E& e) {
        for (std::size_t i = 0; i < size(); i++)
            data[i] = e.get(i);
        return *this;
    }
    
    // Returns the size of the vector object
    inline const std::size_t &size() const {
        return n;
    }

    // Returns constant reference to the raw data array
    inline const T &get(std::size_t &index) const {
        return data[index];
    }

    // Returns reference to the raw data array
    inline T &get(std::size_t &index) {
        return data[index];
    }

    // Store value type
    using value_type = T;

private:
    // Attributes
    T *data;
    std::size_t n;
};

// Helper class for binary operation: addition of two vector expressions
template<typename E1, typename E2>
class VectorAdd : vectorBase {
private:
    // Attributes
    const E1& e1;
    const E2& e2;

public:
    // Constructor
    VectorAdd(const E1& e1, const E2& e2)
    :e1(e1), e2(e2)
    {}

    // Returns evaluated vector expression
    inline const typename std::common_type<typename E1::value_type,
                                           typename E2::value_type>::type get(std::size_t index) const {
        return e1.get(index)+e2.get(index);
    }

    // Store value type
    using value_type = typename std::common_type<typename E1::value_type,
                                                 typename E2::value_type>::type;
};

// Helper class for binary operation: element-wise addition of a scalar and a vector
template<typename T1, typename E2>
class ScalarVectorAdd : vectorBase {
private:
    // Attributes
    const T1& t1;
    const E2& e2;

public:
    // Constructor
    ScalarVectorAdd(const T1& t1, const E2& e2)
    :t1(t1), e2(e2)
    {}

    // Returns evaluated vector expression
    inline const typename std::common_type<T1, typename E2::value_type>::type get(std::size_t index) const {
        return t1+e2.get(index);
    }

    // Store value type
    using value_type = typename std::common_type<T1, typename E2::value_type>::type;
};

// Helper class for binary operation: element-wise addition of a vector and a scalar
template<typename E1, typename T2>
class VectorScalarAdd : vectorBase {
private:
    // Attributes
    const E1& e1;
    const T2& t2;

public:
    // Constructor
    VectorScalarAdd(const E1& e1, const T2& t2)
    :e1(e1), t2(t2)
    {}

    // Returns evaluated vector expression
    inline const typename std::common_type<typename E1::value_type, T2>::type get(std::size_t index) const {
        return e1.get(index)+t2;
    }

    // Store value type
    using value_type = typename std::common_type<typename E1::value_type, T2>::type;
};

// Binary operator: addition of two vector expressions
template<typename E1, typename E2>
auto operator+(const E1& e1, const E2& e2)
    -> typename std::enable_if<std::is_base_of<vectorBase,E1>::value &&
                               std::is_base_of<vectorBase,E2>::value,
                               VectorAdd<E1,E2>>::type
{
    return VectorAdd<E1,E2>(e1,e2);
}

// Binary operator: element-wise addition of a scalar with a vector expression
template<typename T1, typename E2>
auto operator+(const T1& t1, const E2& e2)
    -> typename std::enable_if<!std::is_base_of<vectorBase,T1>::value &&
                               std::is_base_of<vectorBase,E2>::value,
                               ScalarVectorAdd<T1,E2>>::type
{
    return ScalarVectorAdd<T1,E2>(t1,e2);
}

// Binary operator: element-wise addition of a vector expression with a scalar
template<typename E1, typename T2>
auto operator+(const E1& e1, const T2& t2)
    -> typename std::enable_if<std::is_base_of<vectorBase,E1>::value &&
                               !std::is_base_of<vectorBase,T2>::value,
                                VectorScalarAdd<E1,T2>>::type
{
    return VectorScalarAdd<E1,T2>(e1,t2);
}

// Helper class for binary operation: subtraction of two vector expressions
template<typename E1, typename E2>
class VectorSub : public vectorBase {
private:
    // Attributes
    const E1& e1;
    const E2& e2;

public:
    // Constructor
    VectorSub(const E1& e1, const E2& e2)
    :e1(e1), e2(e2)
    {}

    // Returns evaluated vector expression
    inline const typename std::common_type<typename E1::value_type,
                                           typename E2::value_type>::type get(std::size_t index) const {
        return e1.get(index)-e2.get(index);
    }

    // Store value type
    using value_type = typename std::common_type<typename E1::value_type,
                                                 typename E2::value_type>::type;
};

// Helper class for binary operation: element-wise subtraction of a vector expression from a scalar
template<typename T1, typename E2>
class ScalarVectorSub : vectorBase {
private:
    // Attributes
    const T1& t1;
    const E2& e2;

public:
    // Constructor
    ScalarVectorSub(const T1& t1, const E2& e2)
    :t1(t1), e2(e2)
    {}

    // Returns evaluated vector expression
    inline const typename std::common_type<typename T1::value_type,
                                           typename E2::value_type>::type get(std::size_t index) const {
        return t1-e2.get(index);
    }

    // Store value type
    using value_type = typename std::common_type<T1, typename E2::value_type>::type;
};


// Helper class for binary operation: element-wise subtraction of a scalar from a vector expression
template<typename E1, typename T2>
class VectorScalarSub : vectorBase {
private:
    // Attributes
    const E1& e1;
    const T2& t2;

public:
    // Constructor
    VectorScalarSub(const E1& e1, const T2& t2)
    :e1(e1), t2(t2)
    {}

    // Returns evaluated vector expression
    inline const typename std::common_type<typename E1::value_type, T2>::type get(std::size_t index) const {
        return e1.get(index)-t2;
    }

    // Store value type
    using value_type = typename std::common_type<typename E1::value_type, T2>::type;
};

// Binary operator: subtraction of two vector expressions
template<typename E1, typename E2>
auto operator-(const E1& e1, const E2& e2)
    -> typename std::enable_if<std::is_base_of<vectorBase,E1>::value &&
                               std::is_base_of<vectorBase,E2>::value,
                               VectorSub<E1,E2>>::type
{
    return VectorSub<E1,E2>(e1,e2);
}

// Binary operator: element-wise subtraction of a vector expression from a scalar
template<typename T1, typename E2>
auto operator-(const T1& t1, const E2& e2)
    -> typename std::enable_if<!std::is_base_of<vectorBase,T1>::value &&
                               std::is_base_of<vectorBase,E2>::value,
                               ScalarVectorSub<T1,E2>>::type
{
    return ScalarVectorSub<T1,E2>(t1,e2);
}

// Binary operator: element-wise subtraction of a scalar from a vector expression
template<typename E1, typename T2>
auto operator-(const E1& e1, const T2& t2)
    -> typename std::enable_if<std::is_base_of<vectorBase,E1>::value &&
                               !std::is_base_of<vectorBase,T2>::value,
                               VectorScalarSub<E1,T2>>::type
{
    return VectorScalarSub<E1,T2>(e1,t2);
}

// Helper class for binary operation: multiplication of two vector expressions
template<typename E1, typename E2>
class VectorMul : public vectorBase {
private:
    // Attributes
    const E1& e1;
    const E2& e2;

public:
    // Constructor
    VectorMul(const E1& e1, const E2& e2)
    :e1(e1), e2(e2)
    {}

    // Returns evaluated vector expression
    inline const typename std::common_type<typename E1::value_type,
                                           typename E2::value_type>::type get(std::size_t index) const {
        return e1.get(index)*e2.get(index);
    }

    // Store value type
    using value_type = typename std::common_type<typename E1::value_type,
                                                 typename E2::value_type>::type;
};

// Helper class for binary operation: element-wise multiplication of a scalar with a vector
template<typename T1, typename E2>
class ScalarVectorMul : vectorBase {
private:
    // Attributes
    const T1& t1;
    const E2& e2;

public:
    // Constructor
    ScalarVectorMul(const T1& t1, const E2& e2)
    :t1(t1), e2(e2)
    {}

    // Returns evaluated vector expression
    inline const typename std::common_type<T1, typename E2::value_type>::type get(std::size_t index) const {
        return t1*e2.get(index);
    }

    // Store value type
    using value_type = typename std::common_type<T1, typename E2::value_type>::type;
};


// Helper class for binary operation: element-wise multiplication of a vector with a scalar
template<typename E1, typename T2>
class VectorScalarMul : vectorBase {
private:
    // Attributes
    const E1& e1;
    const T2& t2;

public:
    // Constructor
    VectorScalarMul(const E1& e1, const T2& t2)
    :e1(e1), t2(t2)
    {}

    // Returns evaluated vector expression
    inline const typename std::common_type<typename E1::value_type, T2>::type get(std::size_t index) const {
        return e1.get(index)*t2;
    }

    // Store value type
    using value_type = typename std::common_type<typename E1::value_type, T2>::type;
};

// Binary operator: element-wise multiplication of two vector expressions
template<typename E1, typename E2>
auto operator*(const E1& e1, const E2& e2)
    -> typename std::enable_if<std::is_base_of<vectorBase,E1>::value &&
                               std::is_base_of<vectorBase,E2>::value,
                               VectorMul<E1,E2>>::type
{
    return VectorMul<E1,E2>(e1,e2);
}

// Binary operator: element-wise multiplication of a scalar and a vector expression
template<typename T1, typename E2>
auto operator*(const T1& t1, const E2& e2)
    -> typename std::enable_if<!std::is_base_of<vectorBase,T1>::value &&
                               std::is_base_of<vectorBase,E2>::value,
                               ScalarVectorMul<T1,E2>>::type
{
    return ScalarVectorMul<T1,E2>(t1,e2);
}

// Binary operator: element-wise multiplication of a vector expression and a scalar
template<typename E1, typename T2>
auto operator*(const E1& e1, const T2& t2)
    -> typename std::enable_if<std::is_base_of<vectorBase,E1>::value &&
                               !std::is_base_of<vectorBase,T2>::value,
                               VectorScalarMul<E1,T2>>::type
{
    return VectorScalarMul<E1,T2>(e1,t2);
}

// Helper class for binary operation: division of two vector expressions
template<typename E1, typename E2>
class VectorDiv : public vectorBase {
private:
    // Attributes
    const E1& e1;
    const E2& e2;

public:
    // Constructor
    VectorDiv(const E1& e1, const E2& e2)
    :e1(e1), e2(e2)
    {}

    // Returns evaluated vector expression
    inline const typename std::common_type<typename E1::value_type,
                                           typename E2::value_type>::type get(std::size_t index) const {
        return e1.get(index)/e2.get(index);
    }

    // Store value type
    using value_type = typename std::common_type<typename E1::value_type,
                                                 typename E2::value_type>::type;
};

// Helper class for binary operation: element-wise division of a scalar by a vector
template<typename T1, typename E2>
class ScalarVectorDiv : vectorBase {
private:
    // Attributes
    const T1& t1;
    const E2& e2;

public:
    // Constructor
    ScalarVectorDiv(const T1& t1, const E2& e2)
    :t1(t1), e2(e2)
    {}

    // Returns evaluated vector expression
    inline const typename std::common_type<T1, typename E2::value_type>::type get(std::size_t index) const {
        return t1/e2.get(index);
    }

    // Store value type
    using value_type = typename std::common_type<T1, typename E2::value_type>::type;
};


// Helper class for binary operation: element-wise division of a vector by a scalar
template<typename E1, typename T2>
class VectorScalarDiv : vectorBase {
private:
    // Attributes
    const E1& e1;
    const T2& t2;

public:
    // Constructor
    VectorScalarDiv(const E1& e1, const T2& t2)
    :e1(e1), t2(t2)
    {}

    // Returns evaluated vector expression
    inline const typename std::common_type<typename E1::value_type, T2>::type get(std::size_t index) const {
        return e1.get(index)/t2;
    }

    // Store value type
    using value_type = typename std::common_type<typename E1::value_type, T2>::type;
};

// Binary operator: element-wise division of vector expression by another vector expression
template<typename E1, typename E2>
auto operator/(const E1& e1, const E2& e2)
    -> typename std::enable_if<std::is_base_of<vectorBase,E1>::value &&
                               std::is_base_of<vectorBase,E2>::value,
                               VectorDiv<E1,E2>>::type
{
    return VectorDiv<E1,E2>(e1,e2);
}

// Binary operator: element-wise division of a scalar by a vector expression
template<typename T1, typename E2>
auto operator/(const T1& t1, const E2& e2)
    -> typename std::enable_if<!std::is_base_of<vectorBase,T1>::value &&
                               std::is_base_of<vectorBase,E2>::value,
                               ScalarVectorDiv<T1,E2>>::type
{
    return ScalarVectorDiv<T1,E2>(t1,e2);
}

// Binary operator: element-wise division of a vector expression by a scalar
template<typename E1, typename T2>
auto operator/(const E1& e1, const T2& t2)
    -> typename std::enable_if<std::is_base_of<vectorBase,E1>::value &&
                               !std::is_base_of<vectorBase,T2>::value,
                               VectorScalarDiv<E1,T2>>::type
{
    return VectorScalarDiv<E1,T2>(e1,t2);
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const vector<T>& v) {
    for (std::size_t i = 0; i < v.size(); i++)
        os << v.get(i) << " ";
    os << std::endl;
    return os;
}

} // namespace laetlib

#endif // LAETLIB_H

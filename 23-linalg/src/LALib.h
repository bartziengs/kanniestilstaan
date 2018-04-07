/**
 * \file LALib.h
 *
 * This file is part of the course tw3720tu:
 * Object Oriented Scientific Programming with C++
 *
 * \author Matthias Moller
 *
 */

// Include safeguard
#ifndef LALIB_H
#define LALIB_H

// Include header file for standard input/output stream library
#include <iostream>

// Include algorithms
#include <algorithm>

// Make separate namespace
namespace lalib {

    template<typename T>
    class vector {
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

    private:
        // Attributes
        T *data;
        std::size_t n;
    };

    // Binary operator: addition of two vectors v1[i]+v2[i]
    template<typename T1, typename T2>
    auto operator+(const vector<T1> &v1, const vector<T2> &v2) {
        vector<typename std::common_type<T1, T2>::type> v(v1.size());
        for (std::size_t i = 0; i < v1.size(); i++)
            v.get(i) = v1.get(i) + v2.get(i);

        return v;
    };

    // Binary operator: subtraction of two vectors v1[i]-v2[i]
    template<typename T1, typename T2>
    auto operator-(const vector<T1> &v1, const vector<T2> &v2) {
        vector<typename std::common_type<T1, T2>::type> v(v1.size());
        for (std::size_t i = 0; i < v1.size(); i++)
            v.get(i) = v1.get(i) - v2.get(i);

        return v;
    };

    // Binary operator: element-wise multiplication of two vectors v1[i]*v2[i]
    template<typename T1, typename T2>
    auto operator*(const vector<T1> &v1, const vector<T2> &v2) {
        vector<typename std::common_type<T1, T2>::type> v(v1.size());
        for (std::size_t i = 0; i < v1.size(); i++)
            v.get(i) = v1.get(i) * v2.get(i);

        return v;
    };

    // Binary operator: element-wise division of two vectors v1[i]/v2[i]
    template<typename T1, typename T2>
    auto operator/(const vector<T1> &v1, const vector<T2> &v2) {
        vector<typename std::common_type<T1, T2>::type> v(v1.size());
        for (std::size_t i = 0; i < v1.size(); i++)
            v.get(i) = v1.get(i) / v2.get(i);

        return v;
    };

    // Binary operator: addition of a scalar and a vector s1+v2[i]
    template<typename T1, typename T2>
    auto operator+(const T1 s1, const vector<T2> &v2) {
        vector<typename std::common_type<T1, T2>::type> v(v2.size());
        for (std::size_t i = 0; i < v2.size(); i++)
            v.get(i) = s1 + v2.get(i);

        return v;
    };

    // Binary operator: addition of a vector and a scalar v1[i]+s2
    template<typename T1, typename T2>
    auto operator+(const vector<T1> &v1, const T2 s2) {
        vector<typename std::common_type<T1, T2>::type> v(v1.size());
        for (std::size_t i = 0; i < v1.size(); i++)
            v.get(i) = v1.get(i) + s2;

        return v;
    };

    // Binary operator: subtraction of a vector from a scalar s1-v2[i]
    template<typename T1, typename T2>
    auto operator-(const T1 s1, const vector<T2> &v2) {
        vector<typename std::common_type<T1, T2>::type> v(v2.size());
        for (std::size_t i = 0; i < v2.size(); i++)
            v.get(i) = s1 - v2.get(i);

        return v;
    };

    // Binary operator: subtraction of a scalar from a vector v1[i]-s2
    template<typename T1, typename T2>
    auto operator-(const vector<T1> &v1, const T2 s2) {
        vector<typename std::common_type<T1, T2>::type> v(v1.size());
        for (std::size_t i = 0; i < v1.size(); i++)
            v.get(i) = v1.get(i) - s2;

        return v;
    };

    // Binary operator: element-wise multiplication of a scalar and a vector s1*v2[i]
    template<typename T1, typename T2>
    auto operator*(const T1 s1, const vector<T2> &v2) {
        vector<typename std::common_type<T1, T2>::type> v(v2.size());
        for (std::size_t i = 0; i < v2.size(); i++)
            v.get(i) = s1 * v2.get(i);

        return v;
    };

    // Binary operator: element-wise multiplication of a vector and a scalar v1[i]*s2
    template<typename T1, typename T2>
    auto operator*(const vector<T1> &v1, const T2 s2) {
        vector<typename std::common_type<T1, T2>::type> v(v1.size());
        for (std::size_t i = 0; i < v1.size(); i++)
            v.get(i) = v1.get(i) * s2;

        return v;
    };

    // Binary operator: element-wise division of a scalar by a vector s1/v2[i]
    template<typename T1, typename T2>
    auto operator/(const T1 s1, const vector<T2> &v2) {
        vector<typename std::common_type<T1, T2>::type> v(v2.size());
        for (std::size_t i = 0; i < v2.size(); i++)
            v.get(i) = s1 / v2.get(i);

        return v;
    };

    // Binary operator: element-wise division of a vector by a scalar v1[i]/s2
    template<typename T1, typename T2>
    auto operator/(const vector<T1> &v1, const T2 s2) {
        vector<typename std::common_type<T1, T2>::type> v(v1.size());
        for (std::size_t i = 0; i < v1.size(); i++)
            v.get(i) = v1.get(i) / s2;

        return v;
    };

    // Print vector to screen
    template<typename T>
    std::ostream& operator<<(std::ostream& os, const vector<T>& v) {
        for (std::size_t i = 0; i < v.size(); i++)
            os << v.get(i) << " ";
        os << std::endl;
        return os;
    }

} // namespace lalib

#endif // LALIB_H

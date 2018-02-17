#ifndef BIGINTEGERHEADER
#define BIGINTEGERHEADER
#include <iostream>
#include <math.h>
#include <vector>
#include <string>
#include <iostream>

namespace euler { 
    class BigInteger { 
        std::vector<int> value; 
        bool isNegative;
        BigInteger trim(); //Remove leading zeros
        void addToFront(const int digit) { this->value.insert(this->value.begin(), digit); }
        void addToBack(const int digit) { this->value.insert(this->value.end(), digit); }
        BigInteger pad(int) const; //Pad this with zeros
        BigInteger multiply(const BigInteger& other) const;

    public: 
        //constructors
        BigInteger() { this->isNegative = false; }
        BigInteger(const int num) { this->init(num); }
        BigInteger(const std::string str) { this->init(str); }
        BigInteger(const BigInteger& b) { this->init(b); }
        void init(const int num) { this->init(std::to_string(num)); }
        void init(const std::string);
        void init(const BigInteger&);

        //methods
        std::string toString() const;
        int digits() const { return this->value.size(); }
        BigInteger abs() const { BigInteger t (*this); t.isNegative = false; return t; }
        BigInteger range(const int, const int) const; //Returns a BigInteger with a value equal to this->value[int, int]
        BigInteger pow10(int) const; //Shortcut for b * 10^exp
   
        //operators
        //unary
        BigInteger& operator+() { return *this; }
        BigInteger operator-() const { BigInteger t (*this); t.isNegative = !t.isNegative; return t; }
        BigInteger operator++(int) { BigInteger temp (*this); *this += 1; return temp; } //x++
        BigInteger& operator++() { *this += 1; return *this; } //++x
        BigInteger operator--(int) { BigInteger temp (*this); *this -= 1; return temp; } //x--
        BigInteger& operator--() { *this -= 1; return *this; } //--x
        int& operator[](const int); 
        int operator[](const int) const;

        //arithmetic
        BigInteger operator+(const BigInteger&) const;
        BigInteger operator-(const BigInteger&) const;
        BigInteger operator*(const BigInteger&) const; //Karatsuba implementation
        BigInteger operator/(const BigInteger&) const;
        BigInteger operator%(const BigInteger&) const;

        //arithmetic integer overloads
        BigInteger operator+(const int i) const { BigInteger t (i); return *this + t; }
        BigInteger operator-(const int i) const { BigInteger t (i); return *this - t; }
        BigInteger operator*(const int i) const { BigInteger t (i); return *this * t; }
        BigInteger operator/(const int i) const { BigInteger t (i); return *this / t; }
        BigInteger operator%(const int i) const { BigInteger t (i); return *this % t; }

        //assignment
        BigInteger operator=(const BigInteger& b) { this->init(b); return *this; }
        BigInteger& operator+=(const BigInteger& b) { *this = *this + b; return *this; }
        BigInteger& operator-=(const BigInteger& b) { *this = *this - b; return *this; }
        BigInteger& operator*=(const BigInteger& b) { *this = *this * b; return *this; }
        BigInteger& operator/=(const BigInteger& b) { *this = *this / b; return *this; }
        BigInteger& operator%=(const BigInteger& b) { *this = *this % b; return *this; }

        //assigment integer overloads
        BigInteger operator=(const int i) { this->init(i); return *this; }
        BigInteger& operator+=(const int i) { BigInteger t (i); return *this += t; }
        BigInteger& operator-=(const int i) { BigInteger t (i); return *this -= t; }
        BigInteger& operator*=(const int i) { BigInteger t (i); return *this *= t; }
        BigInteger& operator/=(const int i) { BigInteger t (i); return *this /= t; }
        BigInteger& operator%=(const int i) { BigInteger t (i); return *this %= t; }

        //relational
        bool operator==(const BigInteger&) const;
        bool operator!=(const BigInteger& b) const { return !(*this == b); }
        bool operator>(const BigInteger&) const;
        bool operator<(const BigInteger& b) const { return !(*this > b || *this == b); }
        bool operator>=(const BigInteger& b) const { return !(*this < b); }
        bool operator<=(const BigInteger& b) const { return !(*this > b); }

        //relational integer overloads
        bool operator==(const int i) const { BigInteger t (i); return *this == t; }
        bool operator!=(const int i) const { BigInteger t (i); return *this != t; }
        bool operator>(const int i) const { BigInteger t (i); return *this > t; }
        bool operator<(const int i) const { BigInteger t (i); return *this < t; }
        bool operator>=(const int i) const { BigInteger t (i); return *this >= t; }
        bool operator<=(const int i) const { BigInteger t (i); return *this <= t; }

        //stream
        friend std::ostream& operator<<(std::ostream&, const BigInteger&);
        friend std::istream& operator>>(std::istream&, const BigInteger&);
    };
}

#endif

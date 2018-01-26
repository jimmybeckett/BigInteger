#ifndef BIGINTEGERHEADER
#define BIGINTEGERHEADER
#include <iostream>
#include <math.h>
#include <vector>
#include <string>
#include <iostream>

namespace euler { 
    class BigInteger { 
        std::vector<short int> value; 
        bool isNegative;
    public: 
        //constructors
        BigInteger();
        BigInteger(int);
        BigInteger(long);
        BigInteger(std::string);
        BigInteger(BigInteger&);

        //methods
        std::string toString() const;
        int digits() const;
   
        //operators
        //unary
        BigInteger operator+();
        BigInteger operator-();
        BigInteger operator++();
        BigInteger operator--();
        BigInteger operator[](int) const;

        //arithmetic
        BigInteger operator+(const BigInteger&) const;
        BigInteger operator-(const BigInteger&) const;
        BigInteger operator*(const BigInteger&) const;
        BigInteger operator/(const BigInteger&) const;
        BigInteger operator%(const BigInteger&) const;

        //assignment
        BigInteger operator=(const BigInteger&);
        BigInteger operator+=(const BigInteger&);
        BigInteger operator-=(const BigInteger&);
        BigInteger operator*=(const BigInteger&);
        BigInteger operator/=(const BigInteger&);
        BigInteger operator%=(const BigInteger&);

        //relational
        bool operator==(const BigInteger&) const;
        bool operator!=(const BigInteger&) const;
        bool operator>=(const BigInteger&) const;
        bool operator<=(const BigInteger&) const;
        bool operator>(const BigInteger&) const;
        bool operator<(const BigInteger&) const;

        //stream
        friend std::ostream& operator<<(std::ostream&, const BigInteger&);
        friend std::istream& operator>>(std::istream&, const BigInteger&);
    };
}

#endif

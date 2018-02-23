#ifndef BIGINTEGERHEADER
#define BIGINTEGERHEADER
#include <iostream>
#include <vector>
#include <string>

namespace euler { 
    class BigInteger { 
        std::vector<int> value; 
        bool isNegative;

        BigInteger trim(); //Remove leading zeros
        inline void addToFront(const int digit) { this->value.insert(this->value.begin(), digit); }
        inline void addToBack(const int digit) { this->value.insert(this->value.end(), digit); }
        BigInteger pad(int) const; //Pad this with zeros
        BigInteger multiply(const BigInteger&) const;
        BigInteger divideAndRemainder(const BigInteger&, BigInteger&) const;
        inline void init(const int num) { this->init(std::to_string(num)); }
        void init(const std::string);
        void init(const BigInteger&);

    public: 
        //constructors
        BigInteger() { this->isNegative = false; }
        BigInteger(const int num) { this->init(num); }
        BigInteger(const std::string str) { this->init(str); }
        BigInteger(const BigInteger& b) { this->init(b); }
        
        //methods
        std::string toString() const;
        int toInt() const;
        int digits() const { return this->value.size(); }
        inline BigInteger abs() const { BigInteger t (*this); t.isNegative = false; return t; }
        BigInteger range(const int, const int) const; //Returns a BigInteger with a value equal to this->value[int, int]
        BigInteger pow(const int) const;
        inline BigInteger max(const BigInteger& b1, const BigInteger& b2) const { return b1 > b2 ? b1 : b2; }
        inline BigInteger min(const BigInteger& b1, const BigInteger& b2) const { return b1 < b2 ? b1 : b2; }
   
        //operators
        //unary
        inline BigInteger& operator+() { return *this; }
        inline BigInteger operator-() const { BigInteger t (*this); t.isNegative = !t.isNegative; return t; }
        inline BigInteger operator++(int) { BigInteger temp (*this); *this += 1; return temp; } //x++
        inline BigInteger& operator++() { *this += 1; return *this; } //++x
        inline BigInteger operator--(int) { BigInteger temp (*this); *this -= 1; return temp; } //x--
        inline BigInteger& operator--() { *this -= 1; return *this; } //--x
        int& operator[](const int); 
        //IMPORTANT
        /* (BigInteger (12345)[0]) == 1, not 5.
         * This decision was made in order to make the subscript operator more intuitive, it's 
         * current behavior mirrors the behavior of the subscript operator with strings.
         * An argument can be made for the behavior (BigInteger (12345)[0]) == 5, so that the
         * subscript matches the power of the base. 
         * However, but this behavior can be reproduced by using the digits() function.
         * BigInteger t (12345); t[t.digits() - 1 - 0] == 5;
         */
        int operator[](const int) const;

        //arithmetic
        BigInteger operator+(const BigInteger&) const;
        BigInteger operator-(const BigInteger&) const;
        BigInteger operator*(const BigInteger&) const; //Karatsuba implementation
        BigInteger operator/(const BigInteger&) const; //Algorithm D implementation
        BigInteger operator%(const BigInteger&) const;

        //assignment
        inline BigInteger operator=(const BigInteger& b) { this->init(b); return *this; }
        inline BigInteger& operator+=(const BigInteger& b) { *this = *this + b; return *this; }
        inline BigInteger& operator-=(const BigInteger& b) { *this = *this - b; return *this; }
        inline BigInteger& operator*=(const BigInteger& b) { *this = *this * b; return *this; }
        inline BigInteger& operator/=(const BigInteger& b) { *this = *this / b; return *this; }
        inline BigInteger& operator%=(const BigInteger& b) { *this = *this % b; return *this; }

        //relational
        bool operator==(const BigInteger&) const;
        inline bool operator!=(const BigInteger& b) const { return !(*this == b); }
        bool operator>(const BigInteger&) const;
        inline bool operator<(const BigInteger& b) const { return !(*this > b || *this == b); }
        inline bool operator>=(const BigInteger& b) const { return !(*this < b); }
        inline bool operator<=(const BigInteger& b) const { return !(*this > b); }

        //stream
        friend std::ostream& operator<<(std::ostream&, const BigInteger&);
        friend std::istream& operator>>(std::istream&, const BigInteger&);
    };
}

#endif

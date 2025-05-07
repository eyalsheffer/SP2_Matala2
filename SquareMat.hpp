#ifndef SQUARE_MAT_HPP
#define SQUARE_MAT_HPP

#include <iostream>

namespace MyMath {

    class SquareMat {
        private:
            int n;
            double** data;

        public:
            SquareMat(int size);
            SquareMat(const SquareMat& other);
            ~SquareMat();

            SquareMat& operator=(const SquareMat& other);

            double* operator[](int index);
            const double* operator[](int index) const;

            SquareMat operator+(const SquareMat& other) const;
            SquareMat operator-(const SquareMat& other) const;
            SquareMat operator-() const;
            SquareMat operator*(const SquareMat& other) const;
            SquareMat operator*(double scalar) const;
            friend SquareMat operator*(double scalar, const SquareMat& mat);
            SquareMat operator%(const SquareMat& other) const;
            SquareMat operator%(int scalar) const;
            SquareMat operator/(double scalar) const;
            SquareMat operator^(unsigned int power) const;

            SquareMat& operator++();
            SquareMat operator++(int);
            SquareMat& operator--();
            SquareMat operator--(int);
            SquareMat operator~() const;

            SquareMat& operator+=(const SquareMat& other);
            SquareMat& operator-=(const SquareMat& other);
            SquareMat& operator*=(const SquareMat& other);
            SquareMat& operator*=(double scalar);
            SquareMat& operator%=(const SquareMat& other);
            SquareMat& operator%=(int scalar);
            SquareMat& operator/=(double scalar);

            double sum() const;

            bool operator==(const SquareMat& other) const;
            bool operator!=(const SquareMat& other) const;
            bool operator<(const SquareMat& other) const;
            bool operator<=(const SquareMat& other) const;
            bool operator>(const SquareMat& other) const;
            bool operator>=(const SquareMat& other) const;

            double operator!() const;

            friend std::ostream& operator<<(std::ostream& os, const SquareMat& mat);
        };

}

#endif

#include "SquareMat.hpp"
#include <cmath> 

namespace MyMath {

    SquareMat::SquareMat(int size) : n(size) {
        data = new double*[n];
        for (int i = 0; i < n; ++i) {
            data[i] = new double[n];
            for (int j = 0; j < n; ++j) {
                data[i][j] = 0.0;
            }
        }
    }

    SquareMat::SquareMat(const SquareMat& other) : n(other.n) {
        data = new double*[n];
        for (int i = 0; i < n; ++i) {
            data[i] = new double[n];
            for (int j = 0; j < n; ++j) {
                data[i][j] = other.data[i][j];
            }
        }
    }

    SquareMat::~SquareMat() {
        for (int i = 0; i < n; ++i) {
            delete[] data[i];
        }
        delete[] data;
    }

    SquareMat& SquareMat::operator=(const SquareMat& other) {
        if (this != &other) {
            for (int i = 0; i < n; ++i) {
                delete[] data[i];
            }
            delete[] data;
            n = other.n;
            data = new double*[n];
            for (int i = 0; i < n; ++i) {
                data[i] = new double[n];
                for (int j = 0; j < n; ++j) {
                    data[i][j] = other.data[i][j];
                }
            }
        }
        return *this;
    }

    double* SquareMat::operator[](int index) {
        return data[index];
    }

    const double* SquareMat::operator[](int index) const {
        return data[index];
    }

    SquareMat SquareMat::operator+(const SquareMat& other) const {
        SquareMat result(n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }

    SquareMat SquareMat::operator-(const SquareMat& other) const {
        SquareMat result(n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                result.data[i][j] = data[i][j] - other.data[i][j];
            }
        }
        return result;
    }

    SquareMat SquareMat::operator-() const {
        SquareMat result(n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                result.data[i][j] = -data[i][j];
            }
        }
        return result;
    }

    SquareMat SquareMat::operator*(const SquareMat& other) const {
        SquareMat result(n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                result.data[i][j] = 0.0;
                for (int k = 0; k < n; ++k) {
                    result.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }
        return result;
    }

    SquareMat SquareMat::operator*(double scalar) const {
        SquareMat result(n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                result.data[i][j] = data[i][j] * scalar;
            }
        }
        return result;
    }
    SquareMat operator*(double scalar, const SquareMat& mat) {
        return mat * scalar;
    }

    SquareMat SquareMat::operator%(const SquareMat& other) const {
        SquareMat result(n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                result.data[i][j] = fmod(data[i][j], other.data[i][j]);
            }
        }
        return result;
    }
    
    SquareMat SquareMat::operator%(int scalar) const {
        SquareMat result(n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                result.data[i][j] = fmod(data[i][j], scalar);
            }
        }
        return result;
    }

    SquareMat SquareMat::operator/(double scalar) const {
        SquareMat result(n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                result.data[i][j] = data[i][j] / scalar;
            }
        }
        return result;
    }

    SquareMat SquareMat::operator^(unsigned int power) const {
        SquareMat result(n); 
        for (int i = 0; i < n; i++)
        {
            for (int j = 0;j < n; j ++)
            {
                if(i==j) 
                    result.data[i][j] = 1.0;
                else
                result.data[i][j] = 0.0;
            }
            
        }
        SquareMat base = *this;

        while (power > 0) {
            if (power % 2 == 1) {
                result = result * base;
            }
            base = base * base;
            power /= 2;
        }

        return result;

    }

    SquareMat& SquareMat::operator++() {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                data[i][j] += 1;
            }
        }
        return *this;
    }

    SquareMat SquareMat::operator++(int) {
        SquareMat temp = *this;
        ++(*this);
        return temp;
    }

    SquareMat& SquareMat::operator--() {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                data[i][j] -= 1;
            }
        }
        return *this;
    }

    SquareMat SquareMat::operator--(int) {
        SquareMat temp = *this;
        --(*this);
        return temp;
    }

    SquareMat SquareMat::operator~() const {
        SquareMat result(n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                result.data[i][j] = data[j][i];
            }
        }
        return result;
    }

    SquareMat& SquareMat::operator+=(const SquareMat& other) {
        *this = *this + other;
        return *this;
    }

    SquareMat& SquareMat::operator-=(const SquareMat& other) {
        *this = *this - other;
        return *this;
    }

    SquareMat& SquareMat::operator*=(const SquareMat& other) {
        *this = *this * other;
        return *this;
    }

    SquareMat& SquareMat::operator*=(double scalar) {
        *this = *this * scalar;
        return *this;
    }

    SquareMat& SquareMat::operator%=(const SquareMat& other) {
        *this = *this % other;
        return *this;
    }

    SquareMat& SquareMat::operator%=(int scalar) {
        *this = *this % scalar;
        return *this;
    }

    SquareMat& SquareMat::operator/=(double scalar) {
        *this = *this / scalar;
        return *this;
    }
    double SquareMat::sum() const{
        double sum = 0.0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                sum += data[i][j];
            }
        }
        return sum;
    }

    bool SquareMat::operator==(const SquareMat& other) const {
        return(sum() == other.sum());
    }

    bool SquareMat::operator!=(const SquareMat& other) const {
        return !(*this == other);
    }

    bool SquareMat::operator<(const SquareMat& other) const {
        return(sum() < other.sum());
    }

    bool SquareMat::operator<=(const SquareMat& other) const {
        return *this < other || *this == other;
    }

    bool SquareMat::operator>(const SquareMat& other) const {
        return !(*this <= other);
    }

    bool SquareMat::operator>=(const SquareMat& other) const {
        return !(*this < other);
    }

    double SquareMat::operator!() const {
        if (n == 1) 
            return data[0][0];
        double det = 0;
        for (int i = 0; i < n; ++i) {
            SquareMat tempMat(n - 1);
            for (int k = 1; k < n; ++k) {
                int col = 0;
                for (int j = 0; j < n; ++j) {
                    if (j == i) continue;
                        tempMat.data[k - 1][col++] = data[k][j];
                }
            }
            det += (i % 2 == 0 ? 1 : -1) * data[0][i] * !tempMat;
        }
        return det;
       
    }

    std::ostream& operator<<(std::ostream& os, const SquareMat& mat) {
        for (int i = 0; i < mat.n; ++i) {
            for (int j = 0; j < mat.n; ++j) {
                os << mat.data[i][j] << " ";
            }
            os << "\n";
        }
        return os;
    }

}

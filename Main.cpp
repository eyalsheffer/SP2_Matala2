#include <iostream>
#include "SquareMat.hpp"
using namespace MyMath;

int main() {
    std::cout << "tset"<< std::endl;
    SquareMat mat1(3);
    
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            mat1[i][j] = i * 3 + j + 1;
        }
    }

    std::cout << "Matrix 1:\n" << mat1 << std::endl;

    MyMath::SquareMat mat2(3);

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            mat2[i][j] = (i + 1) * (j + 1);
        }
    }

    std::cout << "Matrix 2:\n" << mat2 << std::endl;

    MyMath::SquareMat result = mat1 + mat2;
    std::cout << "Matrix 1 + Matrix 2:\n" << result << std::endl;

    result = mat1 - mat2;
    std::cout << "Matrix 1 - Matrix 2:\n" << result << std::endl;

    result = mat1 * mat2;
    std::cout << "Matrix 1 * Matrix 2:\n" << result << std::endl;

    double scalar = 2.0;
    result = mat1 * scalar;
    std::cout << "Matrix 1 * " << scalar << ":\n" << result << std::endl;

    if (mat1 == mat2) {
        std::cout << "Matrix 1 and Matrix 2 are equal." << std::endl;
    } else {
        std::cout << "Matrix 1 and Matrix 2 are not equal." << std::endl;
    }

    return 0;
}

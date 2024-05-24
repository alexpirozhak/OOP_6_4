#include <iostream>
#include "Matrix.h"

int main() {
    int rows1, cols1;
    cout << "Enter the number of rows and columns for the first matrix: ";
    cin >> rows1 >> cols1;

    Matrix<int> mat1(rows1, cols1);
    mat1.input();

    int rows2, cols2;
    cout << "Enter the number of rows and columns for the second matrix: ";
    cin >> rows2 >> cols2;

    Matrix<int> mat2(rows2, cols2);
    mat2.input();

    try {
        // Додавання матриць
        Matrix<int> sum = mat1 + mat2;
        cout << "Sum of matrices:" << endl;
        cout << sum;
    } catch (const invalid_argument& e) {
        cout << "Error: " << e.what() << endl;
    }

    int rows3, cols3;
    cout << "Enter the number of rows and columns for the third matrix: ";
    cin >> rows3 >> cols3;

    Matrix<int> mat3(rows3, cols3);
    mat3.input();

    try {
        // Множення матриць
        Matrix<int> product = mat1 * mat3;
        cout << "Product of matrices:" << endl;
        cout << product;
    } catch (const invalid_argument& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}

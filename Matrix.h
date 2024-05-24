#pragma once

#include <iostream>
#include <vector>

using namespace std;

template<typename T>
class Matrix {
private:
    vector<vector<T>> data;
    int rows;
    int cols;

public:
    // Конструктор
    Matrix(int r, int c);

    // Оператор доступу до елементів
    T& operator()(int r, int c);

    // Оператор доступу до елементів для константних об'єктів
    const T& operator()(int r, int c) const;

    // Додавання матриць
    Matrix<T> operator+(const Matrix<T>& other) const;

    // Множення матриць
    Matrix<T> operator*(const Matrix<T>& other) const;

    // Введення матриці з клавіатури
    void input();

    // Вивід матриці
    template<typename U>
    friend ostream& operator<<(ostream& os, const Matrix<U>& matrix);
};

// Реалізація шаблонного класу повинна бути у заголовочному файлі
template<typename T>
Matrix<T>::Matrix(int r, int c) : rows(r), cols(c) {
    data.resize(rows, vector<T>(cols, 0));
}

template<typename T>
T& Matrix<T>::operator()(int r, int c) {
    return data[r][c];
}

template<typename T>
const T& Matrix<T>::operator()(int r, int c) const {
    return data[r][c];
}

template<typename T>
Matrix<T> Matrix<T>::operator+(const Matrix<T>& other) const {
    if (rows != other.rows || cols != other.cols) {
        throw invalid_argument("Matrices dimensions do not match for addition");
    }

    Matrix<T> result(rows, cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result(i, j) = data[i][j] + other(i, j);
        }
    }
    return result;
}

template<typename T>
Matrix<T> Matrix<T>::operator*(const Matrix<T>& other) const {
    if (cols != other.rows) {
        throw invalid_argument("Matrices dimensions do not match for multiplication");
    }

    Matrix<T> result(rows, other.cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < other.cols; ++j) {
            for (int k = 0; k < cols; ++k) {
                result(i, j) += data[i][k] * other(k, j);
            }
        }
    }
    return result;
}

template<typename T>
void Matrix<T>::input() {
    cout << "Enter the elements of the matrix (" << rows << "x" << cols << "):" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cin >> data[i][j];
        }
    }
}

template<typename T>
ostream& operator<<(ostream& os, const Matrix<T>& matrix) {
    for (int i = 0; i < matrix.rows; ++i) {
        for (int j = 0; j < matrix.cols; ++j) {
            os << matrix(i, j) << " ";
        }
        os << endl;
    }
    return os;
}

#include <gtest/gtest.h>
#include "../Matrix.h"

// Тест для функції додавання матриць
TEST(MatrixTest, AddMatrices) {
Matrix<int> mat1(2, 3);
Matrix<int> mat2(2, 3);

// Заповнення першої матриці
mat1(0, 0) = 1; mat1(0, 1) = 2; mat1(0, 2) = 3;
mat1(1, 0) = 4; mat1(1, 1) = 5; mat1(1, 2) = 6;

// Заповнення другої матриці
mat2(0, 0) = 7; mat2(0, 1) = 8; mat2(0, 2) = 9;
mat2(1, 0) = 10; mat2(1, 1) = 11; mat2(1, 2) = 12;

// Очікуваний результат
Matrix<int> expected(2, 3);
expected(0, 0) = 8; expected(0, 1) = 10; expected(0, 2) = 12;
expected(1, 0) = 14; expected(1, 1) = 16; expected(1, 2) = 18;

// Перевірка додавання матриць
Matrix<int> result = mat1 + mat2;
EXPECT_EQ(result(0, 0), expected(0, 0));
EXPECT_EQ(result(0, 1), expected(0, 1));
EXPECT_EQ(result(0, 2), expected(0, 2));
EXPECT_EQ(result(1, 0), expected(1, 0));
EXPECT_EQ(result(1, 1), expected(1, 1));
EXPECT_EQ(result(1, 2), expected(1, 2));
}
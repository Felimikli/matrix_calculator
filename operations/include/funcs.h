#pragma once

#include "utils.h"

Matrix* add_matrices(Matrix* matrix1, Matrix* matrix2);
Matrix* substract_matrices(Matrix* matrix1, Matrix* matrix2);
double get_determinant(Matrix* matrix);
Matrix* gauss_elimination(Matrix* matrix);
Gauss_elimination_result gauss_elimination_row_exchanges(Matrix* matrix);
Matrix* inverse(Matrix* matrix);
Matrix* matrix_power(Matrix* matrix, int exponent);
Matrix* multiply_matrices(Matrix* matrix1, Matrix* matrix2);
int get_rank(Matrix* matrix);
Matrix* transpose(Matrix* matrix);

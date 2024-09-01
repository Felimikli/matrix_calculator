#pragma once

#include "common_structs.h"

int get_matrix_rows(int mult_cols);
int get_matrix_cols();
void fill_matrix(Matrix* matrix);
Matrix* create_matrix(int rows, int cols);
Matrix* replace_matrix(Matrix* destination, Matrix* source);
Matrix* copy_matrix(Matrix* matrix);
void print_matrix(Matrix* matrix);
void free_matrix(Matrix* matrix);
void exchange_matrix_rows(Matrix* matrix, int row1, int row2);

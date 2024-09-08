#pragma once

#include "common_structs.h"

void exchange_matrix_rows(Matrix* matrix, int row1, int row2);
Matrix* create_matrix(int rows, int cols);
Matrix* copy_matrix(Matrix* matrix);
void free_matrix(Matrix* matrix);

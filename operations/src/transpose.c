#include "transpose.h"
#include "utils.h"

Matrix* transpose(Matrix* matrix) {
	Matrix* transposed_matrix = create_matrix(matrix->cols, matrix->rows);
	for(int i = 0; i < matrix->rows; i++) {
		for(int j = 0; j < matrix->cols; j++) {
			transposed_matrix->data[j][i] = matrix->data[i][j];
		}
	}
	return transposed_matrix;
}

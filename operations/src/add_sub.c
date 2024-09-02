#include "add_sub.h"

Matrix* add_matrices(Matrix* matrix1, Matrix* matrix2) {

	Matrix* result_matrix = create_matrix(matrix1->rows, matrix1->rows);

	for(int i = 0; i < result_matrix->rows; i++) {
		for(int j = 0; j < result_matrix->cols; j++) {
				result_matrix->data[i][j] = matrix1->data[i][j] + matrix2->data[i][j];
			}
		}
	return result_matrix;
}

Matrix* substract_matrices(Matrix* matrix1, Matrix* matrix2) {

	Matrix* result_matrix = create_matrix(matrix1->rows, matrix1->rows);

	for(int i = 0; i < result_matrix->rows; i++) {
		for(int j = 0; j < result_matrix->cols; j++) {
				result_matrix->data[i][j] = matrix1->data[i][j] - matrix2->data[i][j];
			}
		}
	return result_matrix;
}

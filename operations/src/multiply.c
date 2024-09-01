#include "multiply.h"
#include "utils.h"

Matrix* multiply(Matrix* matrix1, Matrix* matrix2) {

	int middle_cols_rows = matrix1->cols; // = matrix2->rows

	int result_matrix_rows = matrix1->rows;
	int result_matrix_cols = matrix2->cols;
	Matrix* result_matrix = create_matrix(result_matrix_rows, result_matrix_cols);

	for(int m = 0; m < result_matrix_rows; m++) {
		for(int p = 0; p < result_matrix_cols; p++) {
			for(int n = 0; n < middle_cols_rows; n++) {
				result_matrix->data[m][p] += matrix1->data[m][n] * matrix2->data[n][p];
			}
		}
	}
	return result_matrix;
}

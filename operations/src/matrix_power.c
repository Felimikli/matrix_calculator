#include "matrix_power.h"
#include "multiply_matrices.h"
#include "utils.h"

Matrix* matrix_power(Matrix* matrix, int exponent) {

	int size = matrix->rows;

	Matrix* result_matrix;

	switch (exponent) {
		case 0:
			result_matrix = create_matrix(size, size);
			for(int i = 0; i < size; i++) {
				result_matrix->data[i][i] = 1;
			}
			break;
		case 1:
			result_matrix = copy_matrix(matrix);
			break;
		default:
			result_matrix = copy_matrix(matrix);
			for (int i = 1; i < exponent; i++) {
				Matrix* temp_matrix = multiply_matrices(result_matrix, matrix);
				result_matrix = replace_matrix(result_matrix, temp_matrix);

			}
			break;
	}
	return result_matrix;
}

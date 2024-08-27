#include "exponentiate.h"
#include "multiply.h"
#include "utils.h"

double** exponentiate(double** matrix, int size, int exponent) {

	double** result_matrix = allocate_matrix(size, size);
	switch (exponent) {
		case 0:
			for(int i = 0; i < size; i++) {
				result_matrix[i][i] = 1;
			}
		case 1:
			copy_matrix(result_matrix, matrix, size, size);
		default:
			copy_matrix(result_matrix, matrix, size, size);
			for (int i = 1; i < exponent; i++) {

				double** temp_matrix = multiply(result_matrix, matrix, size, size, size);

				copy_matrix(result_matrix, temp_matrix, size, size);

				free_matrix(temp_matrix, size);

			}
	}
	return result_matrix;
}

#include "../../include/operations/exponentiate.h"
#include "../../include/operations/multiply.h"
#include "../../include/utils.h"

double** exponentiate(double** matrix, int size, int exponent) {

	double** result_matrix = allocate_matrix(size, size);
	for(int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			result_matrix[i][j] = matrix[i][j];
		}
	}
	for (int i = 1; i < exponent; i++) {
		result_matrix = multiply(matrix, result_matrix, size, size, size);
	}
	return result_matrix;
}

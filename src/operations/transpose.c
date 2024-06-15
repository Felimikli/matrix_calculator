#include "../../include/operations/transpose.h"
#include "../../include/utils.h"

double** transpose(double** matrix, int* matrix_size) {
	double** transposed_matrix = allocate_matrix(matrix_size[1], matrix_size[0]);
	for(int j = 0; j < matrix_size[1]; j++) {
		for(int k = 0; k < matrix_size[0]; k++) {
			transposed_matrix[j][k] = matrix[k][j];
		}
	}
	return transposed_matrix;
}

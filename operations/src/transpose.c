#include "transpose.h"
#include "utils.h"

double** transpose(double** matrix, int rows, int cols) {
	double** transposed_matrix = allocate_matrix(cols, rows);
	for(int j = 0; j < cols; j++) {
		for(int k = 0; k < rows; k++) {
			transposed_matrix[j][k] = matrix[k][j];
		}
	}
	return transposed_matrix;
}

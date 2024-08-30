#include <math.h>
#include "../include/utils.h"

double** gauss(double** matrix, int rows, int cols) {
	
	double x;
	double** result_matrix = allocate_matrix(rows, cols);
	copy_matrix(result_matrix, matrix, rows, cols);

	for(int j = 0; j < cols; j++) {
		int max_pivot = j;
		for(int k = j; k < rows; k++) {
			if(fabs(result_matrix[k][j]) > fabs(result_matrix[max_pivot][j])) {
				max_pivot = k;
			}
		}
		if(max_pivot != j) {
			exchange_matrix_rows(result_matrix, cols, j, max_pivot);
		}
		for(int i = j; i < rows-1; i++) {
			if(result_matrix[i+1][j] != 0) {
				x = result_matrix[i+1][j] / result_matrix[j][j];
				for(int p = j; p < cols; p++) {
					result_matrix[i+1][p] -= result_matrix[j][p] * x;
				}
			}
		}
	}
	return result_matrix;
}

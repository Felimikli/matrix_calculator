#include "gauss_elimination.h"
#include <math.h>

Matrix* gauss_elimination(Matrix* matrix) {
	
	double x;
	Matrix* result_matrix = copy_matrix(matrix);

	for(int j = 0; j < result_matrix->cols; j++) {
		int max_pivot = j;
		for(int k = j; k < result_matrix->rows; k++) {
			if(fabs(result_matrix->data[k][j]) > fabs(result_matrix->data[max_pivot][j])) {
				max_pivot = k;
			}
		}
		if(max_pivot != j) {
			exchange_matrix_rows(result_matrix, j, max_pivot);
		}
		for(int i = j; i < result_matrix->rows-1; i++) {
			if(result_matrix->data[i+1][j] != 0) {
				x = (-1) * (result_matrix->data[i+1][j] / result_matrix->data[j][j]);
				for(int p = j; p < result_matrix->cols; p++) {
					result_matrix->data[i+1][p] += (result_matrix->data[j][p] * x);
				}
			}
		}
	}
	return result_matrix;
}


Gauss_elimination_result gauss_elimination_row_exchanges(Matrix* matrix) {
	
	double x;
	int row_exchanges = 0;
	Matrix* result_matrix = copy_matrix(matrix);

	for(int j = 0; j < result_matrix->cols; j++) {
		int max_pivot = j;
		for(int k = j; k < result_matrix->rows; k++) {
			if(fabs(result_matrix->data[k][j]) > fabs(result_matrix->data[max_pivot][j])) {
				max_pivot = k;
			}
		}
		if(max_pivot != j) {
			exchange_matrix_rows(result_matrix, j, max_pivot);
			row_exchanges++;
		}
		for(int i = j; i < result_matrix->rows-1; i++) {
			if(result_matrix->data[i+1][j] != 0) {
				x = (-1) * (result_matrix->data[i+1][j] / result_matrix->data[j][j]);
				for(int p = j; p < result_matrix->cols; p++) {
					result_matrix->data[i+1][p] += (result_matrix->data[j][p] * x);
				}
			}
		}
	}
	Gauss_elimination_result result = {result_matrix, row_exchanges};
	return result;
}

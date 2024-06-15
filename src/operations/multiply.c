#include "../../include/operations/multiply.h"
#include "../../include/utils.h"

double** multiply(double** first_matrix, double** second_matrix, int result_matrix_rows, int middle_cols_rows, int result_matrix_cols) {

	double** result_matrix = allocate_matrix(result_matrix_rows, result_matrix_cols);

	for(int m = 0; m < result_matrix_rows; m++) {
		for(int p = 0; p < result_matrix_cols; p++) {
			for(int n = 0; n < middle_cols_rows; n++) {
				result_matrix[m][p] += first_matrix[m][n] * second_matrix[n][p];
			}
		}
	}
	return result_matrix;
}

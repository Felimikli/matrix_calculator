#include "operations.h"
#include "operations_utils.h"
#include <math.h>
#include <stddef.h>

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


Matrix* multiply_matrices(Matrix* matrix1, Matrix* matrix2) {

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


Matrix* transpose(Matrix* matrix) {
	Matrix* transposed_matrix = create_matrix(matrix->cols, matrix->rows);
	for(int i = 0; i < matrix->rows; i++) {
		for(int j = 0; j < matrix->cols; j++) {
			transposed_matrix->data[j][i] = matrix->data[i][j];
		}
	}
	return transposed_matrix;
}


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


Matrix* inverse(Matrix* matrix) {
	int sign;
	int size = matrix->rows;
	Matrix* result_matrix = copy_matrix(matrix);

	double inv_det = 1/(get_determinant(result_matrix));
	switch (size) {
		case 1:
			result_matrix->data[0][0] = 1/result_matrix->data[0][0];
			break;
		case 2:
			result_matrix->data[0][0] = (inv_det) * matrix->data[1][1];
			result_matrix->data[0][1] = (inv_det) * (-1) * matrix->data[0][1];
			result_matrix->data[1][0] = (inv_det) * (-1) * matrix->data[1][0];
			result_matrix->data[1][1] = (inv_det) * matrix->data[0][0];
			break;
		default:
			for (int i = 0; i < size; i++) {
				for (int j = 0; j < size; j++) {
					int minor_size = size-1;
					Matrix* minor = create_matrix(minor_size, minor_size);
					int minor_row = 0;
					for (int k = 0; k < size; k++) {
						int minor_col = 0;
						if(i != k) {
							for (int l = 0; l < size; l++) {
								if(j != l) {
									minor->data[minor_row][minor_col] = matrix->data[l][k];
									minor_col++;
								}
							}
						minor_row++;
						}
					}
					sign = ((i+j) % 2 == 0) ? 1 : -1;
					result_matrix->data[i][j] = inv_det * sign * get_determinant(minor);
					if(minor != NULL) {
						free_matrix(minor);
					}
				}
			}
			break;
	}
	return result_matrix;
}


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
				if(result_matrix != NULL) {
					free_matrix(result_matrix);
				}
				result_matrix = temp_matrix;

			}
			break;
	}
	return result_matrix;
}

double get_determinant(Matrix* matrix){

	
	double det = 1.0;

	Gauss_elimination_result gauss_result = gauss_elimination_row_exchanges(matrix);
	Matrix* det_matrix = gauss_result.matrix;
	int row_exchanges = gauss_result.row_exchanges;

	for(int i = 0; i < det_matrix->cols && i < det_matrix->rows; i++) {
		det *= det_matrix->data[i][i];
	}
	if(det_matrix != NULL) {
		free_matrix(det_matrix);
	}

	if(row_exchanges%2 == 0) {
		return det;
	}
	return -det;
}


int get_rank(Matrix* matrix) {
	int rank = 0;
	Matrix* rank_matrix = gauss_elimination(matrix);
	for(int i = 0; i < matrix->cols && i < matrix->rows; i++) {
		if(rank_matrix->data[i][i] != 0) {
			rank++;
		}
	}
	if(rank_matrix != NULL) {
		free_matrix(rank_matrix);
	}
	return rank;
}

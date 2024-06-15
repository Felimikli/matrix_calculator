#include "../../include/utils.h"
#include "../../include/operations/inverse.h"
#include "../../include/operations/determinant.h"
#include "../../include/operations/transpose.h"


double** get_inverse(double** matrix, int matrix_size, double determinant) {
	int sign;
	double** result_matrix = allocate_matrix(matrix_size, matrix_size);
	double inv_det = 1/determinant;
	switch (matrix_size) {
		case 1:
			result_matrix[0][0] = 1/matrix[0][0];
			break;
		case 2:
			result_matrix[0][0] = (inv_det) * matrix[1][1];
			result_matrix[0][1] = (inv_det) * (-1) * matrix[0][1];
			result_matrix[1][0] = (inv_det) * (-1) * matrix[1][0];
			result_matrix[1][1] = (inv_det) * matrix[0][0];
			break;
		default:
			for (int i = 0; i < matrix_size; i++) {
				for (int j = 0; j < matrix_size; j++) {
					int minor_size = matrix_size-1;
					double** minor = allocate_matrix(minor_size, minor_size);
					int minor_row = 0;
					for (int k = 0; k < matrix_size; k++) {
						int minor_col = 0;
						if(i != k) {
							for (int l = 0; l < matrix_size; l++) {
								if(j != l) {
									minor[minor_row][minor_col] = matrix[l][k];
									minor_col++;
								}
							}
						minor_row++;
						}
					}
					sign = ((i+j) % 2 == 0) ? 1 : -1;
					result_matrix[i][j] = inv_det * sign * get_determinant(minor_size, minor);
					free_matrix(minor, minor_size);
				}
			}
			break;
	}
	return result_matrix;
}

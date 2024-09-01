#include "inverse.h"
#include "determinant.h"

Matrix* get_inverse(Matrix* matrix) {
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
					free_matrix(minor);
				}
			}
			break;
	}
	return result_matrix;
}

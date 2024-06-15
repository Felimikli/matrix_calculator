#include "../../include/operations/add_sub.h"
#include "../../include/utils.h"

double** add(double** first_matrix, double** second_matrix, int* matrix_size) {

	double** result_matrix = allocate_matrix(matrix_size[0], matrix_size[1]);

	for(int m = 0; m < matrix_size[0]; m++) {
		for(int p = 0; p < matrix_size[1]; p++) {
				result_matrix[m][p] = first_matrix[m][p] + second_matrix[m][p];
			}
		}
	return result_matrix;
}

double** substract(double** first_matrix, double** second_matrix, int* matrix_size) {

	double** result_matrix = allocate_matrix(matrix_size[0], matrix_size[1]);

	for(int m = 0; m < matrix_size[0]; m++) {
		for(int p = 0; p < matrix_size[1]; p++) {
				result_matrix[m][p] = first_matrix[m][p] - second_matrix[m][p];
			}
		}
	return result_matrix;
}

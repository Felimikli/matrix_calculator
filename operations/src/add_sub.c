#include "add_sub.h"
#include "utils.h"

double** add(double** first_matrix, double** second_matrix, int rows, int cols) {

	double** result_matrix = allocate_matrix(rows, cols);

	for(int m = 0; m < rows; m++) {
		for(int p = 0; p < cols; p++) {
				result_matrix[m][p] = first_matrix[m][p] + second_matrix[m][p];
			}
		}
	return result_matrix;
}

double** substract(double** first_matrix, double** second_matrix, int rows, int cols) {

	double** result_matrix = allocate_matrix(rows, cols);

	for(int m = 0; m < rows; m++) {
		for(int p = 0; p < cols; p++) {
				result_matrix[m][p] = first_matrix[m][p] - second_matrix[m][p];
			}
		}
	return result_matrix;
}

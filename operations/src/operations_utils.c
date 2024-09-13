#include <stdlib.h>
#include "operations_utils.h"
#include <stddef.h>

void exchange_matrix_rows(Matrix* matrix, int row1, int row2) {
	double temp;
	for(int j = 0; j < matrix->cols; j++) {
		temp = matrix->data[row1][j];
		matrix->data[row1][j] = matrix->data[row2][j];
		matrix->data[row2][j] = temp;
	}
}

Matrix* create_matrix(int rows, int cols) {

	Matrix* matrix = calloc(1, sizeof(Matrix));
	matrix->rows = rows;
	matrix->cols = cols;

	matrix->data = calloc(rows, sizeof(double*));

	for(int i = 0; i < rows; i++) {
		matrix->data[i] = calloc(cols, sizeof(double));
	}

	return matrix;
}

Matrix* copy_matrix(Matrix* matrix) {
	Matrix* copy = create_matrix(matrix->rows, matrix->cols);
	for(int i = 0; i < matrix->rows; i++) {
		for (int j = 0; j < matrix->cols; j++) {
			copy->data[i][j] = matrix->data[i][j];
		}
	}
	return copy;
}

void free_matrix(Matrix* matrix) {
	if(matrix != NULL) {
		if(matrix->data != NULL) {
			for (int i = 0; i < matrix->rows; i++) {
				if(matrix->data[i] != NULL) {
					free(matrix->data[i]);
				}
			}
			free(matrix->data);
		}
		free(matrix);
	}
}

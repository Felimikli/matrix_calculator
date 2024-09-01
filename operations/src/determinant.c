#include "determinant.h"
#include "gauss_elimination.h"
#include "utils.h"

double get_determinant(Matrix* matrix){

	
	double det = 1.0;

	Gauss_elimination_result gauss_result = gauss_elimination_row_exchanges(matrix);
	Matrix* det_matrix = gauss_result.matrix;
	int row_exchanges = gauss_result.row_exchanges;

	for(int i = 0; i < det_matrix->cols && i < det_matrix->rows; i++) {
		det *= det_matrix->data[i][i];
	}

	free_matrix(det_matrix);

	if(row_exchanges%2 == 0) {
		return det;
	}
	return -det;
}

#include "determinant.h"
#include "utils.h"
#include "gauss.h"

double get_determinant(double** matrix, int rows, int cols){

	// laplace (slow, O(n!))
	// double det = 0.0;

	// switch (matrix_size) {
	// case 1:
		// det = matrix[0][0];
		// break;
	// case 2:
		// det = (matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]); 
		// break;
	// default:
		// for (int i = 0; i < matrix_size; i++) {
			// int sign;
			// int minor_size = matrix_size-1;
			// double** minor = allocate_matrix(minor_size, minor_size);
			// int minor_row = 0;
			// for (int j = 1; j < matrix_size; j++) {
				// int minor_col = 0;
				// for (int k = 0; k < matrix_size; k++) {
					// if(k != i) {
						// minor[minor_row][minor_col] = matrix[j][k];
						// sign = (i % 2 == 0) ? 1 : -1;
						// minor_col++;
					// }
				// }
				// minor_row++;
			// }
			// det += sign  * matrix[0][i] * get_determinant(minor_size, minor);
			// free_matrix(minor, minor_size);
		// }
		// break;
	// }

	// gaussian elimination and product of the principal diag
	

	double det = 1.0;
	double** det_matrix;
	det_matrix = gauss(matrix, rows, cols);
	for(int i = 0; i < cols && i < rows; i++) {
		det *= det_matrix[i][i];
	}
	free_matrix(det_matrix, rows);

	return det;
}

#include "operations_loop.h"
#include "utils.h"


int main() {

	Matrix matrix;
	matrix.rows = get_matrix_rows(0);
	matrix.cols = get_matrix_cols();
	matrix.data = fill_matrix(matrix.rows, matrix.cols);

	operations_loop(&matrix);
	
	return 0;
}

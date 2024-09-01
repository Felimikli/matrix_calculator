#include "operations_loop.h"
#include "utils.h"


int main() {

	int rows = get_matrix_rows(0);
	int cols = get_matrix_cols();
	Matrix* matrix = create_matrix(rows, cols);
	fill_matrix(matrix);

	operations_loop(matrix);
	
	return 0;
}

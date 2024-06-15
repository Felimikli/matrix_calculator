#include "../include/operations_loop.h"
#include "../include/utils.h"

int main() {

	int* matrix_size = get_matrix_size(0);
	double** matrix = fill_matrix(matrix_size);

	operations_loop(matrix, matrix_size);
	
	return 0;
}

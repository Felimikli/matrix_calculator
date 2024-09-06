#include <math.h>
#include <stdio.h>
#include "common_structs.h"
#include "operations_loop.h"
#include "utils.h"


int main() {

	int rows = get_matrix_rows(0);
	int cols = get_matrix_cols();
	Matrix* matrix = create_matrix(rows, cols);
	fill_matrix(matrix);

	Node* head = create_node(OPERATION_BLANK, matrix, NULL, 1, NULL, NULL);
	Result* res;

	char operation_input;
	printf("Your matrix:\n");
	print_matrix(head->m1);
	while(operation_input != 'q') {
		printf("Press:\n");
		printf("'D' to calculate determinant\n");
		printf("'I' to calculate the inverse matrix\n");
		printf("'E' to exponentiate\n");
		printf("'T' to transpose\n");
		printf("'M' to multiplicate matrices\n");
		printf("'A' to add matrices\n");
		printf("'S' to substract matrices\n");
		printf("'R' to calculate rank\n");
		printf("'G' for Gaussian elimination\n");
		printf("'N' to enter other matrix\n");
		printf("'Q' to exit\n");
		scanf(" %c", &operation_input);
		res = operations_loop(head);

		printf("\n");
		print_matrix(res->result_matrix);
		printf("det: %lf\n", res->determinant);
		printf("rank: %d\n", res->rank);
		printf("\n");

		head->m1 = res->result_matrix;
	}
	
	return 0;
}

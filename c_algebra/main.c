#include "laplace/laplace.c"
#include "mat_mult/mat_mult.c"
#include "transpose/transpose.c"

int main() {

	char action_input;
	printf("press:\n 'd' to calculate determinant\n 'm' to multiply matrices\n 't' to transpose\n");
	scanf("%c", &action_input);

	switch(action_input) {
		case "d":
			double get_determinant(int matrix_size, double** matrix);
		case "m":
			double** multiply(double** first_matrix, double** second_matrix, int result_matrix_rows, int middle_cols_rows, int result_matrix_cols);
		case "t":
			double** transpose(double** matrix, int* matrix_size);
	}
	



	return 0;
}


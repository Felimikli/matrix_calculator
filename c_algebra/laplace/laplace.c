#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

int get_size(void){
	int size;
	printf("Write the size of the square matrix (for 3x3 matrix type 3): \n");
	scanf("%d", &size);
	return size;
};

double** fill_matrix(int matrix_size) {

	double** matrix = calloc(matrix_size, sizeof(double*));
	for(int c = 0; c < matrix_size; c++) {
		matrix[c] = calloc(matrix_size, sizeof(double));
	}

	for (int i = 0; i < matrix_size; i++) {
		for (int j = 0; j < matrix_size; j++) {
			printf("Type coordinate (%d, %d): ", i+1 , j+1);
			scanf(" %lf", &matrix[i][j]);
		}
	}
	return matrix;
}

void print_matrix(int matrix_size, double** matrix){
	for (int i = 0; i < matrix_size; i++) {
		for (int j = 0; j < matrix_size; j++) {
			printf("%.2lf\t", matrix[i][j]);
		}
		printf("\n");
	}
}

double get_determinant(int matrix_size, double** matrix){

	double det = 0.0;

	switch (matrix_size) {
	case 1:
		det = matrix[0][0];
		break;
	case 2:
		det = (matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]); 
		break;
	default:
		for (int i = 0; i < matrix_size; i++) {
        
			int sign;
			int minor_size = matrix_size-1;
			double** minor = calloc(minor_size, sizeof(double*));
			for(int c = 0; c < minor_size; c++) {
				minor[c] = calloc(minor_size, sizeof(double));
			}

			int minor_row = 0;
			for (int j = 1; j < matrix_size; j++) {
				int minor_col = 0;
				for (int k = 0; k < matrix_size; k++) {
					if(k != i) {
						minor[minor_row][minor_col] = matrix[j][k];
						sign = (i % 2 == 0) ? 1 : -1;
						minor_col++;
					}
				}
				minor_row++;        
			}
			det += sign  * matrix[0][i] * get_determinant(minor_size, minor);

			for(int k = 0; k < minor_size; k++) {
				free(minor[k]);
			}
			free(minor);
		}
		break;
	}

	return det;
}

int main(){
	int matrix_size = get_size();

	printf("fill your matrix:\n");
	double** matrix = fill_matrix(matrix_size);

	printf("\nYour matrix:\n");
	print_matrix(matrix_size, matrix);
	printf("\n");

	clock_t start, end;
	double time_spent;
	start = clock(); // Start measuring time


	printf("DETERMINANT: %lf\n", get_determinant(matrix_size, matrix));


	end = clock(); // Stop measuring time
	time_spent = ((double) (end - start)) / CLOCKS_PER_SEC;

	printf("\nTime taken to calculate determinant: %lf seconds\n------------------------------------------------------\n\n", time_spent);

	// free matrix
	for(int k = 0; k < matrix_size; k++) {
		free(matrix[k]);
	}
	free(matrix);

	char exit_input;
	printf("to continue press anything,\nto exit press: q\n");
	scanf(" %c", &exit_input);
	if(exit_input == 'q') {
		return 0;
	} else {
		main();
	}
}

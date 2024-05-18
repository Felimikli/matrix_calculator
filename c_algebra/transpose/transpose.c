#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

int* get_matrix_size(){
	int* matrix_size = (int*)malloc(2 * sizeof(int)) ;
	printf("Number of rows: ");
	scanf("%d",&matrix_size[0]);
	printf("Number of columns: ");
	scanf("%d",&matrix_size[1]);

	return matrix_size;
}

double** fill_matrix(int* matrix_size) {

	double** matrix = malloc(matrix_size[0] * sizeof(double*));
	for(int i = 0; i < matrix_size[0]; i++) {
		matrix[i] = malloc(matrix_size[1] * sizeof(double));
	}

	for(int j = 0; j < matrix_size[0]; j++) {
		for(int k = 0; k < matrix_size[1]; k++) {
			printf("type coordinate (%d, %d): ", j+1, k+1);
			scanf(" %lf", &matrix[j][k]);
		}
	}
	return matrix;
}

double** transpose(double** matrix, int* matrix_size) {
	
	double** transposed_matrix = malloc(matrix_size[1] * sizeof(double*));
	for(int i = 0; i < matrix_size[1]; i++) {
		transposed_matrix[i] = malloc(matrix_size[0] * sizeof(double));
	}
	for(int j = 0; j < matrix_size[1]; j++) {
		for(int k = 0; k < matrix_size[0]; k++) {
			transposed_matrix[j][k] = matrix[k][j];
		}
	}
	return transposed_matrix;
}

void print_matrix(double** matrix, int* matrix_size) {
    for(int i = 0; i < matrix_size[0]; i++) {
        for(int j = 0; j < matrix_size[1]; j++) {
            printf("%.2lf,\t", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
	printf("type your matrix sizes:\n");
	int* matrix_size = get_matrix_size();
	
	printf("fill your matrix:\n");
	double** matrix = fill_matrix(matrix_size);	
	printf("your matrix:\n");
	print_matrix(matrix, matrix_size);

	double** transposed_matrix = transpose(matrix, matrix_size);
	int* transposed_matrix_size = (int*)malloc(2 * sizeof(int));
	transposed_matrix_size[0] = matrix_size[1];
	transposed_matrix_size[1] = matrix_size[0];
	printf("your transposed matrix:\n");
	print_matrix(transposed_matrix, transposed_matrix_size);

	free(matrix_size);
	free(transposed_matrix_size);

	for(int i = 0; i < matrix_size[0];i++) {
		free(matrix[i]);
	}
	free(matrix);

	for(int j = 0; j < matrix_size[1];j++) {
		free(transposed_matrix[j]);
	}
	free(transposed_matrix);

	char exit_input;
	printf("to continue press anything,\nto exit press: q\n");
	scanf(" %c", &exit_input);
	if(exit_input == 'q') {
		return 0;
	} else {
		main();
	}
}

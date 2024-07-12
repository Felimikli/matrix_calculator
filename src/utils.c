#include <stdio.h>
#include <stdlib.h>
#include "../include/utils.h"

double** allocate_matrix(int rows, int cols) {
	double** matrix = calloc(rows, sizeof(double*));
	for(int i = 0; i < rows; i++) {
	matrix[i] = calloc(cols, sizeof(double));
	}
	return matrix;
}
int* get_matrix_size(int set_no_rows){
	int* matrix_size = (int*)malloc(2 * sizeof(int)) ;
	printf("Number of rows: ");
	scanf("%d",&matrix_size[0]);
	printf("Number of columns: ");
	scanf("%d",&matrix_size[1]);

	if(set_no_rows && set_no_rows != matrix_size[0]){
		printf("invalid number of rows, it must be equal to numbre of rows of first matrix (%d)\n", set_no_rows);
		free(matrix_size);
		return get_matrix_size(set_no_rows);
	} else {
		return matrix_size;
	}
}

double** fill_matrix(int rows, int cols) {
	double** matrix = malloc(rows * sizeof(double*));
	for(int i = 0; i < rows; i++) {
		matrix[i] = malloc(cols * sizeof(double));
	}

	for(int j = 0; j < rows; j++) {
		for(int k = 0; k < cols; k++) {
			printf("type coordinate (%d, %d): ", j+1, k+1);
			scanf(" %lf", &matrix[j][k]);
		}
	}
	return matrix;
}

void print_matrix(double** matrix, int rows, int cols) {
	for(int i = 0; i < rows; i++) {
		for(int j = 0; j < cols; j++) {
			if(matrix[i][j] == -0.0) {matrix[i][j] = 0;}
			printf("%lf\t", matrix[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void free_matrix(double** matrix, int rows) {
	for (int i = 0; i < rows; i++) {
		free(matrix[i]);
	}
	free(matrix);
}

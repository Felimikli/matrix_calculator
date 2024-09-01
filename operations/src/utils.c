#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

double** allocate_matrix(int rows, int cols) {
	double** matrix = calloc(rows, sizeof(double*));
	for(int i = 0; i < rows; i++) {
	matrix[i] = calloc(cols, sizeof(double));
	}
	return matrix;
}

void copy_matrix(double** copy, double** matrix, int rows, int cols) {
	for(int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			copy[i][j] = matrix[i][j];
		}
	}
}


int get_matrix_rows(int mult_cols) {
	int rows;
	printf("Number of rows: ");
	scanf("%d",&rows);
	// just for multiplication operation
	if(mult_cols && mult_cols != rows){
		printf("invalid number of rows, it must be equal to number of cols of first matrix (%d)\n", mult_cols);
		return get_matrix_rows(mult_cols);
	} else {
		return rows;
	}
}
int get_matrix_cols() {
	int cols;
	printf("Number of rows: ");
	scanf("%d",&cols);
	return cols;
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
			if(matrix[i][j] == -0) {matrix[i][j] = 0;}
			printf("%.1lf\t", matrix[i][j]);
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

void exchange_matrix_rows(double** matrix, int no_cols, int row1, int row2) {
	double temp;
	for(int j = 0; j < no_cols; j++) {
		temp = matrix[row1][j];
		matrix[row1][j] = matrix[row2][j];
		matrix[row2][j] = temp;
	}
}

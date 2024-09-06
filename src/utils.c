#include "../include/utils.h"
#include <stdio.h>
#include <stdlib.h>

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
	printf("Number of cols: ");
	scanf("%d",&cols);
	return cols;
}

void fill_matrix(Matrix* matrix) {
	for(int j = 0; j < matrix->rows; j++) {
		for(int k = 0; k < matrix->cols; k++) {
			printf("type coordinate (%d, %d): ", j+1, k+1);
			scanf(" %lf", &matrix->data[j][k]);
		}
	}
}

Matrix* create_matrix(int rows, int cols) {

	// Matrix* matrix = calloc(1, sizeof(Matrix));

	// matrix->rows = rows;
	// matrix->cols = cols;

	// matrix->data = calloc(rows, sizeof(double*));

	// for(int i = 0; i < rows; i++) {
		// matrix->data[i] = calloc(cols, sizeof(double));
	// }

	// return matrix;
	
	Matrix* matrix = calloc(1, sizeof(Matrix)); // Use calloc for Matrix
	if (!matrix) {
		exit(1);
		return NULL;
	}
	matrix->rows = rows;
	matrix->cols = cols;

	matrix->data = calloc(rows, sizeof(double*)); // Use calloc for data array
	if (!matrix->data) {
		// Handle allocation failure
		exit(2);
		free(matrix); // Free previously allocated memory
		return NULL;
	}

	for(int i = 0; i < rows; i++) {
		matrix->data[i] = calloc(cols, sizeof(double)); // Use calloc for each row
		if (!matrix->data[i]) {
			// Handle allocation failure
			exit(3);
			for (int j = 0; j < i; j++) {
				free(matrix->data[j]);
			}
			free(matrix->data);
			free(matrix);
			return NULL;
		}
	}

	return matrix;
}

Matrix* replace_matrix(Matrix* destination, Matrix* source) {
	free_matrix(destination);
	return source;
}

Matrix* copy_matrix(Matrix* matrix) {
	Matrix* copy = create_matrix(matrix->rows, matrix->cols);
	for(int i = 0; i < matrix->rows; i++) {
		for (int j = 0; j < matrix->cols; j++) {
			copy->data[i][j] = matrix->data[i][j];
		}
	}
	return copy;
}

void print_matrix(Matrix* matrix) {
	for(int i = 0; i < matrix->rows; i++) {
		for(int j = 0; j < matrix->cols; j++) {
			if(matrix->data[i][j] == -0) {matrix->data[i][j] = 0;}
			printf("%lf\t", matrix->data[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void free_matrix(Matrix* matrix) {
	if(matrix) {
		if(matrix->data) {
			for (int i = 0; i < matrix->rows; i++) {
				free(matrix->data[i]);
			}
		}
		free(matrix->data);
	}
	free(matrix);
}

void exchange_matrix_rows(Matrix* matrix, int row1, int row2) {
	double temp;
	for(int j = 0; j < matrix->cols; j++) {
		temp = matrix->data[row1][j];
		matrix->data[row1][j] = matrix->data[row2][j];
		matrix->data[row2][j] = temp;
	}
}


Node* create_node(Operation_type op, Matrix* matrix1, Matrix* matrix2, int exp, Node* prev_node, Node* next_node) {
	Node* new_node = malloc(sizeof(Node));

	new_node->op_type = op;
	new_node->m1 = matrix1;
	new_node->m2 = matrix2;
	new_node->exponent = exp;
	new_node->prev = prev_node;
	new_node->next = new_node;

	return new_node;
}

void append_end(List* list, Node* new_node) {
	list->tail->next = new_node;
	new_node->prev = list->tail;
	list->tail = new_node;
}

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include "operations_loop.h"
#include "utils.h"
#include "determinant.h"
#include "add_sub.h"
#include "multiply.h"
#include "transpose.h"
#include "inverse.h"
#include "rank.h"
#include "exponentiate.h"
#include "gauss.h"


void operations_loop(Matrix* matrix) {
	int second_matrix_rows;
	int second_matrix_cols;
	double** second_matrix;
	double determinant;

	char operation_input;
	printf("Your matrix:\n");
	print_matrix(matrix->data, matrix->rows, matrix->cols);
	while(1) {
		printf("Press:\n");
		if(matrix->rows == matrix->cols) {
			printf("'D' to calculate determinant\n");
			determinant = get_determinant(matrix->data, matrix->rows, matrix->cols);
			if(determinant != 0) {
				printf("'I' to calculate the inverse matrix\n");
			}
			printf("'E' to exponentiate\n");
		}
		printf("'T' to transpose\n");
		printf("'M' to multiplicate matrices\n");
		printf("'A' to add matrices\n");
		printf("'S' to substract matrices\n");
		printf("'R' to calculate rank\n");
		printf("'G' for Gaussian elimination\n");
		printf("'N' to enter other matrix\n");
		printf("'Q' to exit\n");
		scanf(" %c", &operation_input);
		switch (tolower(operation_input)) {
			case 'd': {
				if(matrix->rows == matrix->cols) {
					printf("determinant: %lf\n", determinant);
				} else {
					printf("matrix not square, can't calculate determinant\n");
				}
				break;
			}
			case 't': {
				double** transposed = transpose(matrix->data, matrix->rows, matrix->cols);
				free_matrix(matrix->data, matrix->rows);
				matrix->data = transposed;
				int temp = matrix->rows;
				matrix->rows = matrix->cols;
				matrix->cols = temp;
				break;
			}
			case 'm': {
				second_matrix_rows = get_matrix_rows(matrix->cols);
				second_matrix_cols = get_matrix_cols();
				second_matrix = fill_matrix(second_matrix_rows, second_matrix_cols);
				double** multiplied = multiply(matrix->data, second_matrix, matrix->rows, matrix->cols, second_matrix_cols); 
				free_matrix(matrix->data, matrix->rows);
				matrix->data = multiplied;
				free_matrix(second_matrix, second_matrix_rows);
				matrix->cols = second_matrix_cols;
				break;
			}
			case 'a': {
				second_matrix = fill_matrix(matrix->rows,matrix->cols);
				double** added_matrix = add(matrix->data, second_matrix, matrix->rows, matrix->cols);
				copy_matrix(matrix->data, added_matrix, matrix->rows, matrix->cols);
				free_matrix(added_matrix, matrix->rows);
				free_matrix(second_matrix, matrix->rows);
				break;
			}
			case 's': {
				second_matrix = fill_matrix(matrix->rows,matrix->cols);
				double** substracted_matrix = substract(matrix->data, second_matrix, matrix->rows, matrix->cols);
				copy_matrix(matrix->data, substracted_matrix, matrix->rows, matrix->cols);
				free_matrix(substracted_matrix, matrix->rows);
				free_matrix(second_matrix, matrix->rows);
				break;
			}
			case 'i': {
				if (matrix->rows == matrix->cols && determinant != 0) {
					double** inverse_matrix = get_inverse(matrix->data, matrix->rows, determinant);
					free_matrix(matrix->data, matrix->rows);
					matrix->data = inverse_matrix;
				} else {
					printf("matrix is not square or not non-singular\n");
				}
				break;
			}
			case 'r': {
				int rank = get_rank(matrix->data, matrix->rows, matrix->cols);
				printf("rank: %d\n", rank);
				break;
			}
			case 'e': {
				if (matrix->rows == matrix->cols) {
					int exponent;
					printf("type exponent: \n");
					scanf(" %d", &exponent);
					double** exp_matrix = exponentiate(matrix->data, matrix->rows, exponent);
					free_matrix(matrix->data, matrix->rows);
					matrix->data = exp_matrix;
				} else {
					printf("matrix is not square\n");
				}
				break;
			}
			case 'g': {
				double** gauss_matrix = gauss(matrix->data, matrix->rows, matrix->cols);
				free_matrix(matrix->data, matrix->rows);
				matrix->data = gauss_matrix;
				break;
			}
			case 'n': {
				free_matrix(matrix->data, matrix->rows);
				// matrix_size = get_matrix_size(0);
				matrix->data = fill_matrix(matrix->rows, matrix->cols);
				break;
			}
			case 'q': {
				free_matrix(matrix->data, matrix->rows);
				return;
			}
			default: {
				printf("invalid input\n");
				break;
			}
		}
		printf("\n");
		print_matrix(matrix->data, matrix->rows, matrix->cols);
	}
	free_matrix(matrix->data, matrix->rows);
}

#include <ctype.h>
#include <stdio.h>
#include "operations_loop.h"
#include "utils.h"
#include "determinant.h"
#include "add_sub.h"
#include "multiply.h"
#include "transpose.h"
#include "inverse.h"
#include "rank.h"
#include "exponentiate.h"
#include "gauss_elimination.h"


void operations_loop(Matrix* matrix) {
	double determinant;

	char operation_input;
	printf("Your matrix:\n");
	print_matrix(matrix);
	while(1) {
		printf("Press:\n");
		if(matrix->rows == matrix->cols) {
			printf("'D' to calculate determinant\n");
			determinant = get_determinant(matrix);
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
				
				Matrix* result_matrix = transpose(matrix);
				matrix = replace_matrix(matrix, result_matrix);

				break;
			}
			case 'm': {
				int second_matrix_rows = get_matrix_rows(matrix->cols);
				int second_matrix_cols = get_matrix_cols();
				Matrix* second_matrix = create_matrix(second_matrix_rows, second_matrix_cols);
				fill_matrix(second_matrix);

				Matrix* result_matrix = multiply(matrix, second_matrix);
				matrix = replace_matrix(matrix, result_matrix);

				free_matrix(second_matrix);
				break;
			}
			case 'a': {
				Matrix* second_matrix = create_matrix(matrix->rows, matrix->cols);
				fill_matrix(second_matrix);

				Matrix* result_matrix = add(matrix, second_matrix);
				matrix = replace_matrix(matrix, result_matrix);

				free_matrix(second_matrix);
				break;
			}
			case 's': {
				Matrix* second_matrix = create_matrix(matrix->rows, matrix->cols);
				fill_matrix(second_matrix);

				Matrix* result_matrix = substract(matrix, second_matrix);
				matrix = replace_matrix(matrix, result_matrix);

				free_matrix(second_matrix);
				break;
			}
			case 'i': {
				if (matrix->rows == matrix->cols && determinant != 0) {
					Matrix* result_matrix = get_inverse(matrix);
					matrix = replace_matrix(matrix, result_matrix);
				} else {
					printf("matrix is not square or not non-singular\n");
				}
				break;
			}
			case 'r': {
				int rank = get_rank(matrix);
				printf("rank: %d\n", rank);
				break;
			}
			case 'e': {
				if (matrix->rows == matrix->cols) {
					int exponent;
					printf("type exponent: \n");
					scanf(" %d", &exponent);

					Matrix* result_matrix = exponentiate(matrix, exponent);
					matrix = replace_matrix(matrix, result_matrix);
				} else {
					printf("matrix is not square\n");
				}
				break;
			}
			case 'g': {
				Matrix* result_matrix = gauss_elimination(matrix);
				matrix = replace_matrix(matrix, result_matrix);
				break;
			}
			case 'n': {
				fill_matrix(matrix);
				break;
			}
			case 'q': {
				free_matrix(matrix);
				return;
			}
			default: {
				// printf("invalid input\n");
				// break;
			}
		}
		printf("\n");
		print_matrix(matrix);
	}
	free_matrix(matrix);
}

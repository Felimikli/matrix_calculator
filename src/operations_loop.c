#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include "../include/operations_loop.h"
#include "../include/utils.h"
#include "../include/operations/determinant.h"
#include "../include/operations/add_sub.h"
#include "../include/operations/multiply.h"
#include "../include/operations/transpose.h"
#include "../include/operations/inverse.h"


void operations_loop(double** matrix, int* matrix_size) {
	int* second_matrix_size;
	double** second_matrix;
	double determinant;

	char operation_input;
	printf("Your matrix:\n");
	print_matrix(matrix, matrix_size[0], matrix_size[1]);
	while(1) {
		printf("Press:\n");
		if(matrix_size[0] == matrix_size[1]) {
			printf("'D' to calculate determinant\n");
			determinant = get_determinant(matrix_size[0], matrix);
			if(determinant != 0) {
				printf("'I' to calculate the inverse matrix\n");
			}
		}
		printf("'T' to transpose\n");
		printf("'M' to multiplicate matrices\n");
		printf("'A' to add matrices\n");
		printf("'S' to substract matrices\n");
		printf("'R' to enter other matrix\n");
		printf("'Q' to exit\n");
		scanf(" %c", &operation_input);
		switch (tolower(operation_input)) {
			case 'd': {
				if(matrix_size[0] == matrix_size[1]) {
					printf("determinant: %lf\n", determinant);
				} else {
					printf("matrix not square, can't calculate determinant\n");
				}
				break;
			}
			case 't': {
				double** transposed = transpose(matrix, matrix_size[0], matrix_size[1]);
				free_matrix(matrix, matrix_size[0]);
				matrix = transposed;
				int temp = matrix_size[0];
				matrix_size[0] = matrix_size[1];
				matrix_size[1] = temp;
				break;
			}
			case 'm': {
				second_matrix_size = get_matrix_size(matrix_size[1]);
				second_matrix = fill_matrix(second_matrix_size[0], second_matrix_size[1]);
				double** multiplied = multiply(matrix, second_matrix, matrix_size[0], matrix_size[1], second_matrix_size[1]); 
				free_matrix(matrix, matrix_size[0]);
				matrix = multiplied;
				free_matrix(second_matrix, second_matrix_size[0]);
				matrix_size[1] = second_matrix_size[1];
				free(second_matrix_size);
				break;
			}
			case 'a': {
				second_matrix = fill_matrix(matrix_size[0],matrix_size[1]);
				double** added = add(matrix, second_matrix, matrix_size); 
				free_matrix(matrix, matrix_size[0]);
				matrix = added;
				free_matrix(second_matrix, matrix_size[0]);
				break;
			}
			case 's': {
				second_matrix = fill_matrix(matrix_size[0],matrix_size[1]);
				double** substracted = substract(matrix, second_matrix, matrix_size);
				free_matrix(matrix, matrix_size[0]);
				free_matrix(second_matrix, matrix_size[0]);
				matrix = substracted;
				break;
			}
			case 'i': {
				if (matrix_size[0] == matrix_size[1] && determinant != 0) {
					double** inverse_matrix = get_inverse(matrix, matrix_size[0], determinant);
					free_matrix(matrix, matrix_size[0]);
					matrix = inverse_matrix;
				} else {
					printf("matrix is not square and non-singular\n");
				}
				break;
			}
			case 'r': {
				free_matrix(matrix, matrix_size[0]);
				free(matrix_size);
				matrix_size = get_matrix_size(0);
				matrix = fill_matrix(matrix_size[0], matrix_size[1]);
				break;
			}
			case 'q': {
				free_matrix(matrix, matrix_size[0]);
				free(matrix_size);
				return;
			}
			default: {
				printf("invalid input\n");
				break;
			}
		}
		printf("\n");
		print_matrix(matrix, matrix_size[0], matrix_size[1]);
	}
	free_matrix(matrix, matrix_size[0]);
	free(matrix_size);
}

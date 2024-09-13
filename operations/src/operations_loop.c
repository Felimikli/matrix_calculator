#include <math.h>
#include <stdio.h>
#include "operations_loop.h"
#include "operations.h"
#include <stddef.h>


Result* operations_loop(Node* prev) {

	Result* result;
	result->result_matrix = NULL;
	result->determinant = 0;
	result->rank = 0;
	result->has_determinant = false;
	result->has_rank = false;

	switch (prev->op_type) {
		case OPERATION_BLANK: {

			result->result_matrix = prev->m1;
			break;
		}
		case OPERATION_ADD: {

			result->result_matrix = add_matrices(prev->m1, prev->m2);
			break;
		}
		case OPERATION_SUBTRACT: {

			result->result_matrix = substract_matrices(prev->m1, prev->m2);
			break;
		}
		case OPERATION_MULTIPLY: {

			result->result_matrix = multiply_matrices(prev->m1, prev->m2);
			break;
		}
		case OPERATION_INVERSE: {
			if (prev->m1->rows == prev->m1->cols && get_determinant(prev->m1) != 0) {
				result->result_matrix = inverse(prev->m1);
			} else {
				printf("matrix is not square or not non-singular\n");
			}
			break;
		}
		case OPERATION_GAUSS: {
			result->result_matrix = gauss_elimination(prev->m1);
			break;
		}
		case OPERATION_TRANSPOSE: {
			
			result->result_matrix = transpose(prev->m1);
			break;
		}
		case OPERATION_DETERMINANT: {
			if(prev->m1->rows == prev->m1->cols) {
				result->determinant = get_determinant(prev->m1);
				result->has_determinant = true;
			} else {
				printf("matrix not square, can't calculate determinant\n");
			}
			break;
		}
		case OPERATION_RANK: {
			result->rank = get_rank(prev->m1);
			result->has_rank = true;
			break;
		}
		case OPERATION_POWER: {
			if (prev->m1->rows == prev->m1->cols) {
				result->result_matrix = matrix_power(prev->m1, prev->exponent);
			} else {
				printf("matrix is not square\n");
			}
			break;
		}
	}

	if(result->result_matrix != NULL) {
		result->determinant = get_determinant(result->result_matrix);
		result->rank = get_rank(result->result_matrix);
		result->has_determinant = true;
		result->has_rank = true;
		
	}


	return result;
}

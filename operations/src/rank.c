#include "funcs.h"

int get_rank(Matrix* matrix) {
	int rank = 0;
	Matrix* rank_matrix = gauss_elimination(matrix);
	for(int i = 0; i < matrix->cols && i < matrix->rows; i++) {
		if(rank_matrix->data[i][i] != 0) {
			rank++;
		}
	}
	free_matrix(rank_matrix);
	return rank;
}

#include "utils.h"
#include "rank.h"
#include "gauss.h"

int get_rank(double** matrix, int rows, int cols) {
	int rank = 0;
	double** rank_matrix;
	rank_matrix = gauss(matrix, rows, cols);
	for(int i = 0; i < cols; i++) {
		if(rank_matrix[i][i] != 0) {
			rank++;
		}
	}
	free_matrix(rank_matrix, rows);
	return rank;
}

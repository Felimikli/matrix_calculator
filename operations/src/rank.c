#include "utils.h"
#include "rank.h"
#include "transpose.h"

int get_rank(double** matrix, int rows, int cols) {
	int rank = 0;
	double** rank_matrix;
	int rank_rows = rows;
	int rank_cols = cols;
	if(cols > rows) {
		rank_matrix = transpose(matrix, rows, cols);
		rank_rows = cols;
		rank_cols = rows;
	} else {
		rank_matrix = allocate_matrix(rank_rows, rank_cols);
		copy_matrix(rank_matrix, matrix, rank_rows, rank_cols);
	}
	for(int j = 0; j < rank_cols; j++) {
		for(int i = (j+1); i < rank_rows; i++) {
			if((rank_matrix[i][j] != 0) && (rank_matrix[j][j] != 0)) {
				double x = (-1) * rank_matrix[i][j] / rank_matrix[j][j];
				for(int k = 0; k < rank_cols; k++) {
					rank_matrix[j][k] *= x;
					rank_matrix[i][k] += rank_matrix[j][k];
				}
			}
		}
	}
	for(int i = 0; i < rank_rows; i++) {
		for(int j = 0; j < rank_cols; j++) {
			if(rank_matrix[i][j] != 0) {
				++rank;
				break;
			}
		}
	}
	free_matrix(rank_matrix, rank_rows);
	return rank;
}

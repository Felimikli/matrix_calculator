#include "../../include/utils.h"
#include "../../include/operations/rank.h"
#include "../../include/operations/transpose.h"

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
		rank_matrix = allocate_matrix(rows, cols);
		for(int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				rank_matrix[i][j] = matrix[i][j];
			}
		}

	}
	for(int j = 0; j < rank_cols; j++) {
		for(int i = (j+1); i < rank_rows; i++) {
			if(rank_matrix[i][j] != 0 && rank_matrix[j][j] != 0) {
				double x = (-1) * rank_matrix[i][j] / rank_matrix[j][j];
				for(int k = 0; k < rank_cols; k++) {
					rank_matrix[j][k] *= x;
					rank_matrix[i][k] += rank_matrix[j][k];
				}
			}
		}
	}
	for(int l = 0; l < rank_rows; l++) {
		int h = 0;
		while (h < rank_cols) {
			if(rank_matrix[l][h] != 0) {
				break;
			} else {
				h++;
			}
		}
		if(h != rank_cols) {
			rank += 1;
		}
	}
	free_matrix(rank_matrix, rank_rows);
	return rank;
}

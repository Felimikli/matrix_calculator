typedef struct Matrix {
	int rows;
	int cols;
	double** data;
} Matrix;


typedef struct Gauss_elimination_result {
	Matrix* matrix;
	int row_exchanges;
} Gauss_elimination_result;

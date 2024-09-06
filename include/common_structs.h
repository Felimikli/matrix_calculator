#pragma once

typedef struct Matrix {
	int rows;
	int cols;
	double** data;
} Matrix;


typedef struct Gauss_elimination_result {
	Matrix* matrix;
	int row_exchanges;
} Gauss_elimination_result;

typedef enum {
	OPERATION_BLANK,
	OPERATION_ADD,
	OPERATION_SUBTRACT,
	OPERATION_MULTIPLY,
	OPERATION_INVERSE,
	OPERATION_GAUSS,
	OPERATION_TRANSPOSE,
	OPERATION_DETERMINANT,
	OPERATION_RANK,
	OPERATION_POWER,
} Operation_type;

typedef struct Node {
	Operation_type op_type;
	Matrix* m1;
	Matrix* m2;
	int exponent;
	struct Node* prev;
	struct Node* next;
} Node;

typedef struct Result {
	Matrix* result_matrix;
	double determinant;
	int rank;
} Result;

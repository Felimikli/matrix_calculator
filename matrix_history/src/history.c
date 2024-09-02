#include "history.h"
#include <stdlib.h>
#include <sys/types.h>
#include "operations_loop.h"
#include "utils.h"
#include "determinant.h"
#include "add_sub.h"
#include "multiply_matrices.h"
#include "transpose.h"
#include "inverse.h"
#include "rank.h"
#include "matrix_power.h"
#include "gauss_elimination.h"


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
	OPERATION_POWER
} Operation_type;
int num_op = 9;

typedef struct Node {
	Operation_type op_type;
	Matrix* m1;
	Matrix* m2;
	int exponent;
	struct Node* prev;
	struct Node* next;
} Node;

Node* create_node(Operation_type op, Matrix* matrix1, Matrix* matrix2, int exp, Node* prev_node, Node* next_node) {
	Node* new_node = malloc(sizeof(Node));

	new_node->op_type = op;
	new_node->m1 = matrix1;
	new_node->m2 = matrix2;
	new_node->exponent = exp;
	new_node->prev = prev_node;
	new_node->next = new_node;

	return new_node;
}


void matrix_history() {





	Matrix* identity = create_matrix(3, 3);
	for(int i = 0; i < 3; i++) {
		identity->data[i][i] = 1;
	}

	Node* head = create_node(OPERATION_BLANK, identity, NULL, 0, NULL, NULL);

	print_matrix(identity);


}

#include "history.h"
#include <stdlib.h>
#include <sys/types.h>
#include "operations_loop.h"
#include "funcs.h"




void matrix_history() {
	Matrix* identity = create_matrix(3, 3);
	for(int i = 0; i < 3; i++) {
		identity->data[i][i] = 1;
	}

	Node* head = create_node(OPERATION_BLANK, identity, NULL, 0, NULL, NULL);

	print_matrix(identity);
}

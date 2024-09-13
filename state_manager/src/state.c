#include <stdio.h>
#include "common_structs.h"
#include "utils.h"

List* create_list_initial_node(Node* initial_node){
	List* list;

	list->head = initial_node;
	list->curr = initial_node;
	list->tail = initial_node;

	list->length = 1;

	return list;
}

void initial_draw_call() {

	Matrix* BLANK_MATRIX = create_matrix(3, 3);
	Node* BLANK_NODE = create_node(OPERATION_BLANK, BLANK_MATRIX, NULL, 1, NULL, NULL);
	List* list = create_list_initial_node(BLANK_NODE);

	
}

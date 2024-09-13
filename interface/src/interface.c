#include <stdio.h>
#include <stdlib.h>
#include "common_structs.h"
#include "utils.h"
#include "../include/interface.h"

void draw_node(Node* node) {
	printf("Your Matrix: ");
	print_matrix(node->m1);
	if(node->m2 != NULL) {
		printf("Your Second Matrix: ");
		print_matrix(node->m2);
	}
}

void initial_draw(Node* node) {
	// initialize_window();
	draw_node(node);
}

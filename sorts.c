#include <stdlib.h>
#include <stdbool.h>
#include "sorts.h"
#include "miniunit.h"
#include "clog.h"

void _order_bst(int* nums_array, BSTNode* a_root, int* addr_inc); // fill array from bst.
void _destroy_tree(BSTNode* a_root);
void _insert_trees(int value, BSTNode** a_root); 	// helper create_bst -- insert childs of root.

void _insert_trees(int value, BSTNode** a_root) {
	if(*a_root == NULL) {
		BSTNode* new_bst_node = malloc(sizeof(*new_bst_node));
		*new_bst_node = (BSTNode) { .value = value, .left = NULL, .right = NULL};
		*a_root = new_bst_node;
	}
	else if(value < ((*a_root) -> value)) {
		_insert_trees(value, &((*a_root) -> left));
	}
	else {
		_insert_trees(value, &((*a_root) -> right));
	}
}

void _destroy_tree(BSTNode* a_root) {
	if(a_root != NULL) {
		_destroy_tree(a_root -> left);
		_destroy_tree(a_root -> right);
		free(a_root);
	}
	a_root = NULL;
}

void empty_bst(BST* bst) {
	_destroy_tree(bst -> root);
	bst->size = 0;
}

void _order_bst(int* num_array, BSTNode* a_root, int* addr_inc) {
	if(a_root != NULL) {
		_order_bst(num_array, a_root -> left, addr_inc);
		*(num_array + *addr_inc) = (a_root -> value);  // visit roor
		*addr_inc += 1;
		_order_bst(num_array, a_root -> right, addr_inc);
	}
}

void tree_sort_array(int* nums_array, size_t size) {
	int addr_inc = 0; 
	BST bst = create_bst(nums_array, size);
	_order_bst(nums_array, bst.root, &addr_inc);
	empty_bst(&bst);
}

BST create_bst(const int* num_array, int a_size) {
	BST root_bst = { .root = NULL, .size = a_size};
	for(int i = 0; i < a_size; i++) {
		_insert_trees(*(num_array + i), &(root_bst.root));
	}
	return root_bst;
}

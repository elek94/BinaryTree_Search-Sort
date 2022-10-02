#include <stdlib.h>
#include <stdbool.h>

typedef struct _BSTNode {
	int value;
	struct _BSTNode* left;
	struct _BSTNode* right;
} BSTNode;

typedef struct {
	int size;
	BSTNode* root;
} BST;

BST create_bst(const int* nums_array, int size);
void empty_bst(BST* bst);
void tree_sort_array(int* nums_array, size_t a_size);

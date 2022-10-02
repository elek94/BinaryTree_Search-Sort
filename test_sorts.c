#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "sorts.h"
#include "miniunit.h"
#include "clog.h"

static void _print_elements(int* nums_array, size_t a_size); // helper for printing test cases.

// declaration of test cases.
static int _test_one_digit();
static int _test_bst_digits();
static int _test_bst_double_digits();
static int _test_bst_triple_digits();
static int _test_bst_bigger_size();
static int _test_big_root();
static int _test_small_root();

int main(int argc, char* argv[]) {
	mu_run(_test_one_digit);        // calling test cases.
	mu_run(_test_bst_digits);
	mu_run(_test_bst_double_digits);
	mu_run(_test_bst_triple_digits);
	mu_run(_test_bst_bigger_size);
	mu_run(_test_big_root);
	mu_run(_test_small_root);

	return EXIT_SUCCESS;
}

static void _print_elements(int* nums_array, size_t a_size) {
	for(int i = 0; i < a_size; i++) {
		printf("%d ", nums_array[i]);
	}
	printf("\n");
}

// definition, body, and execution of test cases.
static int _test_one_digit() {
	mu_start();

	const int nums_array[] = { 5 };
	int size = 1;
	BST bst = create_bst(nums_array, size);
	mu_check(bst.root != NULL);
	mu_check((bst.root)->value == 5);
	mu_check((bst.root)->left == NULL);
	mu_check((bst.root)->right == NULL);
	empty_bst(&bst);

	mu_end();
}

static int _test_bst_digits() {
	mu_start();
	
	const int nums_array[] = { 5, 7, 2, 9, 4 };
	int size = 5;
	BST bst = create_bst(nums_array, size);
	mu_check(bst.root != NULL);
	mu_check((bst.root)->value == 5);
	mu_check((bst.root)->left->value == 2);
	mu_check((bst.root)->left->left == NULL);
	mu_check((bst.root)->left->right->value == 4); 
	mu_check((bst.root)->right->value == 7);
	mu_check((bst.root)->right->right->value == 9);
	mu_check((bst.root)->right->left == NULL);
	empty_bst(&bst);

	int nums_array_nonconst[] = { 5, 7, 2, 9, 4 };
	size_t arr_size = sizeof(nums_array_nonconst) / sizeof(*nums_array_nonconst);
	_print_elements(nums_array_nonconst, arr_size); // before sort tree
	tree_sort_array(nums_array_nonconst, arr_size);
	_print_elements(nums_array_nonconst, arr_size); // after sort tree

	mu_end();
}

static int _test_bst_double_digits() {
	mu_start();

	const int nums_array[] = { 11, 19, 21, 10, 48 };
	int size = 5;
	BST bst = create_bst(nums_array, size);
	mu_check(bst.root != NULL);
	mu_check((bst.root)->value == 11);
	mu_check((bst.root)->left->value == 10);
	mu_check((bst.root)->right->value == 19);
	mu_check((bst.root)->right->right->value == 21);
	mu_check((bst.root)->right->left == NULL);
	mu_check((bst.root)->right->right->right->value == 48);
	empty_bst(&bst);

	int nums_array_nonconst[] = { 11, 19, 21, 10, 48 };
	size_t arr_size = sizeof(nums_array_nonconst) / sizeof(*nums_array_nonconst);
	_print_elements(nums_array_nonconst, arr_size); // before sort tree
	tree_sort_array(nums_array_nonconst, arr_size);
	_print_elements(nums_array_nonconst, arr_size); // after sort tree

	mu_end();
}

static int _test_bst_triple_digits() {
	mu_start();
	
	const int nums_array[] = { 105, 117, 216, 349, 114 };
	int size = 5;
	BST bst = create_bst(nums_array, size);
	mu_check(bst.root != NULL);
	mu_check((bst.root)->value == 105);
	mu_check((bst.root)->left == NULL);
	mu_check((bst.root)->right->value == 117); 
	mu_check((bst.root)->right->right->value == 216);
	mu_check((bst.root)->right->right->right->value == 349);
	mu_check((bst.root)->right-> right->right->right == NULL);
	mu_check((bst.root)->right->left->value == 114);
	empty_bst(&bst);

	int nums_array_nonconst[] = { 105, 117, 216, 349, 114 };
	size_t arr_size = sizeof(nums_array_nonconst) / sizeof(*nums_array_nonconst);
	_print_elements(nums_array_nonconst, arr_size);
	tree_sort_array(nums_array_nonconst, arr_size);
	_print_elements(nums_array_nonconst, arr_size);

	mu_end();
}

static int _test_bst_bigger_size() {
	mu_start();

	const int nums_array[] = { 200, 107, 44, 543, 89, 484, 11, 154 };
	int size = 8;
	BST bst = create_bst(nums_array, size);
	mu_check(bst.root != NULL);
	mu_check((bst.root)->value == 200);
	mu_check((bst.root)->left->value == 107); 
	mu_check((bst.root)->left->left->value == 44);
	mu_check((bst.root)->left->left->left->value == 11);
	mu_check((bst.root)->left->right->value == 154);
	mu_check((bst.root)->right->value == 543);
	mu_check((bst.root)->right->right == NULL);
	mu_check((bst.root)->right->left->value == 484);
	mu_check((bst.root)->left->left->right->value == 89);
	empty_bst(&bst);

	int nums_array_nonconst[] = { 200, 107, 44, 543, 89, 484, 11, 154 };
	size_t arr_size = sizeof(nums_array_nonconst) / sizeof(*nums_array_nonconst);
	_print_elements(nums_array_nonconst, arr_size);
	tree_sort_array(nums_array_nonconst, arr_size);
	_print_elements(nums_array_nonconst, arr_size);

	mu_end();
}

static int _test_big_root() {
	mu_start();
	
	const int nums_array[] = { 500, 17, 243, 94, 456, 32, 87 };
	int size = 7;
	BST bst = create_bst(nums_array, size);
	mu_check(bst.root != NULL);
	mu_check((bst.root)->value == 500);
	mu_check((bst.root)->left->value = 17); 
	mu_check((bst.root)->left->right->value == 243);
	mu_check((bst.root)->left->right->right->value == 456);
	mu_check((bst.root)->left->right->left->value == 94);
	mu_check((bst.root)->left->right->left->left->value == 32);
	mu_check((bst.root)->left->right->left->left->right->value == 87);
	mu_check((bst.root)->right == NULL);
	empty_bst(&bst);

	int nums_array_nonconst[] = { 500, 17, 243, 94, 456, 32, 87 };
	size_t arr_size = sizeof(nums_array_nonconst) / sizeof(*nums_array_nonconst);
	_print_elements(nums_array_nonconst, arr_size);
	tree_sort_array(nums_array_nonconst, arr_size);
	_print_elements(nums_array_nonconst, arr_size);

	mu_end();
}

static int _test_small_root() {
	mu_start();
	
	const int nums_array[] = { 5, 70, 24, 1265, 8 };
	int size = 5;
	BST bst = create_bst(nums_array, size);
	mu_check(bst.root != NULL);
	mu_check((bst.root)->value == 5);
	mu_check((bst.root)->left == NULL);
	mu_check((bst.root)->right->value == 70); 
	mu_check((bst.root)->right->left->value == 24);
	mu_check((bst.root)->right->right->value == 1265);
	mu_check((bst.root)->right->left->left->value == 8);
	mu_check((bst.root)->right->left->right == NULL);
	empty_bst(&bst);

	int nums_array_nonconst[] = { 5, 70, 24, 1265, 8 };
	size_t arr_size = sizeof(nums_array_nonconst) / sizeof(*nums_array_nonconst);
	_print_elements(nums_array_nonconst, arr_size);
	tree_sort_array(nums_array_nonconst, arr_size);
	_print_elements(nums_array_nonconst, arr_size);

	mu_end();
}

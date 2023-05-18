#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct dictionary {
	char str[100];
	unsigned long long vector;
} element;

typedef struct TreeNode {
	element key;
	struct TreeNode* left, * right;
} TreeNode;

TreeNode* search(TreeNode* node, element key) {
	if (node == NULL)
		return NULL;

	if (key.vector == node->key.vector)
		return node;
	else if (key.vector < node->key.vector)
		return search(node->left, key);
	else
		return search(node->right, key);
}

TreeNode* new_node(element item) {
	TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}

int compare_strings(const char* str1, const char* str2) {
	return strcmp(str1, str2);
}

TreeNode* insert_node(TreeNode* node, element key) {
	if (node == NULL)
		return new_node(key);

	int comparison = compare_strings(key.str, node->key.str);

	if (comparison < 0)
		node->left = insert_node(node->left, key);
	else if (comparison > 0)
		node->right = insert_node(node->right, key);

	return node;
}

void inorder(TreeNode* root) {
	if (root) {
		inorder(root->left);
		printf("[%s]", root->key.str);
		inorder(root->right);
	}
}

int main(void) {
	TreeNode* root = NULL;

	element s1, s2, s3, s4, s5, s6, s7, s8;

	strcpy(s1.str, "NETWORK");
	strcpy(s2.str, "DATA");
	strcpy(s3.str, "SYSTEM");
	strcpy(s4.str, "PROGRAM");
	strcpy(s5.str, "AI");
	strcpy(s6.str, "SOFTWARE");
	strcpy(s7.str, "DAUM");
	strcpy(s8.str, "SOUND");

	s1.vector = s2.vector = s3.vector = s4.vector = s5.vector = s6.vector = s7.vector = s8.vector = 0; // Assign vector values if needed

	root = insert_node(root, s1);
	root = insert_node(root, s2);
	root = insert_node(root, s3);
	root = insert_node(root, s4);
	root = insert_node(root, s5);
	root = insert_node(root, s6);
	root = insert_node(root, s7);
	root = insert_node(root, s8);

	printf("이진 탐색 트리 중위 순회 결과 \n");
	inorder(root);
	printf("\n\n");
	return 0;
}
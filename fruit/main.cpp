/**
 * @file  main.cpp
 * @brief test problem solutions
 *
 * @author  Changrui
 * @date    2018/11/28
 *
 * Copyright © 2018 ChangruiShao. All rights reserved.
 */

#include "tree.hpp"
#include "util.hpp"
#include "array.hpp"

#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::vector;
using std::endl;
using std::begin;
using std::end;

template <typename T, typename... Args>
void fruit_log(T s, Args... args) {
	cout << s << "\t";
	vector<std::string> var = {to_string(args)...};
	for (auto iter = begin(var); iter != end(var); iter++) {
		cout << *iter << " ";
	}
	cout << endl;
};
template <typename T>
void printArray(vector<T>& nums) {
	for (auto iter = begin(nums); iter < end(nums); iter++) {
		cout << *iter << "\t";
	}
	cout << endl;
}

int main(int argc, const char * argv[]) {

/**
 *          1
 *       /     \
 *      2       3
 *     / \     /
 *    4  5    6
 *        \  / \
 *         7 8  9
 * ----------------------
 *          1
 *       /     \
 *      0       1
 *     / \     /
 *    1  0    0
 *        \  / \
 *         0 1  0
 */
	TreeNode *root  = new TreeNode(1);
	TreeNode *node2 = new TreeNode(2);
	TreeNode *node3 = new TreeNode(3);
	TreeNode *node4 = new TreeNode(4);
	TreeNode *node5 = new TreeNode(5);
	TreeNode *node6 = new TreeNode(6);
	TreeNode *node7 = new TreeNode(7);
	TreeNode *node8 = new TreeNode(8);
	TreeNode *node9 = new TreeNode(9);

	root->left   = node2; root->right  = node3;
	node2->left  = node4; node2->right = node5;
	node3->left  = node6;
	node5->right = node7;
	node6->left  = node8; node6->right = node9;

	Solution s;
	s.root = root;
	//TreeNode *pResult = nullptr;
	
	// leetcode 102
	vector<vector<int>> result = s.levelOrderBottom(s.root);
	for (auto& level: result) {
		print_list(level);
	}
	
#if 0
	// postorder
	result = s.postorderTraversal(s.root);
	print_list(result);
	result = s.recursive_postorderTraversal(s.root);
	print_list(result);
	
	// inorder
	result = s.inorderTraversal(root);
	print_list(result);
	result = s.recursive_inorderTraversal(root);
	print_list(result);
	
	//preorder
	result = s.preorderTraversal(root);
	print_list(result);
	result = s.recursive_preorderTraversal(root);
	print_list(result);

	// leetcode 814: binary tree pruning
	pResult = s.recursive_pruneTree(root);
	result = s.preorderTraversal(pResult);
	print_list(result);
	pResult = s.pruneTree(root);
	result = s.preorderTraversal(pResult);
	print_list(result);
#endif
	
	delete root;
	delete node2;
	delete node3;
	delete node4;
	delete node5;
	delete node6;
	delete node7;
	delete node8;
	delete node9;
	
	return 0;
}

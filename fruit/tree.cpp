/**
 * @file	tree.cpp
 * @brief	All functions are solutions of leetcode problems.
 *
 * @author	Changrui
 * @date	2018/11/28
 *
 * Copyright © 2018 ChangruiShao. All rights reserved.
 */

#include "tree.hpp"

#include <stack>

using namespace std;

/**
 * @brief   non-recursive postorder traversal
 * @param
 *  root    root node of binary tree
 * @return  vector of tree member
 */
vector<int> Solution::postorderTraversal(TreeNode *root)
{
	vector<int> result{};
	if(root == nullptr)
        return result;

	TreeNode *pNode = root;
	TreeNode *pFlag = nullptr;
	stack<TreeNode *> sNode;

	while(pNode != nullptr || !sNode.empty()) {
		while(pNode != nullptr) {
			sNode.push(pNode);
			pNode = pNode->left;
		}
		pNode = sNode.top();
		if(pNode->right == nullptr || pNode->right == pFlag) {
			result.push_back(pNode->val);
			sNode.pop();
			pFlag = pNode;
            pNode = nullptr;
		} else {
			pNode = pNode->right;
		}
	}

	return result;
}

/**
 * @brief   recursive implementation of postorder traversal
 * @param
 *  root    root node of binary tree
 */
void postorderTraversalHelper(TreeNode *root, vector<int>& result)
{
    if(root == nullptr) {
        return;
    }
    if(root->left) {
        postorderTraversalHelper(root->left, result);
    }
    if(root->right) {
        postorderTraversalHelper(root->right, result);
    }
    result.push_back(root->val);
}

vector<int> Solution::recursive_postorderTraversal(TreeNode *root)
{
	vector<int> result{};
    postorderTraversalHelper(root, result);
	
	return result;
}

/**
 * @brief	non-recursive implementation of inorder traversal
 * @param
 *  root	root node of binary tree
 */
vector<int> Solution::inorderTraversal(TreeNode *root)
{
	vector<int> result{};
	if(root == nullptr)
		return result;
	
	TreeNode *pNode = root;
	stack<TreeNode *> sNode;
	
	while (pNode != nullptr || !sNode.empty()) {
		while (pNode != nullptr) {
			sNode.push(pNode);
			pNode = pNode->left;
		}
		pNode = sNode.top();
		result.push_back(pNode->val);
		sNode.pop();
		
		if(pNode->right == nullptr) {
			pNode = nullptr;
		} else {
			pNode = pNode->right;
		}
	}
	return result;
}

/**
 * @brief	recursive inorder traversal
 */
void inorderTraversalHelper(TreeNode *root, vector<int>& result)
{
	if(root == nullptr)
		return;
	
	if(root->left) {
		inorderTraversalHelper(root->left, result);
	}
	result.push_back(root->val);
	if(root->right) {
		inorderTraversalHelper(root->right, result);
	}
}

vector<int> Solution::recursive_inorderTraversal(TreeNode *root)
{
	vector<int> result{};
	inorderTraversalHelper(root, result);
	
	return result;
}

/**
 * @brief	non-recursive preorder traversal
 */
vector<int> Solution::preorderTraversal(TreeNode *root)
{
	vector<int> result{};
	if(root == nullptr)
		return result;
	
	TreeNode *pNode = root;
	stack<TreeNode *> sNode;
	sNode.push(pNode);
	
	while (!sNode.empty()) {
		pNode = sNode.top();
		result.push_back(pNode->val);
		sNode.pop();
		
		if(pNode->right) {
			sNode.push(pNode->right);
		}
		if(pNode->left) {
			sNode.push(pNode->left);
		}
	}
	
	return result;
}

/**
 * @brief	recursive preorder traversal
 */
void preorderTraversalHelper(TreeNode *root, vector<int>& result)
{
	if(root == nullptr)
		return;
	
	result.push_back(root->val);
	if(root->left) {
		preorderTraversalHelper(root->left, result);
	}
	if(root->right) {
		preorderTraversalHelper(root->right, result);
	}
}

vector<int> Solution::recursive_preorderTraversal(TreeNode *root)
{
	vector<int> result{};
	preorderTraversalHelper(root, result);
	
	return result;
}

/**
 * @brief	Leetcode 814: Binary Tree Pruning
 * 	We are given the head node root of a binary tree, where additionally e
 * 	very node's value is either a 0 or a 1. Return the same tree where every
 *	subtree (of the given tree) not containing a 1 has been removed.
 *	(Recall that the subtree of a node X is X, plus every node that is a descendant of X.)
 *
 * @param
 * 	root	head node root of a binary tree
 * @return	pointer to a TreeNode node.
 */
TreeNode* Solution::pruneTree(TreeNode *root)
{
    TreeNode *result = nullptr;
//	if(root == nullptr)
//		return result;
//	
//	TreeNode *pNode = root;
//	TreeNode *pFlag = nullptr;
//	stack<TreeNode *> sNode;
//	
//	while (pNode != nullptr || !sNode.empty()) {
//		while (pNode != nullptr) {
//			sNode.push(pNode);
//			pNode = pNode->left;
//		}
//		pNode = sNode.top();
//		if(pNode->right == nullptr) {
//			if(pNode->val == 0) {
//				pNode->val = -1;
//			}
//			pNode = nullptr;
//			sNode.pop();
////			pFlag = pNode;
//		} else {
//			pNode = pNode->right;
//		}
//	}

	return result;
}

/**
 * @brief	Leetcode 814: Binary Tree Pruning
 *  recursion method, Accepted Solutions Runtime Distribution 33%
 */
TreeNode* Solution::recursive_pruneTree(TreeNode *root)
{
	if(root == nullptr)
		return nullptr;
	root->left = recursive_pruneTree(root->left);
	root->right = recursive_pruneTree(root->right);
	if(root->left == nullptr && root->right == nullptr && root->val == 0)
		return nullptr;
	
	return root;
}

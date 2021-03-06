/**
 * @file	tree.cpp
 * @brief	All function implementations related to tree
 *
 * @author	Changrui
 * @date	2018/11/28
 *
 * Copyright © 2018 ChangruiShao. All rights reserved.
 */

#include "tree.hpp"

#include <limits.h>
#include <stdlib.h>
#include <stdint.h>

#include <stack>
#include <list>
#include <queue>
#include <algorithm>

using std::stack;
using std::list;
using std::queue;
using std::pair;
using std::move;

/**
 * @brief   non-recursive postorder traversal
 * @param
 *  root    root node of binary tree
 * @return  vector of tree member
 *
 * -------------------------------------------
 * Accepted Solutions Runtime Distribution beats 100%
 */
vector<int> postorderTraversal(TreeNode *root)
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
static void postorderTraversalHelper(TreeNode *root, vector<int>& result)
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

vector<int> postorderTraversal2(TreeNode *root)
{
	vector<int> result{};
    postorderTraversalHelper(root, result);
	
	return result;
}

/**
 * @brief	non-recursive implementation of inorder traversal
 * @param
 *  root	root node of binary tree
 *
 * -------------------------------------------
 * Accepted Solutions Runtime Distribution beats 100%
 */
vector<int> inorderTraversal(TreeNode* root)
{
	vector<int> result{};
	if(root == nullptr)
		return result;
	
	TreeNode* pNode = root;
	stack<TreeNode*> sNode;
	
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
static void inorderTraversalHelper(TreeNode* root, vector<int>& result)
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

vector<int> inorderTraversal2(TreeNode* root)
{
	vector<int> result{};
	inorderTraversalHelper(root, result);
	
	return result;
}

/**
 * @brief	non-recursive preorder traversal
 *
 * --------------------------------------------
 * Accepted Solutions Runtime Distribution beats 100%
 */
vector<int> preorderTraversal(TreeNode* root)
{
	vector<int> result{};
	if(root == nullptr)
		return result;
	
	TreeNode* pNode = root;
	stack<TreeNode*> sNode;
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
static void preorderTraversalHelper(TreeNode* root, vector<int>& result)
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

vector<int> preorderTraversal2(TreeNode* root)
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
 *
 * --------------------------------------------
 * Accepted Solutions Runtime Distribution beats 100%
 */
TreeNode* pruneTree(TreeNode* root)
{
    TreeNode* result = root;
	if(root == nullptr)
		return result;
	
	TreeNode* pNode = root;
	TreeNode* pFlag = nullptr;
	stack<TreeNode*> sNode;
	
	// assign -1 to the root node of subtree not containing a 1
	// postorder traversal
	while (pNode != nullptr || !sNode.empty()) {
		while (pNode != nullptr) {
			sNode.push(pNode);
			pNode = pNode->left;
		}
		pNode = sNode.top();
		if (pNode->right == nullptr || pNode->right == pFlag) {
			if((pNode->left == nullptr || pNode->left->val == -1) &&
			   (pNode->right == nullptr || pNode->right->val == -1) &&
			   pNode->val == 0) {
				pNode->val = -1;
			}
			pFlag = pNode;
			pNode = nullptr;
			sNode.pop();
		} else {
			pNode = pNode->right;
		}
	}

	// assign nullptr to the node whose value is -1
	// preorder traversal
	if (root->val == -1) {
		return nullptr;
	}
	sNode.push(root);
	while (!sNode.empty()) {
		root = sNode.top();
		sNode.pop();
		if (root->right != nullptr) {
			if (root->right->val == -1) {
				root->right = nullptr;
			} else {
				sNode.push(root->right);
			}
		}
		if (root->left != nullptr) {
			if (root->left->val == -1) {
				root->left = nullptr;
			} else {
				sNode.push(root->left);
			}
		}
	}
	return result;
}

/**
 * @brief	Leetcode 814: Binary Tree Pruning
 *
 * -------------------------------------------
 * Accepted Solutions Runtime Distribution beats 33%
 */
TreeNode* pruneTree2(TreeNode* root)
{
	if(root == nullptr)
		return nullptr;
	root->left = pruneTree2(root->left);
	root->right = pruneTree2(root->right);
	if(root->left == nullptr && root->right == nullptr && root->val == 0)
		return nullptr;
	
	return root;
}

/**
 * @brief	Leetcode 102: Binary Tree Level Order Traversal
 *
 *  this problem can be solved in BFS and DFS method.
 *  this solution is implementated by BFS.
 * --------------------------------------------------------
 * Accepted Solutions Runtime Distribution beats 99%
 */
vector<vector<int>> levelOrder(TreeNode* root)
{
	vector<vector<int>> result;
	if (root == nullptr) {
		return result;
	}
	vector<int>	level;

	queue<TreeNode*> qLevel1;
	qLevel1.push(root);
	while (true) {
		queue<TreeNode*> qLevel2;
		while (!qLevel1.empty()) {
			TreeNode* node = qLevel1.front();
			qLevel1.pop();
			level.push_back(node->val);
			if (node->left) {
				qLevel2.push(node->left);
			}
			if (node->right) {
				qLevel2.push(node->right);
			}
		}
		result.push_back(level);
		level.clear();
		if (qLevel2.empty()) {
			break;
		}
		qLevel1 = move(qLevel2);
	}

	return result;
}

/**
 * @brief	Leetcode 107: Binary Tree Level Order Traversal II
 *
 * -----------------------------------------------------------
 * Accepted Solutions Runtime Distribution beats 99%
 */
vector<vector<int>> levelOrderBottom(TreeNode* root)
{
	vector<vector<int>> result;
	if (root == nullptr) {
		return result;
	}
	queue<TreeNode*> qLevel;
	qLevel.push(root);
	
	while (!qLevel.empty()) {
		vector<int> level;
		size_t qSize = qLevel.size();
		for (uint32_t i = 0; i < qSize; i++) {
			TreeNode *node = qLevel.front();
			qLevel.pop();
			level.push_back(node->val);
			if (node->left) {
				qLevel.push(node->left);
			}
			if (node->right) {
				qLevel.push(node->right);
			}
		}
		result.push_back(level);
	}
	std::reverse(result.begin(), result.end());
	
	return result;
}

/**
 * @brief	Leetcode 310: Minimum Height Trees
 *
 * this problem is related to BFS and graph.
 * the solution below is by graph theory.
 * --------------------------------------------
 * Accepted Solutions Runtime Distribution beats 83%
 */
vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges)
{
	// adjacent node list
	vector<vector<int>> adjacencyList(n);
	for (int i = 0; i < n; ++i) {
		adjacencyList[i] = vector<int>();
	}
	// get node degree
	vector<int> degree(n, 0);
	for (auto const& edge : edges) {
		adjacencyList[edge.first].push_back(edge.second);
		adjacencyList[edge.second].push_back(edge.first);
		++degree[edge.first];
		++degree[edge.second];
	}
	
	vector<int> leafNodes;
	for (int i = 0; i < n; ++i) {
		if (degree[i] == 1) {
			leafNodes.push_back(i);
			degree[i] = 0;
		}
	}
	
	int numNodes = n;
	while (numNodes > 2) {
		vector<int> newLeafNodes;
		numNodes -= leafNodes.size();
		for (auto node : leafNodes) {
			for (auto neigh : adjacencyList[node]) {
				--degree[neigh];
				if (degree[neigh] == 1) {
					newLeafNodes.push_back(neigh);
				}
			}
		}
		leafNodes = move(newLeafNodes);
	}
	
	if (n == 1) {
		leafNodes.push_back(0);
	}
	return leafNodes;
}
/**
 * @brief	Leetcode 310: Minimum Height Trees
 *
 * --------------------------------------------
 * Accepted Solutions Runtime Distribution beats 83%
 */
vector<int> findMinHeightTrees2(int n, vector<pair<int, int>>& edges)
{
	if (n < 2) return {0};

	vector<int> indegres(n, 0);
	vector<vector<int>> graph(n);

	for (auto& p: edges) {
		graph[p.first].push_back(p.second);
		graph[p.second].push_back(p.first);
		indegres[p.first]++;
		indegres[p.second]++;
	}

	queue<int> que;
	for (int i = 0; i < n; i++)
	if (indegres[i] == 1)
	que.push(i);


	while (n > 2) {
		size_t k = que.size();
		n -= k;
		
		for (int i = 0; i < k; i++) {
			auto u = que.front(); que.pop();
			
			for (auto v: graph[u])
				if (--indegres[v] == 1)
					que.push(v);
					}
	}

	vector<int> res;
	while (!que.empty()) {
		res.push_back(que.front());
		que.pop();
	}

	return res;
}

/**
 * @brief   Leetcode 105: Construct Binary Tree from Preorder and Inorder Traversal
 *  If we use an unordered_map to store element-to-index map of inorder array, we can
 *  replace for loop statements and improve beat rate up to 98.69%.
 *
 * --------------------------------------------
 * Accepted Solutions Runtime Distribution beats 80.37%
 */
static TreeNode* buildTreeHelper(vector<int>& preorder,
                                 int pStart,
                                 vector<int>& inorder,
                                 int iStart, int iEnd)
{
    if(pStart > preorder.size()-1 || iStart > iEnd) {
        return nullptr;
    }
    int value = preorder[pStart];
    int iHead = 0;
    for(int i = iStart; i <= iEnd; ++i) {
        if(value == inorder[i]) {
            iHead = i;
            break;
        }
    }

    TreeNode* head = new TreeNode(value);
    head->left = buildTreeHelper(preorder, pStart+1, inorder, iStart, iHead-1);
    head->right = buildTreeHelper(preorder, pStart+iHead-iStart+1, inorder, iHead+1, iEnd);

    return head;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    return buildTreeHelper(preorder, 0, inorder, 0, inorder.size()-1);
}

/**
 * @brief	Leetcode 106: Construct Binary Tree from Inorder and Postorder Traversal
 *
 * --------------------------------------------
 * Accepted Solutions Runtime Distribution beats 28%
 */
static TreeNode* buildTreeIIHelper(vector<int>& inorder,
								 int iStart, int iEnd,
								 vector<int>& postorder,
								 int pEnd)
{
	if(pEnd < 0 || iStart > iEnd) {
		return nullptr;
	}
	int value = postorder[pEnd];
	int iRoot = 0;
	for(int i = iStart; i <= iEnd; ++i) {
		if(value == inorder[i]) {
			iRoot = i;
			break;
		}
	}
	TreeNode* root = new TreeNode(value);
	root->left = buildTreeIIHelper(inorder, iStart, iRoot-1, postorder, pEnd-iEnd+iRoot-1);
	root->right = buildTreeIIHelper(inorder, iRoot+1, iEnd, postorder, pEnd-1);
	
	return root;
}

TreeNode* buildTreeII(vector<int>& inorder, vector<int>& postorder) {
	return buildTreeIIHelper(inorder, 0, inorder.size()-1, postorder, postorder.size()-1);
}

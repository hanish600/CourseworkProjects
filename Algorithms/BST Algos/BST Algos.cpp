#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <time.h>
#include <math.h>
#include <string>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

struct BinaryTreeNode {
	int data;
	BinaryTreeNode* left;
	BinaryTreeNode* right;

	// Below data members used only for some of the problems
	BinaryTreeNode* parent;
	BinaryTreeNode* next;
	int count;

	BinaryTreeNode(int d)
		: data(d),
		left(nullptr),
		right(nullptr),
		next(nullptr),
		parent(nullptr),
		count(0) {}
};

class BinaryTree {
public:
	BinaryTreeNode* root;

	BinaryTree() { root = nullptr; }

	BinaryTree(int node_data) { root = new BinaryTreeNode(node_data); }

	BinaryTree(vector<int>& v) {
		root = nullptr;
		for (int x : v) {
			Insert(x);
		}
	}

	// For normal BT level by level insertion
	void InsertBT(int node_data) {
		queue<BinaryTreeNode*> tempQueue;
		BinaryTreeNode* temp = root;
		tempQueue.push(temp);

		while (!tempQueue.empty()) {
			temp = tempQueue.front();
			tempQueue.pop();

			if (temp->left == nullptr) {
				temp->left = new BinaryTreeNode(node_data);
				break;
			}
			else {
				tempQueue.push(temp->left);
			}

			if (temp->right == nullptr) {
				temp->right = new BinaryTreeNode(node_data);
				break;
			}
			else {
				tempQueue.push(temp->right);
			}
		}
	}

	// For BST insertion
	void Insert(int node_data) {
		BinaryTreeNode* new_node = new BinaryTreeNode(node_data);
		if (root == nullptr) {
			root = new_node;
		}
		else {
			BinaryTreeNode* parent = nullptr;
			BinaryTreeNode* temp_node = root;
			while (temp_node != nullptr) {
				parent = temp_node;
				if (node_data <= temp_node->data) {
					temp_node = temp_node->left;
				}
				else {
					temp_node = temp_node->right;
				}
			}
			if (node_data <= parent->data) {
				parent->left = new_node;
			}
			else {
				parent->right = new_node;
			}
		}
	}

	BinaryTreeNode* FindInBstRec(BinaryTreeNode* node, int node_data) {
		if (node == nullptr) return nullptr;

		if (node->data == node_data) {
			return node;
		}
		else if (node->data > node_data) {
			return FindInBstRec(node->left, node_data);
		}
		else {
			return FindInBstRec(node->right, node_data);
		}
	}

	BinaryTreeNode* FindInBst(int node_data) {
		return FindInBstRec(root, node_data);
	}

	void PopulateParentsRec(BinaryTreeNode* node, BinaryTreeNode* parent) {
		if (node != nullptr) {
			node->parent = parent;
			PopulateParentsRec(node->left, node);
			PopulateParentsRec(node->right, node);
		}
	}

	void PopulateParents() { PopulateParentsRec(root, nullptr); }

	int GetSubTreeNodeCount(BinaryTreeNode* node) {
		if (node == nullptr) {
			return 0;
		}
		else {
			return 1 + GetSubTreeNodeCount(node->left) + GetSubTreeNodeCount(node->right);
		}
	}

	void PopulateCountRec(BinaryTreeNode* node) {
		if (node != nullptr) {
			node->count = GetSubTreeNodeCount(node);
			PopulateCountRec(node->left);
			PopulateCountRec(node->right);
		}
	}

	void PopulateCount() {
		PopulateCountRec(this->root);
	}

	BinaryTreeNode* GetTreeDeepCopyRec(BinaryTreeNode* node) {
		if (node != nullptr) {
			BinaryTreeNode* new_node = new BinaryTreeNode(node->data);
			new_node->left = GetTreeDeepCopyRec(node->left);
			new_node->right = GetTreeDeepCopyRec(node->right);
			return new_node;
		}
		else {
			return nullptr;
		}
	}

	BinaryTree* GetTreeDeepCopy() {
		if (this->root == nullptr) {
			return nullptr;
		}
		else {
			BinaryTree* tree_copy = new BinaryTree();
			tree_copy->root = GetTreeDeepCopyRec(root);
			return tree_copy;
		}
	}

	BinaryTreeNode* FindInBTRec(BinaryTreeNode* node, int node_data) {
		if (node == nullptr) {
			return nullptr;
		}

		if (node->data == node_data) {
			return node;
		}

		BinaryTreeNode* left_node = FindInBTRec(node->left, node_data);
		if (left_node != nullptr) {
			return left_node;
		}

		BinaryTreeNode* right_node = FindInBTRec(node->right, node_data);
		return right_node;
	}

	BinaryTreeNode* FindInBT(int node_data) {
		return FindInBTRec(this->root, node_data);
	}
};

void InorderIterative(BinaryTreeNode* root) {
	stack<BinaryTreeNode*> address;
	if (!root) { cout << "nullptr"; }
	while (!address.empty() || root)
	{
		if (root)
		{
			address.push(root);
			root = root->left;
		}
		else {
			root = address.top();
			address.pop();
			cout << root->data << ", ";
			root = root->right;
		}
	}
}

int main()
{
	vector<int> items = { 300, 200, 125, 100, 75, 60, 50, 35, 25, 12 };
	BinaryTree A(items);
	InorderIterative(A.root);
	return 0;
}
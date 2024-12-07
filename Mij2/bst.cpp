#include <iostream>
using namespace std;

class BST {
private:
	struct Node {
		int data;
		Node* left;
		Node* right;
	};
	Node* root;
	void addLeafPrivate(int data, Node* ptr){
		if (root == NULL) {
			root=createLeaf(data);
		}
		else if (data < ptr->data) {
			if (left != NULL) {
				addLeafPrivate(data, ptr->left);
			}
			else {
				ptr->left = createLeaf(data);
			}
		}
		else if (data > ptr->data) {
			if (right != NULL) {
				addLeafPrivate(data, ptr->right);
			}
			else {
				ptr->right = createLeaf(data);
			}
		}
		else
			cout << "The data has already been added";
	}

	void printInOrderPrivate(Node* ptr) {
		if (root != NULL) {
			if (left != NULL) {
				printInOrderPrivate(ptr->left);
			}
			cout << "The data " << ptr->data ;

			if (right != NULL) {
				printInOrderPrivate(ptr->right);
			}
			else
				cout << "The tree is empty";
		}
	}
	Node* removeNodePrivate(int data, Node* ptr) {
		if (root == NULL) {
			cout << "Value " << data << " not found";
			return root;
		}
		if (data < ptr->data) {
			removeNodePrivate(data, ptr->left);
		}
		else if (data > ptr->data) {
			removeNodePrivate(data, ptr->right);
		}
		else {
			if (ptr->left == NULL) {
				Node* temp = ptr->right;
				delete ptr;
				return temp;
			}
			else if (ptr->right == NULL) {
				Node* temp = ptr->left;
				delete ptr;
				return temp;
			}
		}
	}
public:
	BST() {
		root = NULL;
	}

	Node* createLeaf(int data) {
		Node* n = new Node;
		n->data = data;
		n->left = NULL;
		n->right = NULL;

		return n;
	}
	void addLeaf(int data) {
		addLeafPrivate(data, root);
	}
	void printInOrder() {
		printInOrderPrivate(root);
	}
	void removeNode(int data) {
		removeNodePrivate(data, root);
	}
};




int main() {
	int tree[16] = { 50,76,21,4,32,64,15,52,14,100,83,2,3,70,87,80 };
	BSD myTree;
	cout << "My tree before: " << endl;
	myTree.printInOrder();
	for (int i = 0; i < 16;i++) {
		myTree.addLeaf(tree[i]);
	}
	cout << "The tree after: ";
	myTree.printInOrder();

	return 0;
}

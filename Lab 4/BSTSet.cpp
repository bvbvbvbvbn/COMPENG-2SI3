#include "BSTSet.h"
#include <iostream>
#include <vector>
using namespace std;

BSTSet::BSTSet() {
	root = NULL;
}

BSTSet::BSTSet(const std::vector<int> &input) {

	if (input.size() == 0) { //if the size is 0
		root = NULL; //empty tree
		return; //exits the constructor
	}

	root = new TNode(input[0], NULL, NULL); //letting root be a new TNode with paramaters of the first input, left, and right
	TNode *temp = root; //creating temporary TNode that points to root

	if (input.size() == 1) { //if there is already only one input
		return; //exit
	}

	for (int i = 1; i < input.size(); i++) { //iterate from i as long as i is less than the input size
		while (1) { //infinite loop until can exit

			if (input[i] < temp->element) { //if the number to be added is smaller than the current node
				if (temp->left == NULL) { //if the left node is empty/doesnt exist
					temp->left = new TNode(input[i], NULL, NULL); //created a new TNode for the left
					break; // breaks out of the while loop to the next i
				} else {
					temp = temp->left; //if the node does exist (left) then set temp to point to left
				}
			}

			else if (input[i] > temp->element) { //if the number to be added is greater than the current node
				if (temp->right == NULL) { //if the right node is empty/ does not exist
					temp->right = new TNode(input[i], NULL, NULL); //create a new TNode for the right
					break; // break out of the while loop
				} else {
					temp = temp->right; //if right node does exist, set temp to point to right
				}
			}

			else { // value is already in the tree
				break;
			}

		}
		temp = root;
	}

}

BSTSet::~BSTSet() {
	// TODO
}

bool BSTSet::isIn(int v) {
	if (root == NULL) { //if the root is empty
		return false; //return false
	}

	TNode *temp = root; //create temporary TNode pointing to root
	while (1) { //infinte loop
		if (v == temp->element) { //if v is a value of the current node, return True
			return true;
		} else if (v > temp->element) { //if value is greater than the current node element
			if (temp->right != NULL) { //if right is not NULL
				temp = temp->right; //set temp to the right
			} else {
				return false;
			}
		} else if (v < temp->element) { //if the value is less than the current node element
			if (temp->left != NULL) { //if the left is not NULL
				temp = temp->left; //set temp to point to left
			} else {
				return false;
			}
		}
	}
}

void BSTSet::add(int v) {
	if (root == NULL) {
		root = new TNode(v, NULL, NULL);
	}

	if (isIn(v)) { //if the value is already in the set
		return;
	} else {
		TNode *temp = root; //create temp TNode pointing to root
		while (1) { //infinite loop
			if (v > temp->element) { //if the value is greater than the current node element
				if (temp->right != NULL) { //if right is not NULL
					temp = temp->right; //set temp to the right
				} else {
					temp->right = new TNode(v, NULL, NULL); //if right does not exist, create it
					return;
				}
			} else if (v < temp->element) { //if value is less than the current node element
				if (temp->left != NULL) { //if left is not NULL
					temp = temp->left; //set temp to point to the left
				} else {
					temp->left = new TNode(v, NULL, NULL); //create a new TNode
					return;
				}
			}
		}
	}
}

bool BSTSet::remove(int v) {
	if (!isIn(v)) //if v is not in the set
		return false;

	TNode *temp = root;
	TNode *removal;

	while (1) {
		if (v > temp->element) { // v is greater than the current element
			if (v == temp->right->element) { //if the value is the element it is currently on
				removal = temp->right; //let removal be the current element
				if (removal->right == NULL && removal->left == NULL) { //if the node to the left and right points to NULL
					temp->right = NULL; //set the node to NULL
				} else if (removal->right != NULL && removal->left == NULL) { //if right is not pointing to NULL but left is
					temp->right = removal->right;  //let removal point right
				} else if (removal->right == NULL && removal->left != NULL) { //if right is pointing to NULL but left is not
					temp->right = removal->left; //let removal point left
				} else { // two children
					TNode *tempRemoval = removal->right; //create a new temporary TNode
					int minVal;
					while (tempRemoval->left != NULL) { //while left is not NULL
						tempRemoval = tempRemoval->left; //let tempRemoval point left
					}
					minVal = tempRemoval->element; //minimum value is the current node
					remove(minVal); //remove the minimum value
					temp->right->element = minVal; //
				}
				return true;
			}
			temp = temp->right;
		} else if (v < temp->element) {
			if (v == temp->left->element) {
				removal = temp->left;
				if (removal->right == NULL && removal->left == NULL) {
					temp->left = NULL;
				} else if (removal->right != NULL && removal->left == NULL) {
					temp->left = removal->right;
				} else if (removal->right == NULL && removal->left != NULL) {
					temp->left = removal->left;
				} else { // two children
					TNode *tempRemoval = removal->right; //set tempRemoval to point to the right
					int minVal;
					while (tempRemoval->left != NULL) { //iterate until left is NULL
						tempRemoval = tempRemoval->left; //remove that node
					}
					minVal = tempRemoval->element; //store removed node in minVal
					remove(minVal); //remove it
					temp->left->element = minVal; //change element to new one
				}
				return true;
			}
			temp = temp->left;
		} else if (v == root->element) { //if v is the root
			if (root->right == NULL && root->left == NULL) { //if the root pointing to left and right are NULL
				root = NULL; //set the root as NULL
			} else if (root->right != NULL && root->left == NULL) { //if the root pointing to right is not NULL and root pointing left is NULL
				root = root->right; //set the root to point to the right
			} else if (root->right == NULL && root->left != NULL) { //if the root pointing right is NULL and left is not
				root = root->left; //set root to point to left
			} else {
				TNode *tempRemoval = root->right; //
				int minVal;
				while (tempRemoval->left != NULL) {
					tempRemoval = tempRemoval->left;
				}
				minVal = tempRemoval->element;
				remove(minVal);
				root->element = minVal;
			}
			return true;
		}
	}
	return true;

}

void BSTSet::rUnion(const TNode *n) {

	if (n == NULL) { //if root of s is NULL
		return;
	}

	rUnion(n->left); //root of s points to left
	add(n->element); //add the root of s to the current node
	rUnion(n->right); //root of s points to right

}

void BSTSet::Union(const BSTSet &s) {

	if (s.root == NULL) { //if the root of s is NULL
		return;
	} else if (root == NULL) { //if root is NULL
		root = s.root; //original set root becomes the s set root
		return;
	}

	rUnion(s.root);

}

void BSTSet::rIntersection(const TNode *n, const BSTSet &s) {
	if (n == NULL) { //if root of s is NULL
		return;
	}

	BSTSet set = BSTSet(); //creating empty set
	set.root = s.root; //root of s becomes root of set

	rIntersection(n->left, set); //
	if (!set.isIn(n->element)) { //if element is not in the set
		remove(n->element); //remove the element
	}
	rIntersection(n->right, set);

}

void BSTSet::intersection(const BSTSet &s) {
	BSTSet set = BSTSet();
	set = s;

	if (s.root == NULL) { //if root of s is NULL
		root = NULL; //let the root be NULL
		return;
	} else if (root == NULL) { //if root is already NULL
		return;
	}

	rIntersection(root, set);
}

void BSTSet::rDifference(const TNode *n, const BSTSet &s) {
	if (n == NULL) { //if n is NULL
		return;
	}

	BSTSet set = BSTSet(); //create empty set
	set.root = s.root; //let root of s become root of set

	rDifference(n->left, set); //moves left until the last element
	if (set.isIn(n->element)) { //if element is in the set
		remove(n->element); //remove it
	}
	rDifference(n->right, set); //moves to the right until last element
	if (set.isIn(n->element)) { //if element is in set
		remove(n->element); //remove it

	}

}

void BSTSet::difference(const BSTSet &s) {
	BSTSet set = BSTSet(); //empty set
	set = s;

	if (s.root == NULL || root == NULL) { //if the root of s is empty
		return;
	}

	rDifference(root, set);
}

int BSTSet::rSize(const TNode *n, int size) {

	if (n == NULL) { //if root of s is NULL
		return 0;
	}
	if (n->left == NULL && n->right == NULL) { //if right and left are both pointing to NULL
		return 1;
	}

	size += rSize(n->left, 1); //increase size if you can keep going left
	size += rSize(n->right, 1); //increase size if you can keep going right

	return size;
}

int BSTSet::size() {

	if (root == NULL) { //if root is NULL
		return 0;
	}

	return rSize(root, 1); //call recursion function and change values everytime
}

int BSTSet::rHeight(const TNode *n, int maxHeight, int heightt) {

	if (n == NULL) { //if root of s is NULL
		return maxHeight; //return the max height
	}

	heightt++; //iterate heightt
	if (heightt > maxHeight) { //if the height is greater than the max height
		maxHeight = heightt; //make that equal that
	}

	maxHeight = rHeight(n->left, maxHeight, heightt); //move left and return the max height and heightt
	maxHeight = rHeight(n->right, maxHeight, heightt);
	return maxHeight; //return the max height
}

int BSTSet::height() {

	if (root == NULL) {
		return -1; //if root is NULL height is -1
	}

	return rHeight(root, 0, -1);

}

// create and use class MyStack
void BSTSet::printNonRec() {
	// TODO
	cout << "-2"; //change this after completing this function
}

// Do not modify following provided methods

void BSTSet::printBSTSet() {
	if (root == NULL)
		std::cout << "";
	else {
		printBSTSet(root);
	}
}

void BSTSet::printBSTSet(TNode *t) {
	if (t != NULL) {
		printBSTSet(t->left);
		std::cout << t->element << ",";
		printBSTSet(t->right);
	}
}

#pragma once

//binary search tree template file
#include <iostream>
#include <vector>

//node template
template <class T>
struct bstNode {
	T data;
	bstNode<T>* left;
	bstNode<T>* right; 
	bstNode<T>* root;
	int freq = 0;
};

//class template
template <class T>
class bst
{
	public:
		bst();
		~bst();
		bool Insert(T data);
		bool Remove(T data);
		bool ElementExists(T data);
		T* Find(T data);
		int getFrequency(T data);
		std::vector<T> ToVector();
		std::vector<T> ToVector(std::vector<T> vect);
		bool Empty();
		int Length = 0;
	protected:
		bstNode<T>* root = nullptr;
		bool Insert(bstNode<T>*& node, T data);
		bool Insert(bstNode<T>* from, bstNode<T>* to);
		T* Find(bstNode<T>* node, T data);
		bstNode<T>* findNode(T data);
		bstNode<T>* findNode(bstNode<T>* node, T data);
		bstNode<T>* findParent(T data);
		bstNode<T>* findParent(bstNode<T>* node, T data);
		void addToVector(std::vector<T>& vect, bstNode<T>* node);
		bstNode<T>* findLeastNode(bstNode<T>* start);
};

//constructor
template <class T>
bst<T>::bst() {
	root = nullptr;
}

//destructor
template <class T>
bst<T>::~bst() {
	//not yet
}

//starts recursion loop for insertion;
template <class T>
bool bst<T>::Insert(T data) {
	if (root != nullptr) {
		//if there is a root
		if (data.compare((root->data)) < 0) {
			return Insert(root->left, data);
		}
		else if (data.compare((root->data)) > 0) {
			return Insert(root->right, data);
		}
		else if (data.compare((root->data)) == 0) {
			return root->freq++;
		}
		else {
			std::cout << "BST: Data compare failed! - Input" << std::endl;
			return false;
		}
	}
	else if (root == nullptr) {
		//instatiate first node with data
		root = new bstNode<T>;
 		root->data = data;
		root->left = nullptr;
		root->right = nullptr;
		root->freq++;
		root->root = root;
		Length++;
		return true;
	}
}

//recursively go through the rest of the tree
template <class T>
bool bst<T>::Insert(bstNode<T>*& node, T data) {
	if (node != nullptr) {
		//if there is a node
		if (data.compare((node->data)) < 0) {
			return Insert(node->left, data);
		}
		else if (data.compare((node->data)) > 0) {
			return Insert(node->right, data);
		}
		else if (data.compare((node->data)) == 0) {
			return node->freq++;
		}
		else {
			std::cout << "BST: Data compare failed! - Insert" << std::endl;
			return false;
		}
	}
	else if (node == nullptr) {
		//instatiate new node with data
		node = new bstNode<T>;
		node->data = data;
		node->left = nullptr;
		node->right = nullptr;
		node->freq++;
		node->root = root;
		Length++;
		return true;
	}
}

//overloaded for recursion
template <class T>
bool bst<T>::Insert(bstNode<T>* from, bstNode<T>* to) {
	if (from != nullptr) {
		//if there is a root
		if (to->data.compare((from->data)) < 0) {
			return Insert(from->left, to);
		}
		else if (to->data.compare((from->data)) > 0) {
			return Insert(from->right, to);
		}
		else if (to->data.compare((from->data)) == 0) {
			return from->freq++;
		}
		else {
			std::cout << "BST: Data compare failed! - Insert" << std::endl;
			return false;
		}
	}
	else if (from == nullptr) {
		//instatiate first node with data
		from = to;
		Length++;
		return true;
	}
}


//remove element
template <class T>
bool bst<T>::Remove(T data) {
	bstNode<T>* toRemove = findNode(data);
	bstNode<T>* removeParent = findParent(data);

	if (toRemove != nullptr) {
		if (toRemove == root && removeParent == nullptr) {
			//remove root
			bstNode<T>* left = root->left;
			bstNode<T>* right = root->right;
			delete root;
			root = right;

			//reinsert left node
			Insert(root, left);
			Length--;
		}
		else {
			//remove a subnode
			if (toRemove == removeParent->left) {
				delete removeParent->left;
				Length--;
				removeParent->left = toRemove->right;
				Insert(removeParent, toRemove->left);
				return true;
			}
			else if (toRemove == removeParent->right) {
				delete removeParent->right;
				Length--;
				removeParent->right = toRemove->right;
				Insert(removeParent, toRemove->left);
				return true;
			}
			else {
				std::cout << "BST: Removal Failed!" << std::endl;
				return false;
			}
		}
	}
	else {
		std::cout << "Tried to remove while nonexistant" << std::endl;
		return false;
	}
}

//determine if element exists
template <class T>
bool bst<T>::ElementExists(T data) {
	T* dataPtr = Find(data);

	if (dataPtr != nullptr) {
		return true;
	}
	else {
		return false;
	}
}

//find ptr to data if exists
template <class T>
T* bst<T>::Find(T data) {
	if (root != nullptr) {
		//if there is a root
		if (data.compare((root->data)) < 0) {
			return Find(root->left, data);
		}
		else if (data.compare((root->data)) > 0) {
			return Find(root->right, data);
		}
		else if (data.compare((root->data)) == 0) {
			return root->data;
		}
		else {
			std::cout << "BST: Data compare failed!" << std::endl;
			return false;
		}
	}
	else {
		return nullptr;
	}
}

//find recursion overload
template <class T>
T* bst<T>::Find(bstNode<T>* node, T data) {
	if (node != nullptr) {
		//if node if present
		if (data.compare((node->data)) < 0) {
			return Find(node->left, data);
		}
		else if (data.compare((node->data)) > 0) {
			return Find(node->right, data);
		}
		else if (data.compare((node->data)) == 0) {
			return node->data;
		}
		else {
			std::cout << "BST: Data compare failed!" << std::endl;
			return false;
		}
	}
	else if (node == nullptr) {
		return node;
	}
}

//find a node
template <class T>
bstNode<T>* bst<T>::findNode(T data) {
	if (root != nullptr) {
		//if there is a root
		if (data.compare((root->data)) < 0) {
			return findNode(root->left, data);
		}
		else if (data.compare((root->data)) > 0) {
			return findNode(root->right, data);
		}
		else if (data.compare((root->data)) == 0) {
			return root;
		}
		else {
			std::cout << "BST: Data compare failed!" << std::endl;
			return false;
		}
	}
	else {
		return nullptr;
	}
}

//findNode overload
template <class T>
bstNode<T>* bst<T>::findNode(bstNode<T>* node, T data) {
	if (node != nullptr) {
		//if node if present
		if (data.compare((node->data)) < 0) {
			return findNode(node->left, data);
		}
		else if (data.compare((node->data)) > 0) {
			return findNode(node->right, data);
		}
		else if (data.compare((node->data)) == 0) {
			return node;
		}
		else {
			std::cout << "BST: Data compare failed!" << std::endl;
			return false;
		}
	}
	else if (node == nullptr) {
		return node;
	}
}

//find the parent from data
template <class T>
bstNode<T>* bst<T>::findParent(T data) {
	if (root != nullptr) {
		//if root if present
		if (data.compare(*(root->data)) < 0) {
			//search left
			if (root->left != nullptr) {
				//if equal return that node
				if (data.compare((root->left->data)) == 0) {
					return root->left;
				}
				//else keep moving through the nodes.
				else {
					return findParent(root->left, *data);
				}
			}
			else {
				return nullptr;
			}
		}
		else if (data.compare((root->data)) > 0) {
			//search right
			if (root->right != nullptr) {
				//if equal return that node
				if (data.compare(*(root->right->data)) == 0) {
					return root->right;
				}
				//else keep moving through the nodes.
				else {
					return findParent(root->right, *data);
				}
			}
			else {
				return nullptr;
			}
		}
		else if (data.compare((root->data)) == 0) {
			//if root and no parent return null
			return nullptr;
		}
		else {
			std::cout << "BST: Data compare failed!" << std::endl;
			return nullptr;
		}
	}
}

//findParent recursion overload
template <class T>
bstNode<T>* bst<T>::findParent(bstNode<T>* node, T data) {
	if (node != nullptr) {
		//if node if present
		if (data.compare((node->data)) < 0) {
			//search left
			if (node->left != nullptr) {
				//if equal return that node
				if (data.compare((node->left->data)) == 0) {
					return node;
				}
				//else keep moving through the nodes.
				else {
					return findParent(node->left, data);
				}
			}
			else {
				return nullptr;
			}
		}
		else if (data.compare((node->data)) > 0) {
			//search right
			if (node->right != nullptr) {
				//if equal return that node
				if (data.compare((node->right->data)) == 0) {
					return node;
				}
				//else keep moving through the nodes.
				else {
					return findParent(node->right, data);
				}
			}
			else {
				return nullptr;
			}
		}
		else if (data.compare((node->data)) == 0) {
			//overtraversed parent node
			std::cout << "BST: Data compare failed! - findParent" << std::endl;
			return nullptr;
		}
		else {
			std::cout << "BST: Data compare failed! - findParent" << std::endl;
			return nullptr;
		}
	}
}

//find frequency
template <class T>
int bst<T>::getFrequency(T data) {
	bstNode<T>* node = findNode(data);

	if (node != nullptr) {
		return node->freq;
	}
	else {
		return 0;
	}
}

//convert to array
template <class T>
std::vector<T> bst<T>::ToVector() {
	std::vector<T> vect;
	addToVector(vect, root);

	return vect;
}

//convert to array
template <class T>
std::vector<T> bst<T>::ToVector(std::vector<T> vect) {
	addToVector(vect, root);

	return vect;
}

//add to vector, for recursion
template <class T>
void bst<T>::addToVector(std::vector<T>& vect, bstNode<T>* node) {
	if (node != nullptr) {
		//add left
		if (node->left != nullptr) {
			addToVector(vect, node->left);
		}
		//add node
		vect.push_back((node->data));
		//add right
		if (node->right != nullptr) {
			addToVector(vect, node->right);
		}
	}
}

//find least node
template <class T>
bstNode<T>* bst<T>::findLeastNode(bstNode<T>* start) {
	bstNode<T>* node = start;

	while (node->left != nullptr) {
		node = node->left;
	}

	return node;
}

//determine if empty or not
template <class T>
bool bst<T>::Empty() {
	if (Length == 0) {
		return true;
	}
	else {
		return false;
	}
}
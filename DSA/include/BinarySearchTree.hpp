/*
 * BinarySearchTree.hpp
 *
 *  Created on: 14-Aug-2017
 *      Author: gsharma
 */

#ifndef INCLUDE_BINARYSEARCHTREE_HPP_
#define INCLUDE_BINARYSEARCHTREE_HPP_

#include "Node.hpp"
#include "Utils.hpp"
#include <cassert>

template <typename T>
class BinarySearchTree
{
	BSTNode<T> *root;

	void clear(BSTNode<T> *root);
	BSTNode<T> * insert(BSTNode<T> *root, const T &t);
	BSTNode<T> * remove(BSTNode<T> *root, const T &t);

	BSTNode<T> * minValueNode(BSTNode<T>* node);
	void inorder(BSTNode<T> *node) const;
public:
	BinarySearchTree():root(nullptr) {}
	virtual ~BinarySearchTree() { clear(root); }

	void insert(const T &t) { root = insert(root, t); }
	void remove(const T &t) { remove(root, t); }

	void inorder() const { inorder(root); }
};

template <typename T>
inline void BinarySearchTree<T>::clear(BSTNode<T> *root)
{
	if(root == nullptr)
		return;

	clear(root->left);
	clear(root->right);

	delete root;
	root = nullptr;
}

template<typename T>
inline BSTNode<T> * BinarySearchTree<T>::insert(BSTNode<T> *node, const T& t)
{
	if(t < node->value)
	{
		if(node->left == nullptr)
		{
			BSTNode<T> *temp = new BSTNode<T>(t);
			node->left = temp;
			return node;
		}
		node->left = insert(node->left, t);
	}
	else if(t > node->value)
	{
		if(node->right == nullptr)
		{
			BSTNode<T> *temp = new BSTNode<T>(t);
			node->right = temp;
			return node;
		}
		node->right = insert(node->right, t);
	}

	return node;
}

template <typename T>
BSTNode<T> * BinarySearchTree<T>::minValueNode(BSTNode<T>* node)
{
	BSTNode<T> * current = node;

    /* loop down to find the leftmost leaf */
    while (current->left != NULL)
        current = current->left;

    return current;
}

template<typename T>
inline BSTNode<T> * BinarySearchTree<T>::remove(BSTNode<T> *node, const T& key)
{

	    // base case
	    if (root == NULL) return root;

	    // If the key to be deleted is smaller than the root's key,
	    // then it lies in left subtree
	    if (key < root->value)
	        root->left = deleteNode(root->left, key);

	    // If the key to be deleted is greater than the root's key,
	    // then it lies in right subtree
	    else if (key > root->value)
	        root->right = deleteNode(root->right, key);

	    // if key is same as root's key, then This is the node
	    // to be deleted
	    else
	    {
	        // node with only one child or no child
	        if (root->left == NULL)
	        {
	            struct node *temp = root->right;
	            free(root);
	            return temp;
	        }
	        else if (root->right == NULL)
	        {
	            struct node *temp = root->left;
	            free(root);
	            return temp;
	        }

	        // node with two children: Get the inorder successor (smallest
	        // in the right subtree)
	        BSTNode<T>* temp = minValueNode(root->right);

	        // Copy the inorder successor's content to this node
	        root->value = temp->value;

	        // Delete the inorder successor
	        root->right = deleteNode(root->right, temp->value);
	    }
	    return root;
}

template <typename T>
void BinarySearchTree<T>::inorder(BSTNode<T> *node) const
{
	if(node == nullptr)
		return;

	inorder(node->left);
	print(node->value);
	inorder(node->right);
}

#endif /* INCLUDE_BINARYSEARCHTREE_HPP_ */

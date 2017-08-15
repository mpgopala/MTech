/*
 * AVLTree.hpp
 *
 *  Created on: 15-Aug-2017
 *      Author: gsharma
 */

#ifndef INCLUDE_AVLTREE_HPP_
#define INCLUDE_AVLTREE_HPP_

#include "BinarySearchTree.hpp"

template <typename T>
class AVLTree : public BinarySearchTree<T>
{
	int balance(BSTNode<T> *node);
	int restructure(BSTNode<T> *node, int leftHeight, int rightHeight);
	int rotateLeft(BSTNode<T> *node);
	int rotateRight(BSTNode<T> *node);

public:
	void insert(const T &t)
	{
		BinarySearchTree<T>::insert(t);
		balance(BinarySearchTree<T>::root);
	}

	void remove(const T &t)
	{
		BinarySearchTree<T>::remove(t);
		balance(BinarySearchTree<T>::root);
	}

	int height() { return BinarySearchTree<T>::height(); }
};

//Returns the height of the tree rooted at node.
template <typename T>
int AVLTree<T>::balance(BSTNode<T> *node)
{
	if(node == nullptr)
		return 0;

	int leftHeight = balance(node->left);
	int rightHeight = balance(node->right);

	return restructure(node, leftHeight, rightHeight);
}

template <typename T>
int AVLTree<T>::restructure(BSTNode<T> *node, int leftHeight, int rightHeight)
{
	int retVal = (leftHeight > rightHeight?leftHeight:rightHeight) + 1;
	if(abs(leftHeight - rightHeight) <= 1)
		return retVal;

	if(leftHeight > rightHeight)
		retVal = rotateLeft(node);
	else
		retVal = rotateRight(node);
	return retVal + 1;
}

template <typename T>
int AVLTree<T>::rotateLeft(BSTNode<T> *node)
{
	if(node == nullptr || node->left == nullptr)
	{
		assert(false);
		return 0;
	}

	BSTNode<T> *left = node->left;

	T temp = node->value;
	node->value = left->value;
	left->value = temp;


	node->left = left->left;
	left->left = left->right;
	left->right = node->right;
	node->right = left;

	return BinarySearchTree<T>::height(node);
}

template <typename T>
int AVLTree<T>::rotateRight(BSTNode<T> *node)
{
	if(node == nullptr || node->right == nullptr)
	{
		assert(false);
		return 0;
	}

	BSTNode<T> *right = node->right;

	T temp = node->value;
	node->value = right->value;
	right->value = temp;


	node->right = right->right;
	right->right = right->left;
	right->left = node->left;
	node->left = right;

	return BinarySearchTree<T>::height(node);
}
#endif /* INCLUDE_AVLTREE_HPP_ */

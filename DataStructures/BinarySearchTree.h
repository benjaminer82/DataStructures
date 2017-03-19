#pragma once
#include "BinaryTree.h"

template<class Type>
class BinarySearchTree : public CBinaryTree<Type> 
{
public:
	BinarySearchTree(const Type & value);
	~BinarySearchTree();

	bool Find(const Type & value);
protected:
	void AddToNode(const Type& value, Node<Type>* addToNode) override;

private:
	bool FindInTree(const Type & value, const Node<Type>* node);

};

template<class Type>
inline BinarySearchTree<Type>::BinarySearchTree(const Type & value) : CBinaryTree(value)
{
	pRoot = new Node<Type>();
	pRoot->value = value;
	pRoot->pLeft = pRoot->pRight = nullptr;
	nodes.clear();
}

template<class Type>
BinarySearchTree<Type>::~BinarySearchTree()
{
	DestroyTree();
}

template<class Type>
inline bool BinarySearchTree<Type>::Find(const Type & value)
{
	return FindInTree(value, pRoot);
}

template<class Type>
inline bool BinarySearchTree<Type>::FindInTree(const Type & value, const Node<Type>* node)
{
	if (!node)
		return false;

	if (value == node->value)
		return true;

	if (value < node->value)
		return FindInTree(value, node->pLeft);
	else if (value > node->value)
		return FindInTree(value, node->pRight);

	return false;
}

template<class Type>
inline void BinarySearchTree<Type>::AddToNode(const Type & value, Node<Type>* addToNode)
{
	_ASSERT(&addToNode);

	if (value <= addToNode->value)
	{
		if (addToNode->pLeft)
			AddToNode(value, addToNode->pLeft);
		else
			addToNode->pLeft = CreateNodeWithValue(value);
	}
	else if (value > addToNode->value)
	{
		if (addToNode->pRight)
			AddToNode(value, addToNode->pRight);
		else
			addToNode->pRight = CreateNodeWithValue(value);
	}
}

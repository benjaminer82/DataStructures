#pragma once
#include <string>
#include <deque>
#include <iostream>

template <class Type>
struct Node {
	Type value;

	Node<Type> * pLeft;
	Node<Type> * pRight;
};

template <class Type>
class CBinaryTree
{
public:
	CBinaryTree(const Type & value);
	~CBinaryTree();

	virtual void InsertNode(const Type & value);
	std::string ToString(int iOpt = 1); // iOpt = 1, breadth first; iOpt = 2, depth first.

protected:
	virtual void DestroyTree();
	virtual void DestroyNodes(Node<Type>* node);
	virtual bool DestroyChild(Node<Type>* child);
	bool HasNoChild(Node<Type>* node) { return !node->pLeft && !node->pRight; }
	virtual void AddToNode(const Type& value, Node<Type>* nodeToAdd);
	void AddChildrenToQueueLeftFirst(const Node<Type> & node);
	void AddChildrenToQueueRightFirst(const Node<Type>& node);
	Node<Type>* CreateNodeWithValue(const Type & value);
	std::string PrintNodeBreadthFirst(const Node<Type> & node);
	std::string PrintNodeDepthFirst(const Node<Type> & node);

	std::deque<Node<Type>*> nodes;
	Node<Type> * pRoot;
}; 


using namespace std;

template<class Type>
inline CBinaryTree<Type>::CBinaryTree(const Type & value)
{
	pRoot = new Node<Type>();
	pRoot->value = value;
	pRoot->pLeft = pRoot->pRight = nullptr;
	nodes.clear();
}

template<class Type>
CBinaryTree<Type>::~CBinaryTree()
{
	DestroyTree();
}

template<class Type>
void CBinaryTree<Type>::DestroyTree()
{
	nodes.clear();

	if (pRoot)
	{
		nodes.push_back(pRoot);
		DestroyNodes(pRoot);
		pRoot->pLeft = nullptr;
		pRoot->pRight = nullptr;
		delete pRoot;
		pRoot = nullptr;
	}
}

template<class Type>
void CBinaryTree<Type>::DestroyNodes(Node<Type> *node)
{	
	if (node->pLeft && DestroyChild(node->pLeft))
		node->pLeft = nullptr;
	if (node->pRight && DestroyChild(node->pRight))
		node->pRight = nullptr;

	if (HasNoChild(node) && !nodes.empty())
		nodes.pop_back();

	if (!nodes.empty())
	{
		auto next = nodes.back();
		DestroyNodes(next);
	}
}

template<class Type>
bool CBinaryTree<Type>::DestroyChild(Node<Type>* child)
{
	if (HasNoChild(child))
	{
		delete child;
		return true;
	}
	else
		nodes.push_back(child);

	return false;
}


template<class Type>
inline void CBinaryTree<Type>::InsertNode(const Type & value)
{
	_ASSERT(pRoot);
	nodes.clear();
	Node<Type>* pNode = new Node<Type>();
	pNode->value = value;
	pNode->pLeft = pNode->pRight = nullptr;

	AddToNode(value, pRoot);
}

template<class Type>
inline void CBinaryTree<Type>::AddToNode(const Type& value, Node<Type>* addToNode)
{
	_ASSERT(&addToNode);
	
	if (!addToNode->pLeft)
		addToNode->pLeft = CreateNodeWithValue(value);
	else if (!addToNode->pRight)
		addToNode->pRight = CreateNodeWithValue(value);
	else
	{
		AddChildrenToQueueLeftFirst(*addToNode);
		auto nextNode = nodes.front();
		nodes.pop_front();
		AddToNode(value, nextNode);		
	}
}

template<class Type>
inline void CBinaryTree<Type>::AddChildrenToQueueLeftFirst(const Node<Type>& node)
{
	if (node.pLeft)
		nodes.push_back(node.pLeft);
	if (node.pRight)
		nodes.push_back(node.pRight);
}

template<class Type>
inline void CBinaryTree<Type>::AddChildrenToQueueRightFirst(const Node<Type>& node)
{
	if (node.pRight)
		nodes.push_back(node.pRight);
	if (node.pLeft)
		nodes.push_back(node.pLeft);	
}

template<class Type>
inline Node<Type>* CBinaryTree<Type>::CreateNodeWithValue(const Type & value)
{
	Node<Type> * pLeaf = new Node<Type>();
	pLeaf->value = value;
	pLeaf->pLeft = pLeaf->pRight = nullptr;

	return pLeaf;
}

template<class Type>
string CBinaryTree<Type>::ToString(int iOpt)
{
	_ASSERT(pRoot);
	nodes.clear();

	if (iOpt == 1)
		return PrintNodeBreadthFirst(*pRoot);
	else
		return PrintNodeDepthFirst(*pRoot);
}

template<class Type>
inline string CBinaryTree<Type>::PrintNodeBreadthFirst(const Node<Type>& node)
{
	_ASSERT(&node);
	string retValue;

	AddChildrenToQueueLeftFirst(node);
	retValue = std::to_string(node.value) + ",";
	if (!nodes.empty())
	{		
		auto nextNode = *nodes.front();
		nodes.pop_front();
		retValue += PrintNodeBreadthFirst(nextNode);
	}

	return retValue;
}

template<class Type>
inline std::string CBinaryTree<Type>::PrintNodeDepthFirst(const Node<Type>& node)
{
	_ASSERT(&node);
	string retValue;

	AddChildrenToQueueRightFirst(node);
	retValue = std::to_string(node.value) + ",";
	if (!nodes.empty())
	{
		auto nextNode = *nodes.back();
		nodes.pop_back();
		retValue += PrintNodeDepthFirst(nextNode);
	}

	return retValue;
}





#pragma once
#include <string>

template <class Type>
class CBinaryTree;

class CDemo
{
public:
	CDemo();
	~CDemo();
	void Init();

private:
	void mainMenu();
	void binaryTreeSection();
	void binarySearchTreeSection();
	void validateTree();
	void treeSection();
	void treeMenu();
	bool useBinaryTree() { return treeSelection == 1; }
	bool useBinarySearchTree() { return treeSelection == 2; }
	void setUseBinaryTree() { treeSelection = 1; }
	void setUseBinarySearchTree() { treeSelection = 2; }

	int ConvertToInt(const std::string str);

	CBinaryTree<int> * binaryTree;

	int treeSelection;
};


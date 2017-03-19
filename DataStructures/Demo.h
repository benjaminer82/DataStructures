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
	void treeSection(int iOpt);// iOpt = 1 binary tree; iOpt = 2 binary search tree.
	void treeMenu(int iOpt);// iOpt = 1 binary tree; iOpt = 2 binary search tree.

	int ConvertToInt(const std::string str);

	CBinaryTree<int> * binaryTree;
};


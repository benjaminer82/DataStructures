#include "Demo.h"
#include "BinaryTree.h"
#include "BinarySearchTree.h"
#include <iostream>
#include <string>

using namespace std;

CDemo::CDemo()
{
	treeSelection = 1;
}


CDemo::~CDemo()
{
	if (binaryTree)
		delete binaryTree;
}

void CDemo::Init()
{
	mainMenu();
	string userInput;
	while (getline(cin, userInput))
	{
		if (userInput.compare("exit") == 0)
			return;
		else if (userInput.compare("1") == 0)
			binaryTreeSection();
		else if (userInput.compare("2") == 0)
			binarySearchTreeSection();
		
		mainMenu();
	}
}

void CDemo::mainMenu() {
	cout << "please select from the following" << endl;
	cout << "press 1 to create a binary tree" << endl;
	cout << "press 2 to create a binary search tree" << endl;
	cout << "press exit to exit" << endl;
}

void CDemo::binaryTreeSection()
{
	setUseBinaryTree();
	treeSection();
}

void CDemo::binarySearchTreeSection()
{
	setUseBinarySearchTree();
	treeSection();
}

void CDemo::validateTree()
{
	if (binaryTree)
	{
		binaryTree->~CBinaryTree();
		binaryTree = nullptr;
	}
}

void CDemo::treeMenu()
{
	if(useBinaryTree())
		cout << "please enter numbers for the new binary tree" << endl;
	else
		cout << "please enter numbers for the new binary search tree" << endl;
	cout << "press d to print the tree in depth first mode" << endl;
	cout << "press b to print the tree in breadth first mode" << endl;
	cout << "press exit to quite to the main menu" << endl;
}

int CDemo::ConvertToInt(const std::string str)
{
	return std::atoi(str.c_str());
	return 0;
}

void CDemo::treeSection()
{
	validateTree();
	treeMenu();
	string userInput;
	while (getline(cin, userInput))
	{
		if (userInput.compare("exit") == 0)
			return;
		else if (userInput.compare("b") == 0)
		{
			printTreeBreadthFirst();
		}
		else if (userInput.compare("d") == 0)
		{
			printTreeDepthFirst();
		}
		else
		{
			int value = ConvertToInt(userInput);
			insertNodeToTree(value);
		}
	}
}

void CDemo::printTreeBreadthFirst()
{
	if (binaryTree)
		cout << binaryTree->ToString(1) << endl;
	else
		treeMenu();
}

void CDemo::printTreeDepthFirst()
{
	if (binaryTree)
		cout << binaryTree->ToString(2) << endl;
	else
		treeMenu();
}

void CDemo::insertNodeToTree(int value)
{	
	if (binaryTree)
		binaryTree->InsertNode(value);
	else
	{
		if (useBinaryTree())
			binaryTree = new CBinaryTree<int>(value);
		else
			binaryTree = new BinarySearchTree<int>(value);
	}
}

int main()
{
	CDemo demo;
	demo.Init();

	return 0;
}

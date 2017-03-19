#include "Demo.h"
#include "BinaryTree.h"
#include "BinarySearchTree.h"
#include <iostream>
#include <string>

using namespace std;

CDemo::CDemo()
{
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
			treeSection(1);
		else if (userInput.compare("2") == 0)
			treeSection(2);
		
		mainMenu();
	}
}

void CDemo::mainMenu() {
	cout << "please select from the following" << endl;
	cout << "press 1 to create a binary tree" << endl;
	cout << "press 2 to create a binary search tree" << endl;
	cout << "press exit to exit" << endl;
}

void CDemo::treeMenu(int iOpt)
{
	if(iOpt == 1)
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

void CDemo::treeSection(int iOpt)
{
	if (binaryTree)
	{
		binaryTree->~CBinaryTree();
		binaryTree = nullptr;
	}

	treeMenu(iOpt);
	string userInput;
	while (getline(cin, userInput))
	{
		if (userInput.compare("exit") == 0)
			return;
		else if (userInput.compare("b") == 0)
		{
			if (binaryTree)
				cout << binaryTree->ToString(1) << endl;
			else
				treeMenu(iOpt);
		}
		else if (userInput.compare("d") == 0)
		{
			if (binaryTree)
				cout << binaryTree->ToString(2) << endl;
			else
				treeMenu(iOpt);
		}
		else
		{
			int value = ConvertToInt(userInput);
			if (binaryTree)
				binaryTree->InsertNode(value);
			else
			{
				if (iOpt == 1)
					binaryTree = new CBinaryTree<int>(value);
				else
					binaryTree = new BinarySearchTree<int>(value);
			}
		}
	}
}

int main()
{
	CDemo demo;
	demo.Init();

	return 0;
}

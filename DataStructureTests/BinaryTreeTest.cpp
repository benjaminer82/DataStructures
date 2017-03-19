#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\DataStructures\BinaryTree.h"
#include <wchar.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace BinaryTreeTest
{		
	TEST_CLASS(BinaryTreeTest)
	{
	public:
		CBinaryTree<int>* bst;

		TEST_METHOD_INITIALIZE(SetupBinaryTree)
		{
			bst = new CBinaryTree<int>(0);
		}

		TEST_METHOD_CLEANUP(CleanupBinaryTree)
		{
			delete bst;
		}
		
		TEST_METHOD(PrintResultBreadthFirstInt)
		{
			// TODO: Your test code here
			bst->InsertNode(8);
			bst->InsertNode(9);
			bst->InsertNode(2);
			bst->InsertNode(4);
			bst->InsertNode(12);

			std::string treeString = bst->ToString(1);
			std::string sExpected = std::to_string(0);
			std::string sActual = std::to_string(treeString.compare("0,8,9,2,4,12,"));
			std::string msg = "PrintResultBreadthFirstInt failed " + treeString;
			Assert::AreEqual(sExpected.c_str(), sActual.c_str(), msg.c_str());
//			Assert::IsTrue(treeString.compare("5,8,9,2,4,12,") == 0);
//			Logger::WriteMessage("PrintResultInt test done");
		}

		TEST_METHOD(PrintResultBreadthFirstIntEmptyTree)
		{
			// TODO: Your test code here
			std::string treeString = bst->ToString(1);
			std::string sExpected = std::to_string(0);
			std::string sActual = std::to_string(treeString.compare("0,"));
			std::string msg = "PrintResultBreadthFirstIntEmptyTree failed " + treeString;
			Assert::AreEqual(sExpected.c_str(), sActual.c_str(), msg.c_str());
		}

		TEST_METHOD(PrintResultBreadthFirstIntDuplicates)
		{
			// TODO: Your test code here
			bst->InsertNode(0);
			bst->InsertNode(0);
			bst->InsertNode(0);
			bst->InsertNode(0);
			bst->InsertNode(0);

			std::string treeString = bst->ToString(1);
			std::string sExpected = std::to_string(0);
			std::string sActual = std::to_string(treeString.compare("0,0,0,0,0,0,"));
			std::string msg = "PrintResultBreadthFirstIntDuplicates failed " + treeString;
			Assert::AreEqual(sExpected.c_str(), sActual.c_str(), msg.c_str());
		}

		TEST_METHOD(PrintResultDepthFirstInt)
		{
			// TODO: Your test code here
			bst->InsertNode(8);
			bst->InsertNode(9);
			bst->InsertNode(2);
			bst->InsertNode(4);
			bst->InsertNode(12);

			std::string treeString = bst->ToString(2);
			std::string sExpected = std::to_string(0);
			std::string sActual = std::to_string(treeString.compare("0,8,2,4,9,12,"));
			std::string msg = "PrintResultDepthFirstInt failed " + treeString;
			Assert::AreEqual(sExpected.c_str(), sActual.c_str(), msg.c_str());
		}

		TEST_METHOD(PrintResultDepthFirstIntEmptyTree)
		{
			// TODO: Your test code here
			std::string treeString = bst->ToString(2);
			std::string sExpected = std::to_string(0);
			std::string sActual = std::to_string(treeString.compare("0,"));
			std::string msg = "PrintResultDepthFirstIntEmptyTree failed " + treeString;
			Assert::AreEqual(sExpected.c_str(), sActual.c_str(), msg.c_str());
		}

		TEST_METHOD(PrintResultDepthFirstIntDuplicates)
		{
			// TODO: Your test code here
			bst->InsertNode(0);
			bst->InsertNode(0);
			bst->InsertNode(0);
			bst->InsertNode(0);
			bst->InsertNode(0);

			std::string treeString = bst->ToString(2);
			std::string sExpected = std::to_string(0);
			std::string sActual = std::to_string(treeString.compare("0,0,0,0,0,0,"));
			std::string msg = "PrintResultDepthFirstIntDuplicates failed " + treeString;
			Assert::AreEqual(sExpected.c_str(), sActual.c_str(), msg.c_str());
		}

	};
}
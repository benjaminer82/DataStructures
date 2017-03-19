#include "stdafx.h"
#include "CppUnitTest.h"
#include "../DataStructures/BinarySearchTree.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace BinarySearchTreeTest {
	TEST_CLASS(BinarySearchTreeTest)	
	{
	public:
		BinarySearchTree<int>* bst;

		TEST_METHOD_INITIALIZE(SetupBinaryTree)
		{
			bst = new BinarySearchTree<int>(6);
		}

		TEST_METHOD_CLEANUP(CleanupBinaryTree)
		{
			delete bst;
		}

		void init()
		{
			if (bst)
			{
				bst->InsertNode(9);
				bst->InsertNode(3);
				bst->InsertNode(2);
				bst->InsertNode(18);
				bst->InsertNode(98);
				bst->InsertNode(5);
				bst->InsertNode(7);
			}
		}

		TEST_METHOD(PrintResultInt)
		{
			init();

			string result = bst->ToString(2);
			string expected = "0";
			string actual = std::to_string(result.compare("6,3,2,5,9,7,18,98,"));
			std::string msg = "PrintResultInt failed " + result;
			Assert::AreEqual(expected.c_str(), actual.c_str(), msg.c_str());
		}

		TEST_METHOD(FindIntSuccess)
		{
			init();

			Assert::IsTrue(bst->Find(2), L"FindInt failed");
		}

		TEST_METHOD(FindRootIntSuccess)
		{
			init();

			Assert::IsTrue(bst->Find(6), L"FindRootIntSuccess failed");
		}

		TEST_METHOD(FindIntFail)
		{
			init();

			Assert::IsFalse(bst->Find(12), L"FindIntFail failed");
		}
	};
}
#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab6.4_REC/Lab6.4_REC.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest64REC
{
	TEST_CLASS(UnitTest64REC)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int arr[] = { 1, 2, 3, 4, 5 };
			printA(arr, 5);
			Assert::AreEqual(0, 0);
		}
	};
}

#include "pch.h"
#include "CppUnitTest.h"
#include "../oop 6.7/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UToop67
{
	TEST_CLASS(UToop67)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int a[14] = { -4, 1, 5, -1, 2, 3, -4, 9, -7, -6, -1, 2, 3, -4 };
			int a2[4] = { -1, 2, 3, -4 };

			int* found = Search_End(&a[0], &a[14], &a2[0], &a2[4]);
			int i = Index(&a[0], &a[14], found);
			Assert::AreEqual(i, 10);
		}
	};
}

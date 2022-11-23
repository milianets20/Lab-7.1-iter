#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab 7.1 iter/Lab 7.1 iter.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TESTFORITER71
{
	TEST_CLASS(TESTFORITER71)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int count = 0;
			int suma = 0;
			int result;
			const int ROW_COUNT = 4;
			const int COL_COUNT = 4;
			int a[ROW_COUNT][COL_COUNT] = {
				{1, 5, 6, 10},
				{4, 12, 18, 9},
				{3, -2, 7, 0},
				{-3, 4, 6, 7}
			};
			int* pa[4] = { a[0], a[1], a[2], a[3] };
			Calc(pa, ROW_COUNT, COL_COUNT, suma, count);
			result = count;
			Assert::AreEqual(3, result);
		}
	};
}

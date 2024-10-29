#include "pch.h"
#include "CppUnitTest.h"
#include "../llab71it/llab71it.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest71it
{
	TEST_CLASS(UnitTest71it)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			const int rowCount = 3;
			const int colCount = 4;
			int** a = new int* [rowCount];
			for (int i = 0; i < rowCount; i++)
				a[i] = new int[colCount];

			// Ініціалізуємо тестовий масив
			a[0][0] = 5; a[0][1] = 3; a[0][2] = 2; a[0][3] = 1;
			a[1][0] = 7; a[1][1] = 1; a[1][2] = 2; a[1][3] = 0;
			a[2][0] = 3; a[2][1] = 2; a[2][2] = 4; a[2][3] = 6;

			Sort(a, rowCount, colCount);

			Assert::IsTrue(a[0][0] >= a[1][0]);
			Assert::IsTrue(a[1][0] >= a[2][0]);

			for (int i = 0; i < rowCount; i++)
				delete[] a[i];
			delete[] a;
		}
	};
}

#include "pch.h"
#include "CppUnitTest.h"
#include "..\Lab_12_2.4\Matrix.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Matrix m(2, 1);
			m[0][0] = 2;
			m[1][0] = -4;
			Assert::AreEqual(m.Norm(), 6u);
		}
	};
}

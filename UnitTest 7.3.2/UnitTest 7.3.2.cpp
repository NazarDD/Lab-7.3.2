#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab 7.3.2/Lab 7.3.2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace YourProjectTests
{
    TEST_CLASS(MatrixFunctionsTest)
    {
    public:
        TEST_METHOD(TestFindSameRowAndColumn)
        {
            int n = 3;
            int** a = new int* [n];
            for (int i = 0; i < n; i++)
                a[i] = new int[n];

            a[0][0] = 1; a[0][1] = 2; a[0][2] = 3;
            a[1][0] = 2; a[1][1] = 5; a[1][2] = 6;
            a[2][0] = 3; a[2][1] = 6; a[2][2] = 9;

            std::stringstream capturedOutput;
            std::streambuf* originalOutput = std::cout.rdbuf(capturedOutput.rdbuf());
            FindSameRowAndColumn(a, n, 0);
            std::string output = capturedOutput.str();
            std::string expectedOutput = "Row 0 and Column 0\nRow 1 and Column 1\nRow 2 and Column 2\n";
            Assert::AreEqual(output, expectedOutput);
            std::cout.rdbuf(originalOutput);
        }

        TEST_METHOD(TestSumRowsWithNegativeElements)
        {
            int n = 3;
            int** a = new int* [n];
            for (int i = 0; i < n; i++)
                a[i] = new int[n];

            a[0][0] = -2; a[0][1] = -1; a[0][2] = 2;
            a[1][0] = -3; a[1][1] = 1; a[1][2] = -4;
            a[2][0] = 1; a[2][1] = 2; a[2][2] = 3;

            int result = SumRowsWithNegativeElementsRec(a, n, 0, 0);
            int expected = -7; 

            Assert::AreEqual(result, expected);

        }
    };
}

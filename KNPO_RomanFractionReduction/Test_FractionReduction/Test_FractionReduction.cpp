#include "pch.h"
#include "CppUnitTest.h"
#include "../RomanFractionReduction/Prototypes.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestFractionReduction
{
	TEST_CLASS(TestFractionReduction)
	{
	public:
		TEST_METHOD(NumeratorIsLessThanDenominatorAndFractionIsNotReduced)
		{
			int numerator = 2;
			int denominator = 5;
			int reductedFraction[2];
			int exp_reductedFraction[2] = { 2,5 };
			FractionReduction(reductedFraction, numerator, denominator);

			Assert::IsTrue(equalArrays(exp_reductedFraction, reductedFraction));

		}

		TEST_METHOD(NumeratorIsGreaterThanDenominatorAndFractionIsReduced)
		{
			int numerator = 10;
			int denominator = 5;
			int reductedFraction[2];
			int exp_reductedFraction[2] = { 2,1 };
			FractionReduction(reductedFraction, numerator, denominator);

			Assert::IsTrue(equalArrays(exp_reductedFraction, reductedFraction));

		}

		TEST_METHOD(NumeratorIsGreaterThanDenominatorAndFractionIsNotReduced)
		{
			int numerator = 12;
			int denominator = 5;
			int reductedFraction[2];
			int exp_reductedFraction[2] = { 12,5 };
			FractionReduction(reductedFraction, numerator, denominator);

			Assert::IsTrue(equalArrays(exp_reductedFraction, reductedFraction));

		}

		TEST_METHOD(NumeratorAndDenominatorOfTheFractionAreEqual)
		{
			int numerator = 3;
			int denominator = 3;
			int reductedFraction[2];
			int exp_reductedFraction[2] = { 1,1 };
			FractionReduction(reductedFraction, numerator, denominator);

			Assert::IsTrue(equalArrays(exp_reductedFraction, reductedFraction));

		}

		TEST_METHOD(FractionDoesNotRequireReduction)
		{
			int numerator = 5;
			int denominator = 1;
			int reductedFraction[2];
			int exp_reductedFraction[2] = { 5,1 };
			FractionReduction(reductedFraction, numerator, denominator);

			Assert::IsTrue(equalArrays(exp_reductedFraction, reductedFraction));

		}

		TEST_METHOD(NumeratorIsLessThanDenominatorAndFractionIsReduced)
		{
			int numerator = 6;
			int denominator = 12;
			int reductedFraction[2];
			int exp_reductedFraction[2] = { 1,2 };
			FractionReduction(reductedFraction, numerator, denominator);

			Assert::IsTrue(equalArrays(exp_reductedFraction, reductedFraction));

		}

		bool equalArrays(int arr[], int arr1[])
		{
			int length = sizeof(arr) / sizeof(arr[0]);
			int length1 = sizeof(arr1) / sizeof(arr1[0]);

			if (length != length1)
			{
				return false;
			}

			for (int i = 0; i < length; i++)
			{
				if (arr[i] != arr1[i])
				{
					return false;
				}
			}
			return true;
		}
	};
}

#include "pch.h"
#include "CppUnitTest.h"
#include "../RomanFractionReduction/Prototypes.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestConvertToRimNumber
{
	TEST_CLASS(TestConvertToRimNumber)
	{
	public:

		TEST_METHOD(BeforeFiveIsOne)
		{
			int ArabicNumber = 4;
			string rimNum;
			string exp_rimNum = "IV";

			rimNum = ConvertToRimNumber(ArabicNumber);

			Assert::AreEqual(exp_rimNum, rimNum);
		}

		TEST_METHOD(BeforeTenIsOne)
		{
			int ArabicNumber = 9;
			string rimNum;
			string exp_rimNum = "IX";

			rimNum = ConvertToRimNumber(ArabicNumber);

			Assert::AreEqual(exp_rimNum, rimNum);
		}

		TEST_METHOD(BeforeFiftyIsTen)
		{
			int ArabicNumber = 40;
			string rimNum;
			string exp_rimNum = "XL";

			rimNum = ConvertToRimNumber(ArabicNumber);

			Assert::AreEqual(exp_rimNum, rimNum);
		}

		TEST_METHOD(BeforeHundredIsTen)
		{
			int ArabicNumber = 90;
			string rimNum;
			string exp_rimNum = "XC";

			rimNum = ConvertToRimNumber(ArabicNumber);

			Assert::AreEqual(exp_rimNum, rimNum);
		}

		TEST_METHOD(BeforeFiveHundredIsHundred)
		{
			int ArabicNumber = 400;
			string rimNum;
			string exp_rimNum = "CD";

			rimNum = ConvertToRimNumber(ArabicNumber);

			Assert::AreEqual(exp_rimNum, rimNum);
		}

		TEST_METHOD(BeforeThousandIsHundred)
		{
			int ArabicNumber = 900;
			string rimNum;
			string exp_rimNum = "CM";

			rimNum = ConvertToRimNumber(ArabicNumber);

			Assert::AreEqual(exp_rimNum, rimNum);
		}

		TEST_METHOD(MaxNumber)
		{
			int ArabicNumber = 10000;
			string rimNum;
			string exp_rimNum = "MMMMMMMMMM";

			rimNum = ConvertToRimNumber(ArabicNumber);

			Assert::AreEqual(exp_rimNum, rimNum);
		}

		TEST_METHOD(FirstBigNumber)
		{
			int ArabicNumber = 9494;
			string rimNum;
			string exp_rimNum = "MMMMMMMMMCDXCIV";

			rimNum = ConvertToRimNumber(ArabicNumber);

			Assert::AreEqual(exp_rimNum, rimNum);
		}

		TEST_METHOD(SecondBigNumber)
		{
			int ArabicNumber = 4949;
			string rimNum;
			string exp_rimNum = "MMMMCMXLIX";

			rimNum = ConvertToRimNumber(ArabicNumber);

			Assert::AreEqual(exp_rimNum, rimNum);
		}

		TEST_METHOD(NumberIsOne)
		{
			int ArabicNumber = 1;
			string rimNum;
			string exp_rimNum = "I";

			rimNum = ConvertToRimNumber(ArabicNumber);

			Assert::AreEqual(exp_rimNum, rimNum);
		}

		TEST_METHOD(NumberIsTwo)
		{
			int ArabicNumber = 2;
			string rimNum;
			string exp_rimNum = "II";

			rimNum = ConvertToRimNumber(ArabicNumber);

			Assert::AreEqual(exp_rimNum, rimNum);
		}

		TEST_METHOD(NumberIsThree)
		{
			int ArabicNumber = 3;
			string rimNum;
			string exp_rimNum = "III";

			rimNum = ConvertToRimNumber(ArabicNumber);

			Assert::AreEqual(exp_rimNum, rimNum);
		}

		TEST_METHOD(NumberIsTen)
		{
			int ArabicNumber = 10;
			string rimNum;
			string exp_rimNum = "X";

			rimNum = ConvertToRimNumber(ArabicNumber);

			Assert::AreEqual(exp_rimNum, rimNum);
		}

		TEST_METHOD(NumberIsFive)
		{
			int ArabicNumber = 5;
			string rimNum;
			string exp_rimNum = "V";

			rimNum = ConvertToRimNumber(ArabicNumber);

			Assert::AreEqual(exp_rimNum, rimNum);
		}

		TEST_METHOD(AdditionThreeUnitsToTheFive)
		{
			int ArabicNumber = 8;
			string rimNum;
			string exp_rimNum = "VIII";

			rimNum = ConvertToRimNumber(ArabicNumber);

			Assert::AreEqual(exp_rimNum, rimNum);
		}
	};
}

#include "pch.h"
#include "CppUnitTest.h"
#include "../RomanFractionReduction/Prototypes.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestConvertToArabicNumber
{
	TEST_CLASS(TestConvertToArabicNumber)
	{
	public:

		TEST_METHOD(BeforeFiveIsOne)
		{
			string rimNum = "IV";
			int arabicNum;
			int exp_arabicNum = 4;
			arabicNum = ConvertToArabicNumber(rimNum);

			Assert::AreEqual(exp_arabicNum, arabicNum);
		}

		TEST_METHOD(BeforeTenIsOne)
		{
			string rimNum = "IX";
			int arabicNum;
			int exp_arabicNum = 9;
			arabicNum = ConvertToArabicNumber(rimNum);

			Assert::AreEqual(exp_arabicNum, arabicNum);
		}

		TEST_METHOD(BeforeFiftyIsTen)
		{
			string rimNum = "XL";
			int arabicNum;
			int exp_arabicNum = 40;
			arabicNum = ConvertToArabicNumber(rimNum);

			Assert::AreEqual(exp_arabicNum, arabicNum);
		}

		TEST_METHOD(BeforeHundredIsTen)
		{
			string rimNum = "XC";
			int arabicNum;
			int exp_arabicNum = 90;
			arabicNum = ConvertToArabicNumber(rimNum);

			Assert::AreEqual(exp_arabicNum, arabicNum);
		}

		TEST_METHOD(BeforeFiveHundredIsHundred)
		{
			string rimNum = "CD";
			int arabicNum;
			int exp_arabicNum = 400;
			arabicNum = ConvertToArabicNumber(rimNum);

			Assert::AreEqual(exp_arabicNum, arabicNum);
		}

		TEST_METHOD(BeforeThousandIsHundred)
		{
			string rimNum = "CM";
			int arabicNum;
			int exp_arabicNum = 900;
			arabicNum = ConvertToArabicNumber(rimNum);

			Assert::AreEqual(exp_arabicNum, arabicNum);
		}

		TEST_METHOD(MaxNumber)
		{
			string rimNum = "MMMMMMMMMM";
			int arabicNum;
			int exp_arabicNum = 10000;
			arabicNum = ConvertToArabicNumber(rimNum);

			Assert::AreEqual(exp_arabicNum, arabicNum);
		}

		TEST_METHOD(FirstBigNumber)
		{
			string rimNum = "MMMMMMMMMCDXCIV";
			int arabicNum;
			int exp_arabicNum = 9494;
			arabicNum = ConvertToArabicNumber(rimNum);

			Assert::AreEqual(exp_arabicNum, arabicNum);
		}

		TEST_METHOD(SecondBigNumber)
		{
			string rimNum = "MMMMCMXLIX";
			int arabicNum;
			int exp_arabicNum = 4949;
			arabicNum = ConvertToArabicNumber(rimNum);

			Assert::AreEqual(exp_arabicNum, arabicNum);
		}

		TEST_METHOD(NumberIsOne)
		{
			string rimNum = "I";
			int arabicNum;
			int exp_arabicNum = 1;
			arabicNum = ConvertToArabicNumber(rimNum);

			Assert::AreEqual(exp_arabicNum, arabicNum);
		}

		TEST_METHOD(NumberIsTwo)
		{
			string rimNum = "II";
			int arabicNum;
			int exp_arabicNum = 2;
			arabicNum = ConvertToArabicNumber(rimNum);

			Assert::AreEqual(exp_arabicNum, arabicNum);
		}

		TEST_METHOD(NumberIsThree)
		{
			string rimNum = "III";
			int arabicNum;
			int exp_arabicNum = 3;
			arabicNum = ConvertToArabicNumber(rimNum);

			Assert::AreEqual(exp_arabicNum, arabicNum);
		}

		TEST_METHOD(NumberIsTen)
		{
			string rimNum = "X";
			int arabicNum;
			int exp_arabicNum = 10;
			arabicNum = ConvertToArabicNumber(rimNum);

			Assert::AreEqual(exp_arabicNum, arabicNum);
		}

		TEST_METHOD(NumberIsFive)
		{
			string rimNum = "V";
			int arabicNum;
			int exp_arabicNum = 5;
			arabicNum = ConvertToArabicNumber(rimNum);

			Assert::AreEqual(exp_arabicNum, arabicNum);
		}

		TEST_METHOD(AdditionThreeUnitsToTheFive)
		{
			string rimNum = "VIII";
			int arabicNum;
			int exp_arabicNum = 8;
			arabicNum = ConvertToArabicNumber(rimNum);

			Assert::AreEqual(exp_arabicNum, arabicNum);
		}
	};
}

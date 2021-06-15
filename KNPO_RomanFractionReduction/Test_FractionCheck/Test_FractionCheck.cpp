#include "pch.h"
#include "CppUnitTest.h"
#include "../RomanFractionReduction/Prototypes.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestFractionCheck
{
	TEST_CLASS(TestFractionCheck)
	{
	public:

		TEST_METHOD(EmptyString)
		{
			string Fraction = "";
			string result;
			string exp_result = "5";
			result = getStringFromFunc(Fraction);

			Assert::AreEqual(exp_result, result);
		}

		TEST_METHOD(UnacceptableSymbols)
		{
			string Fraction = "ds/I";
			string result;
			string exp_result = "8";
			result = getStringFromFunc(Fraction);

			Assert::AreEqual(exp_result, result);
		}

		TEST_METHOD(InvalidSignBetweenNumbers)
		{
			string Fraction = "X*V";
			string result;
			string exp_result = "6";
			result = getStringFromFunc(Fraction);

			Assert::AreEqual(exp_result, result);
		}

		TEST_METHOD(InvalidStringFormat)
		{
			string Fraction = "X  / V";
			string result;
			string exp_result = "7";
			result = getStringFromFunc(Fraction);

			Assert::AreEqual(exp_result, result);
		}

		TEST_METHOD(TheNumberDoesNotCorrespondRulesForWritingRomanNumerals)
		{
			string Fraction = "IIV/V";
			string result;
			string exp_result = "12";
			result = getStringFromFunc(Fraction);

			Assert::AreEqual(exp_result, result);
		}

		TEST_METHOD(NumberDoesNotBelongToRange)
		{
			string Fraction = "MMMMMMMMMMI/I";
			string result;
			string exp_result = "11";
			result = getStringFromFunc(Fraction);

			Assert::AreEqual(exp_result, result);
		}

		TEST_METHOD(TheDenominatorOfTheFractionIsMissing)
		{
			string Fraction = "D/";
			string result;
			string exp_result = "10";
			result = getStringFromFunc(Fraction);

			Assert::AreEqual(exp_result, result);
		}

		TEST_METHOD(LowercaseNumbers)
		{
			string Fraction = "vii/iii";
			string result;
			string exp_result = "8";
			result = getStringFromFunc(Fraction);

			Assert::AreEqual(exp_result, result);
		}

		TEST_METHOD(TheInputIsCorrect)
		{
			string Fraction = "V/X";
			string result;
			string exp_result = "";
			result = getStringFromFunc(Fraction);

			Assert::AreEqual(exp_result, result);
		}

		string getStringFromFunc(string Fraction)
		{
			string string;
			try
			{
				FractionCheck(Fraction);
			}
			catch (Exception& exception)
			{
				string = exception.getErrorCode();
			}			

			return string;
		}
	};
}

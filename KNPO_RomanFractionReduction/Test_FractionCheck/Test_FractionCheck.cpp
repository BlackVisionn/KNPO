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
			string Fraction = " ";
			string result;
			string exp_result = "Введена пустая строка. Код Ошибки: 1";
			result = getStringFromFunc(Fraction);

			Assert::AreEqual(exp_result, result);
		}

		TEST_METHOD(UnacceptableSymbols)
		{
			string Fraction = "ds";
			string result;
			string exp_result = "Введены недопустимые символы. Используйте I, V, X, L, C, D, M для записи римского числа. Код Ошибки: 2";
			result = getStringFromFunc(Fraction);

			Assert::AreEqual(exp_result, result);
		}

		TEST_METHOD(InvalidSignBetweenNumbers)
		{
			string Fraction = "X*V";
			string result;
			string exp_result = "Введены недопустимый символ между числами. Используйте символ деления “/”. Код Ошибки: 3";
			result = getStringFromFunc(Fraction);

			Assert::AreEqual(exp_result, result);
		}

		TEST_METHOD(InvalidStringFormat)
		{
			string Fraction = "X	/	V";
			string result;
			string exp_result = "Неверный формат записи строки. Введите дробь без пробелов и табуляций в формате “Числитель/Знаменатель”. Код Ошибки: 4";
			result = getStringFromFunc(Fraction);

			Assert::AreEqual(exp_result, result);
		}

		TEST_METHOD(TheNumberDoesNotCorrespondRulesForWritingRomanNumerals)
		{
			string Fraction = "IIV";
			string result;
			string exp_result = "Число не соответствует правилам записи римских цифр. Код Ошибки: 5";
			result = getStringFromFunc(Fraction);

			Assert::AreEqual(exp_result, result);
		}

		TEST_METHOD(NumberDoesNotBelongToRange)
		{
			string Fraction = "MMMMMMMMMMI";
			string result;
			string exp_result = "Число не принадлежит диапазону [1 … 10000]. Код Ошибки: 6";
			result = getStringFromFunc(Fraction);

			Assert::AreEqual(exp_result, result);
		}

		TEST_METHOD(TheDenominatorOfTheFractionIsMissing)
		{
			string Fraction = "D";
			string result;
			string exp_result = "Отсутствует знаменатель дроби. Введите дробь без пробелов и табуляций в формате “Числитель/Знаменатель”. Код Ошибки: 7";
			result = getStringFromFunc(Fraction);

			Assert::AreEqual(exp_result, result);
		}

		TEST_METHOD(LowercaseNumbers)
		{
			string Fraction = "vii/iii";
			string result;
			string exp_result = "Введены недопустимые символы. Используйте I, V, X, L, C, D, M для записи римского числа. Код Ошибки: 8";
			result = getStringFromFunc(Fraction);

			Assert::AreEqual(exp_result, result);
		}

		TEST_METHOD(TheInputIsCorrect)
		{
			string Fraction = "V/X";
			string result;
			string exp_result = "V/X";
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
				string = string + exception.what() + ". " + "Код ошибки: " + exception.getErrorCode();

			}
			string = FractionCheck(Fraction);

			return string;
		}
	};
}

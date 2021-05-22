#include "pch.h"
#include "CppUnitTest.h"
#include "../RomanFractionReduction/Prototypes.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestFormationOfAbbreviatedRomanFraction
{
	TEST_CLASS(TestFormationOfAbbreviatedRomanFraction)
	{
	public:

		TEST_METHOD(NumeratorIsLessThanDenominatorAndFractionIsNotReduced)
		{
			string fraction = "II/V";
			string reductedRomanFraction;
			string exp_reductedRomanFraction = "II/V";
			reductedRomanFraction = FormationOfAbbreviatedRomanFraction(fraction);

			Assert::AreEqual(exp_reductedRomanFraction, reductedRomanFraction);
		}

		TEST_METHOD(NumeratorIsGreaterThanDenominatorAndFractionIsReduced)
		{
			string fraction = "";
			string reductedRomanFraction;
			string exp_reductedRomanFraction = "";
			reductedRomanFraction = FormationOfAbbreviatedRomanFraction(fraction);

			Assert::AreEqual(exp_reductedRomanFraction, reductedRomanFraction);

		}

		TEST_METHOD(NumeratorIsGreaterThanDenominatorAndFractionIsNotReduced)
		{
			string fraction = "XII/V";
			string reductedRomanFraction;
			string exp_reductedRomanFraction = "XII/V";
			reductedRomanFraction = FormationOfAbbreviatedRomanFraction(fraction);

			Assert::AreEqual(exp_reductedRomanFraction, reductedRomanFraction);

		}

		TEST_METHOD(NumeratorAndDenominatorOfTheFractionAreEqual)
		{
			string fraction = "IV/IV";
			string reductedRomanFraction;
			string exp_reductedRomanFraction = "I";
			reductedRomanFraction = FormationOfAbbreviatedRomanFraction(fraction);

			Assert::AreEqual(exp_reductedRomanFraction, reductedRomanFraction);

		}

		TEST_METHOD(FractionDoesNotRequireReduction)
		{
			string fraction = "IX/I";
			string reductedRomanFraction;
			string exp_reductedRomanFraction = "IX";
			reductedRomanFraction = FormationOfAbbreviatedRomanFraction(fraction);

			Assert::AreEqual(exp_reductedRomanFraction, reductedRomanFraction);

		}

		TEST_METHOD(NumeratorIsLessThanDenominatorAndFractionIsReduced)
		{
			string fraction = "VI/XII";
			string reductedRomanFraction;
			string exp_reductedRomanFraction = "I/II";
			reductedRomanFraction = FormationOfAbbreviatedRomanFraction(fraction);

			Assert::AreEqual(exp_reductedRomanFraction, reductedRomanFraction);

		}
	};
}

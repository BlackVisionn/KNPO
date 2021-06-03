#pragma once
using namespace std;
/*! Перевод римского числа в арабское
	\param[in] RimNumber строка содержащая число в римской системе счисления
	\param[out] ArabiсNumber арабское число переведеденное из римской системы счисления
*/
int ConvertToArabicNumber(string RimNumber);

/*! Сокращение дроби
	\param[in] numerator числитель дроби
	\param[in] denominator знаменатель дроби
	\param[out] массив arr заполненый сокращенными числами
*/
void FractionReduction(int arr[], int Numerator, int Denominator);

/*! Перевод арабского числа в римское
	\param[in] ArabicNumber число записанное в арабской системе счисления
	\param[out] RimNumber строка содержащая римское число переведенное из арабской системы счисления
*/
string ConvertToRimNumber(int ArabicNumber);


/*! Формирование сокращенной римской дроби
	\param[in] RimNumber строка которую ввел пользователь
	\param[out] FinalFraction сокращенная дробь в римской системе счисления, записанная в виде строки
*/
string FormationOfAbbreviatedRomanFraction(string Fraction);

/*! Проверка наличия и корректности дроби
	\param[in] Fraction строка которую ввел пользователь
	\param[out] Fraction если содержимое прошло проверку или Error если содержимое не соответсвует заданному формату
*/
string FractionCheck(string Fraction);

/*! Считывание входных данных с txt файла по заданному пользователем пути
	\param[in] path путь расположения txt файла
	\param[out] Fraction строка которую ввел пользователь
*/
string readFile(string path);

/*! Запись результата выполнения программы в txt файл
	\param[in] FinalFraction результат выполнения программы
*/
void writeToFile(string Result, string pathOut);

class Exception :public exception
{
public:
	Exception(const char* msg, string errorCode) :exception(msg)
	{
		this->errorCode = errorCode;
	}
	string getErrorCode()
	{
		return errorCode;
	}

private:
	string errorCode;
};
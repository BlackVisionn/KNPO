#include <iostream>
#include <string>
#include <fstream>
#include "Prototypes.h"
#include <Windows.h>
using namespace std;
int main(int argc, char* argv[])
{
    SetConsoleCP(1251); // Установка кодовой страницы win-cp 1251 в поток ввода
    SetConsoleOutputCP(1251); // Установка кодовой страницы win-cp 1251 в поток вывода    
    string Fraction; // Римская дробь
    string ErrorMessage; // Сообщение об ошибке
    
    try
    {
        if (argc == 3)
        {
            /// Считывание входных данных из файла   
            Fraction = readFile(argv[1]);      

            /// Проверка правильности введенной дроби
            FractionCheck(Fraction);

            /// Сокращение римской дроби
            Fraction = FormationOfAbbreviatedRomanFraction(Fraction);

            /// Запись результата выполнения программы в файл
            writeToFile(Fraction, argv[2]); 
        }
        else
        {
            throw Exception("Отсутствует нужное кол-во аргументов командной строки", "0");
        }
    }
    catch (Exception& exception)
    {
        /// Если коды ошибок равны ошибкам считывания и записи в файл, то выводим ошибку в консоль
        if (exception.getErrorCode() == "0" || exception.getErrorCode() == "1" || exception.getErrorCode() == "2" || exception.getErrorCode() == "3" || exception.getErrorCode() == "4")
        {
            cout << exception.what() << ". " << "Код ошибки: " << exception.getErrorCode();
            return 0;
        }
        /// Запись ошибки проверки дроби в файл
        else
        {
            ErrorMessage = ErrorMessage + exception.what() + ". " + "Код ошибки: " + exception.getErrorCode();
            writeToFile(ErrorMessage, argv[2]);
        }
    }

    return 0;

}

/// Сокращение дроби
void FractionReduction(int arr[], int numerator, int denominator)
{
    int remainder; // Остаток от деления
    int NOD; // Наибольший общий делитель
    int a = numerator; // Числитель
    int b = denominator; // Знаменатель

    /// Нахождение НОД
    /// Пока остаток от деления не будет равен 0
    while (b)
    {
        /// Получаем остаток от деления
        remainder = a % b;
        /// Числитель заменяем на знаменатель
        a = b;
        /// Знаменатель заменяем на остаток от деления
        b = remainder;
    }
    NOD = a; // Найденный НОД

    /// Сокращаем числитель
    arr[0] = numerator / NOD;

    /// Сокращаем знаменатель
    arr[1] = denominator / NOD;

}

/// Считывание входных данных с txt файла по заданному пользователем пути
string readFile(string path)
{
    string fileExtension; // Расширение файла
    const string exp_fileExtension = ".txt"; // Ожидаемое расширение файла
    string Text; // Текст получаемый из файла
    string Fraction; // Полученное содержимое файла

    /// У файла отсутствует расширение
    if (path.find(".txt") == string::npos)
    {
        throw Exception("Отсутствует нужное расширение файла", "1");
    }
    /// Получение расширения файла
    else
    {
        fileExtension = path.substr(path.find_last_of('.'));
    }    

    /// Было неверно указано расширение файла
    if (exp_fileExtension != fileExtension)
    {
        throw Exception("Неверно указано расширение файла. Файл должен иметь расширение .txt", "2");        
    }

    /// Считывание содержимого из файла
    ifstream readFile(path); 
    if (!readFile.is_open()) // Неверный путь к файлу
    {
        throw Exception("Неверно указан файл с входными данными. Возможно файл не существует", "3");        
    }
    /// Непосредственно считывание данных из файла
    else
    {
        getline(readFile, Text);

        Fraction += Text;         
    }
    /// Сокращаем знаменатель
    readFile.close();

    /// Полученное содержимое файла 
    return Fraction;

}

/// Запись результата выполнения программы в txt файл
void writeToFile(string Result, string pathOut)
{
    string file_Extension; // Расширение файла
    const string exp_fileExtension = ".txt"; // Ожидаемое расширение файла

     /// У файла отсутствует расширение 
    if (pathOut.find(".txt") == string::npos)
    {
        throw Exception("Отсутствует нужное расширение файла", "1");
    }    
    /// Получение расширения файла
    else
    {
        file_Extension = pathOut.substr(pathOut.find_last_of('.'));
    }

    /// Было неверно указано расширение файла
    if (exp_fileExtension != file_Extension)
    {
        throw Exception("Неверно указано расширение файла. Файл должен иметь расширение .txt", "2");
    }

    /// Запись результата работы программы в файл
    ofstream writeFile;
    writeFile.open(pathOut);
    /// Неверный путь к файлу
    if (!writeFile.is_open())
    {
        throw Exception("Неверно указан файл с выходными данными. Возможно файл не существует", "4");
    }
    /// Непосредственно запись результата работы программы в файл
    else
    {
        writeFile << Result;
    }
    /// Закрытие файла
    writeFile.close();
}

/// Перевод римского числа в арабское
int ConvertToArabicNumber(string RimNumber)
{
    int ArabicNumber = 0;

    for (int i = 0; i < RimNumber.length(); i++)
    {
        /// Увеличить арабское число на 1, если встретился символ I
        if (RimNumber[i] == 'I')
        {
            ArabicNumber += 1;
            /// Увеличить арабское число на 3, если следующий символ V
            if (RimNumber[i + 1] == 'V')
            {
                ArabicNumber += 3;
                i++;
                continue;
            }
            /// Увеличить арабское число на 8, если следующий символ X
            if (RimNumber[i + 1] == 'X')
            {
                ArabicNumber += 8;
                i++;
                continue;
            }
        }

        /// Увеличить арабское число на 5, если встретился символ V
        if (RimNumber[i] == 'V')
        {
            ArabicNumber += 5;            
        }

        /// Увеличить арабское число на 10, если встретился символ X
        if (RimNumber[i] == 'X')
        {
            ArabicNumber += 10;
           
            /// Увеличить арабское число на 30, если следующий символ L
            if (RimNumber[i + 1] == 'L')
            {
                ArabicNumber += 30;
                i++;
                continue;
            }
            /// Увеличить арабское число на 80, если следующий символ C
            if (RimNumber[i + 1] == 'C')
            {
                ArabicNumber += 80;
                i++;
                continue;
            }
        }

        /// Увеличить арабское число на 50, если встретился символ L
        if (RimNumber[i] == 'L')
        {
            ArabicNumber += 50;            
        }

        /// Увеличить арабское число на 100, если встретился символ C
        if (RimNumber[i] == 'C')
        {
            ArabicNumber += 100;            

            /// Увеличить арабское число на 300, если следующий символ D
            if (RimNumber[i + 1] == 'D')
            {
                ArabicNumber += 300;
                i++;
                continue;
            }
            /// Увеличить арабское число на 800, если следующий символ M
            if (RimNumber[i + 1] == 'M')
            {
                ArabicNumber += 800;
                i++;
                continue;
            }
        }

        /// Увеличить арабское число на 500, если встретился символ D       
        if (RimNumber[i] == 'D')
        {
            ArabicNumber += 500;            
        }

        /// Увеличить арабское число на 1000, если встретился символ M
        if (RimNumber[i] == 'M')
        {
            ArabicNumber += 1000;            
        }
    }   

    return ArabicNumber;
}

/// Перевод арабского числа в римское
string ConvertToRimNumber(int ArabicNumber)
{
    string RimNumber;    
    int discharges[4] = {}; // массив разрядов числа
    int k = 1000;
    int m = 0;
    int casenum;
    /// Разбиение числа на разряды тысяч, сотен, десяток , единиц и запись в массив кажжого разряда
    for (int i = 0; i < 4; i++)
    {
        /// Получение соответсвующего разряда, если у числа не будет определенный разряд (Наример разряд тысяч), то в массив будет записан ноль
        discharges[i] = ArabicNumber / k;
        /// Делим текущее число на 1000 и заменяем текущее число на остаток от деления, тем самым убрав разряд тысяч (в дальнейшем сотен, десяток и единиц)
        ArabicNumber %= k;
        /// Уменьшаем 1000 в 10 раз
        k = k / 10;
    }
    /// Замена отсутсвующих разрядов на -1
    for (int i = 0; i < 4; i++)
    {
        if (discharges[i] == 0)
        {
            discharges[i] = -1;
        }
        else
        {
            break;            
        }
    }

    /// Если разряд тысяч присутствует (не является -1), то переходим к переводу числа с  момента перевода разряда тысяч
    if (discharges[0] != -1)
    {
        casenum = 1;
    }
    /// Если разряд сотен присутствует (не является -1), то переходим к переводу числа с  момента перевода разряда сотен
    else if (discharges[1] != -1)
    {
        casenum = 2;
        m += 1;
    }
    /// Если разряд десятых присутствует (не является -1), то переходим к переводу числа с  момента перевода разряда десятых
    else if (discharges[2] != -1)
    {
        casenum = 3;
        m += 2;
    }
    /// Если разряд единиц присутствует (не является -1), то переходим к переводу числа с  момента перевода разряда единиц
    else if (discharges[3] != -1)
    {
        casenum = 4;
        m += 3;
    }

    switch (casenum)
    {
        /// Разряд тысяч
    case 1:
        /// Добавляем цифру M столько раз сколько указано в массиве в разряде тысяч
        for (int i = 0; i < discharges[0]; i++)
        {
            RimNumber += "M";
        }
        m++;
        
            /// Разряд сотен
    case 2:

        /// Если разряд равен 4 то добавляем CD в строку и текущий разряд обнуляем
        if (discharges[m] == 4)
        {
            discharges[m] = 0;
            RimNumber += "CD";
        }
        /// Если разряд равен 9 то добавляем XC в строку и текущий разряд обнуляем
        if (discharges[m] == 9)
        {
            discharges[m] = 0;
            RimNumber += "CM";
        }
        /// Если разряд больше или равен  5 и не равен 9, то добавляем D в строку и текущий разряд уменьшаем на 5
        if (discharges[m] >= 5 && discharges[m] != 9)
        {
            RimNumber += "D";
            discharges[m] = discharges[m] - 5;
        }
        /// Цикл который добавляет цифру C столько раз сколько указано в массиве в разряде сотен
        for (int i = 0; i < discharges[m]; i++)
        {
            RimNumber += "C";
        }
        m++;
        
            /// Разряд десятых
    case 3:

        /// Если разряд равен 4 то добавляем XL в строку и текущий разряд обнуляем
        if (discharges[m] == 4)
        {
            discharges[m] = 0;
            RimNumber += "XL";
        }
        /// Если разряд равен 9 то добавляем XC в строку и текущий разряд обнуляем
        if (discharges[m] == 9)
        {
            discharges[m] = 0;
            RimNumber += "XC";
        }
        /// Если разряд больше или равен  5 и не равен 9, то добавляем L в строку и текущий разряд уменьшаем на 5
        if (discharges[m] >= 5 && discharges[m] != 9)
        {
            RimNumber += "L";
            discharges[m] = discharges[m] - 5;
        }
        /// Цикл который добавляет цифру X столько раз сколько указано в массиве в разряде десятых
        for (int i = 0; i < discharges[m]; i++)
        {
            RimNumber += "X";
        }

        m++;
        
            /// Разряд единиц
    case 4:
        /// Если разряд равен 4 то добавляем IV в строку и текущий разряд обнуляем
        if (discharges[m] == 4)
        {
            discharges[m] = 0;
            RimNumber += "IV";
        }
        /// Если разряд равен 9 то добавляем IX в строку и текущий разряд обнуляем
        if (discharges[m] == 9)
        {
            discharges[m] = 0;
            RimNumber += "IX";
        }
        /// Если разряд больше или равен  5 и не равен 9 или 4, то добавляем V в строку и текущий разряд уменьшаем на 5
        if (discharges[m] >= 5 && discharges[m] != 9)
        {
            RimNumber += "V";
            discharges[m] = discharges[m] - 5;
        }
        /// Цикл который добавляет цифру I столько раз сколько указано в массиве в разряде единиц
        for (int i = 0; i < discharges[m]; i++)
        {
            RimNumber += "I";
        }
        
    }

    return RimNumber;
}

/// Формирование сокращенной римской дроби
string FormationOfAbbreviatedRomanFraction(string Fraction)
{
    string RimNumerator; // Числитель в римской системе счисления
    string RimDenominator; // Знаменатель в римской системе счисления
    string AbbreviatedFraction; // Сокращенная дробь в римской системе счисления
    int ArabicNumerator; // Числитель в арабской системе счисления
    int ArabicDenominator; // Знаменатель в арабской системе счисления
    int AbbreviatedValues[2] = {}; // Массив хранящий сокращенные значения числителя и знаменателя
    

    RimNumerator = Fraction.substr(0, Fraction.find('/')); // Числитель дроби в римской системе счисления
    RimDenominator = Fraction.substr(Fraction.find('/') + 1); // Знаменатель дроби в римской системе счисления

    /// Перевод числителя и знаменателя в арабскую систему счисления
    ArabicNumerator = ConvertToArabicNumber(RimNumerator);

    ArabicDenominator = ConvertToArabicNumber(RimDenominator);

    /// Сокращение числителя и знаменателя дроби
    FractionReduction(AbbreviatedValues, ArabicNumerator, ArabicDenominator);

    /// Присвоение сокращенных значений числителя и знаменателя
    ArabicNumerator = AbbreviatedValues[0];
    ArabicDenominator = AbbreviatedValues[1];
    
    /// Если после сокращения знаменатель 1
    if (ArabicDenominator == 1)
    {
        /// Перевести числитель в римскую систему счисления
        RimNumerator = ConvertToRimNumber(ArabicNumerator);

        /// Сбор сокращенной дроби в римской системе счисления
        AbbreviatedFraction += RimNumerator;
    }
    else
    {
        /// Перевод числителя и знаменателя в римскую систему счисления
        RimNumerator = ConvertToRimNumber(ArabicNumerator);
        
        RimDenominator = ConvertToRimNumber(ArabicDenominator);

        /// Сбор сокращенной дроби в римской системе счисления
        AbbreviatedFraction += RimNumerator + '/' + RimDenominator;
    }
    
    return AbbreviatedFraction;
}

/// Проверка наличия и корректности дроби
void FractionCheck(string Fraction)
{   
    string numerator; // Числитель
    string denominator; // Знаменатель
    int countM = 0; // Кол-во символов M


    numerator = Fraction.substr(0, Fraction.find('/'));
    denominator = Fraction.substr(Fraction.find('/') + 1);

    /// Исключение, если строка пустая
    if (Fraction.empty())
    {
        throw Exception("Неудалось обнаружить дробь", "5");
    }

    /// Исключение, если отсутсвует знак деления между римскими числами
    if (Fraction.find("/") == string::npos)
    {
        throw Exception("Отсутствует знак деления между римскими числами", "6");
    }

    /// Исключение, если присутсвуют пробелы
    for (int i = 0; i < Fraction.length(); i++)
    {
        if (Fraction[i] == ' ')
        {
            throw Exception("Неверный формат записи строки. Введите дробь без пробелов и табуляций в формате “Числитель/Знаменатель”", "7");
        }
    }

    /// Исключение, если найден неизвестный символ
    for (int i = 0; i < Fraction.length(); i++)
    {
        if ((Fraction[i] != 'I') && (Fraction[i] != 'V') && (Fraction[i] != 'X') && (Fraction[i] != 'L') && (Fraction[i] != 'C') && (Fraction[i] != 'D') && (Fraction[i] != 'M') && (Fraction[i] != '/'))
        {
            throw Exception("Введены недопустимые символы. Используйте I, V, X, L, C, D, M для записи римского числа", "8");
        }
    }

    /// Исключение, если отсутствует числитель или знаменатель дроби
    for (int i = 0; i < Fraction.length(); i++)
    {
        // Отсутсвует числитель дроби
        if (i == 0 && Fraction[i] == '/')
        {
            throw Exception("Отсутствует числитель дроби.Введите дробь без пробелов и табуляций в формате “Числитель / Знаменатель”", "9");
        }
        // Отсутсвует знаменатель дроби
        if (Fraction[i] == '/' && Fraction[i + 1] == '\0')
        {
            throw Exception("Отсутствует знаменатель дроби. Введите дробь без пробелов и табуляций в формате “Числитель/Знаменатель”", "10");
        }
    }

    /// Исключение, если число вышло за пределы
    for (int i = 0; i < Fraction.length(); i++)
    {
        if (Fraction[i] == 'M')
        {
            countM++;
            if (countM == 10 && Fraction[i + 1] != '/' && Fraction[i + 1] != '\0')
            {
                throw Exception("Число не принадлежит диапазону [1 … 10000]", "11");
            }
        }
    }

    /// Исключение, если введены неверные сочетания с цифрами I, V, X, L, D
    if (Fraction.find("IL") != -1 || Fraction.find("IC") != string::npos || Fraction.find("ID") != string::npos || Fraction.find("IM") != string::npos || Fraction.find("VV") != string::npos || Fraction.find("VX") != string::npos || Fraction.find("VL") != string::npos || Fraction.find("VC") != string::npos || Fraction.find("VD") != string::npos || Fraction.find("VM") != string::npos || Fraction.find("XD") != string::npos || Fraction.find("XM") != string::npos || Fraction.find("LL") != string::npos || Fraction.find("LC") != string::npos || Fraction.find("LD") != string::npos || Fraction.find("LM") != string::npos || Fraction.find("DD") != string::npos || Fraction.find("DM") != string::npos)
    {
        throw Exception("Число не соответствует правилам записи римских цифр", "12");
    }

    /// Исключение, если введены неверные сочетания с цифрами больше одного I или X или C перед числами
    if (Fraction.find("IIV") != string::npos || Fraction.find("IIX") != string::npos || Fraction.find("XXL") != string::npos || Fraction.find("XXC") != string::npos || Fraction.find("CCD") != string::npos || Fraction.find("CCM") != string::npos)
    {
        throw Exception("Число не соответствует правилам записи римских цифр", "12");
    }
    /// Исключение, если цифра записана больше 3-х раз подряд 
    if (Fraction.find("IIII") != string::npos || Fraction.find("XXXX") != string::npos || Fraction.find("CCCC") != string::npos)
    {
        throw Exception("Число не соответствует правилам записи римских цифр", "12");
    }    
}

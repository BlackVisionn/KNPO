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
            Fraction = readFile(argv[1]); // Считывание входных данных из файла       

            FractionCheck(Fraction); // Проверка правильности введенной дроби

            Fraction = FormationOfAbbreviatedRomanFraction(Fraction); // Сокращение римской дроби

            writeToFile(Fraction, argv[2]); // Запись результата выполнения программы в файл
        }
        else
        {
            throw Exception("Отсутствует нужное кол-во аргументов командной строки.", "0");
        }
    }
    catch (Exception& exception)
    {
        // Если коды ошибок равны ошибкам считывания и записи в файл, то выводим ошибку в консоль
        if (exception.getErrorCode() == "0" || exception.getErrorCode() == "1" || exception.getErrorCode() == "2" || exception.getErrorCode() == "3" || exception.getErrorCode() == "4")
        {
            cout << exception.what() << ". " << "Код ошибки: " << exception.getErrorCode();
            return 0;
        }
        // Запись ошибки проверки дроби в файл
        else
        {
            ErrorMessage = ErrorMessage + exception.what() + ". " + "Код ошибки: " + exception.getErrorCode();
            writeToFile(ErrorMessage, argv[2]);
        }
    }

    return 0;

}

/*! Сокращение дроби
    \param[in] numerator числитель дроби
    \param[in] denominator знаменатель дроби
    \param[out] массив arr заполненый сокращенными числами
*/
void FractionReduction(int arr[], int numerator, int denominator)
{
    int remainder; // Остаток от деления
    int NOD; // Наибольший общий делитель
    int a = numerator; // Числитель
    int b = denominator; // Знаменатель

    // Нахождение НОД
    while (b) // Пока остаток от деления не будет равен 0
    {
        remainder = a % b; // Получаем остаток от деления
        a = b; // Числитель заменяем на знаменатель
        b = remainder; // Знаменатель заменяем на остаток от деления
    }
    NOD = a; // Найденный НОД
    arr[0] = numerator / NOD; // Сокращаем числитель
    arr[1] = denominator / NOD; // Сокращаем знаменатель

}

/*! Считывание входных данных с txt файла по заданному пользователем пути
    \param[in] path путь расположения txt файла
    \param[out] Fraction строка которую ввел пользователь
*/
string readFile(string path)
{
    string fileExtension; // Расширение файла
    const string exp_fileExtension = ".txt"; // Ожидаемое расширение файла
    string Text; // Текст получаемый из файла
    string Fraction; // Полученное содержимое файла

    // У файла отсутствует расширение
    if (path.find(".txt") == string::npos)
    {
        throw Exception("Отсутствует нужное расширение файла.", "1");
    }
    // Получение расширения файла
    else
    {
        fileExtension = path.substr(path.find_last_of('.'));
    }    

    // Было неверно указано расширение файла
    if (exp_fileExtension != fileExtension)
    {
        throw Exception("Неверно указано расширение файла. Файл должен иметь расширение .txt", "2");        
    }

    // Считывание содержимого из файла
    ifstream readFile(path); 
    if (!readFile.is_open()) // Неверный путь к файлу
    {
        throw Exception("Неверно указан файл с входными данными. Возможно файл не существует", "3");        
    }
    // Непосредственно считывание данных из файла
    else
    {
        getline(readFile, Text);

        Fraction += Text;         
    }
    readFile.close(); // Закрытие файла

    return Fraction; // Полученное содержимое файла 

}

/*! Запись результата выполнения программы в txt файл
    \param[in] FinalFraction результат выполнения программы
*/
void writeToFile(string Result, string pathOut)
{
    string file_Extension; // Расширение файла
    const string exp_fileExtension = ".txt"; // Ожидаемое расширение файла

     // У файла отсутствует расширение 
    if (pathOut.find(".txt") == string::npos)
    {
        throw Exception("Отсутствует нужное расширение файла. Код ошибки: ", "1");
    }    
    // Получение расширения файла
    else
    {
        file_Extension = pathOut.substr(pathOut.find_last_of('.'));
    }

    // Было неверно указано расширение файла
    if (exp_fileExtension != file_Extension)
    {
        throw Exception("Неверно указано расширение файла. Файл должен иметь расширение .txt", "2");
    }

    // Запись результата работы программы в файл
    ofstream writeFile;
    writeFile.open(pathOut);
    if (!writeFile.is_open()) // Неверный путь к файлу
    {
        throw Exception("Неверно указан файл с выходными данными. Возможно файл не существует", "4");
    }
    // Непосредственно запись результата работы программы в файл
    else
    {
        writeFile << Result;
    }
    writeFile.close(); // Закрытие файла
}

/*! Перевод римского числа в арабское
    \param[in] RimNumber строка содержащая число в римской системе счисления
    \param[out] ArabiсNumber арабское число переведеденное из римской системы счисления
*/
int ConvertToArabicNumber(string RimNumber)
{
    int ArabicNumber = 0;

    for (int i = 0; i < RimNumber.length(); i++)
    {
        //Если встретился символ I
        if (RimNumber[i] == 'I')
        {
            ArabicNumber += 1;
            if (RimNumber[i + 1] == 'V')
            {
                ArabicNumber += 3;
                i++;
                continue;
            }
            if (RimNumber[i + 1] == 'X')
            {
                ArabicNumber += 8;
                i++;
                continue;
            }
        }

        //Если встретился символ V
        if (RimNumber[i] == 'V')
        {
            ArabicNumber += 5;            
        }

        //Если встретился символ X
        if (RimNumber[i] == 'X')
        {
            ArabicNumber += 10;
           
            //Если следующий элемент 50
            if (RimNumber[i + 1] == 'L')
            {
                ArabicNumber += 30;
                i++;
                continue;
            }
            //Если следующий элемент 100
            if (RimNumber[i + 1] == 'C')
            {
                ArabicNumber += 80;
                i++;
                continue;
            }
        }

        //Если встретился символ L
        if (RimNumber[i] == 'L')
        {
            ArabicNumber += 50;            
        }

        //Если встретился символ C
        if (RimNumber[i] == 'C')
        {
            ArabicNumber += 100;            

            //Если следующий элемент 500
            if (RimNumber[i + 1] == 'D')
            {
                ArabicNumber += 300;
                i++;
                continue;
            }
            //Если следующий элемент 1000
            if (RimNumber[i + 1] == 'M')
            {
                ArabicNumber += 800;
                i++;
                continue;
            }
        }

        //Если встретился символ D        
        if (RimNumber[i] == 'D')
        {
            ArabicNumber += 500;            
        }

        //Если встретился символ M
        if (RimNumber[i] == 'M')
        {
            ArabicNumber += 1000;            
        }
    }   

    return ArabicNumber;
}

/*! Перевод арабского числа в римское
    \param[in] ArabicNumber число записанное в арабской системе счисления
    \param[out] RimNumber строка содержащая римское число переведенное из арабской системы счисления
*/
string ConvertToRimNumber(int ArabicNumber)
{
    string RimNumber;
    //int ArabicNumber = num;
    int discharges[4] = {}; // массив разрядов числа
    int k = 1000;
    int m = 0;
    int casenum;
    // Разбиение числа на разряды тысяч, сотен, десяток , единиц и запись в массив кажжого разряда
    for (int i = 0; i < 4; i++)
    {
        discharges[i] = ArabicNumber / k; // Получение соответсвующего разряда, если у числа не будет определенный разряд (Наример разряд тысяч), то в массив будет записан ноль
        ArabicNumber %= k; //  Делим текущее число на 1000 и заменяем текущее число на остаток от деления, тем самым убрав разряд тысяч (в дальнейшем сотен, десяток и единиц)
        k = k / 10; //Уменьшаем 1000 в 10 раз
    }
    // Замена отсутсвующих разрядов на -1
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

    // Если разряд тысяч присутствует (не является -1), то переходим к переводу числа с  момента перевода разряда тысяч
    if (discharges[0] != -1)
    {
        casenum = 1;
    }
    // Если разряд сотен присутствует (не является -1), то переходим к переводу числа с  момента перевода разряда сотен
    else if (discharges[1] != -1)
    {
        casenum = 2;
        m += 1;
    }
    // Если разряд десятых присутствует (не является -1), то переходим к переводу числа с  момента перевода разряда десятых
    else if (discharges[2] != -1)
    {
        casenum = 3;
        m += 2;
    }
    // Если разряд единиц присутствует (не является -1), то переходим к переводу числа с  момента перевода разряда единиц
    else if (discharges[3] != -1)
    {
        casenum = 4;
        m += 3;
    }

    switch (casenum)
    {
        // Разряд тысяч
    case 1:
        // Добавляем цифру M столько раз сколько указано в массиве в разряде тысяч
        for (int i = 0; i < discharges[0]; i++)
        {
            RimNumber += "M";
        }
        m++;
        if (discharges[m] != -1)
        {
            // Разряд сотен
    case 2:

        // Если разряд равен 4 то добавляем CD в строку и текущий разряд обнуляем
        if (discharges[m] == 4)
        {
            discharges[m] = discharges[m] - 4;
            RimNumber += "CD";
        }
        // Если разряд равен 9 то добавляем XC в строку и текущий разряд обнуляем
        if (discharges[m] == 9)
        {
            discharges[m] = discharges[m] - 9;
            RimNumber += "CM";
        }
        // Если разряд больше или равен  5 и не равен 9 или 4, то добавляем D в строку и текущий разряд уменьшаем на 5
        if (discharges[m] >= 5 && discharges[m] != (9 || 4))
        {
            RimNumber += "D";
            discharges[m] = discharges[m] - 5;
        }
        // Цикл который добавляет цифру C столько раз сколько указано в массиве в разряде сотен
        for (int i = 0; i < discharges[m]; i++)
        {
            RimNumber += "C";
        }
        m++;

        if (discharges[m] != -1)
        {
            // Разряд десятых
    case 3:

        // Если разряд равен 4 то добавляем XL в строку и текущий разряд обнуляем
        if (discharges[m] == 4)
        {
            discharges[m] = discharges[m] - 4;
            RimNumber += "XL";
        }
        // Если разряд равен 9 то добавляем XC в строку и текущий разряд обнуляем
        if (discharges[m] == 9)
        {
            discharges[m] = discharges[m] - 9;
            RimNumber += "XC";
        }
        // Если разряд больше или равен  5 и не равен 9 или 4, то добавляем L в строку и текущий разряд уменьшаем на 5
        if (discharges[m] >= 5 && discharges[m] != (9 || 4))
        {
            RimNumber += "L";
            discharges[m] = discharges[m] - 5;
        }
        // Цикл который добавляет цифру X столько раз сколько указано в массиве в разряде десятых
        for (int i = 0; i < discharges[m]; i++)
        {
            RimNumber += "X";
        }

        m++;
        if (discharges[m] != -1)
        {
            // Разряд единиц
    case 4:
        // Если разряд равен 4 то добавляем IV в строку и текущий разряд обнуляем
        if (discharges[m] == 4)
        {
            discharges[m] = discharges[m] - 4;
            RimNumber += "IV";
        }
        // Если разряд равен 9 то добавляем IX в строку и текущий разряд обнуляем
        if (discharges[m] == 9)
        {
            discharges[m] = discharges[m] - 9;
            RimNumber += "IX";
        }
        // Если разряд больше или равен  5 и не равен 9 или 4, то добавляем V в строку и текущий разряд уменьшаем на 5
        if (discharges[m] >= 5 && discharges[m] != (9 || 4))
        {
            RimNumber += "V";
            discharges[m] = discharges[m] - 5;
        }
        // Цикл который добавляет цифру I столько раз сколько указано в массиве в разряде единиц
        for (int i = 0; i < discharges[m]; i++)
        {
            RimNumber += "I";
        }
        }
        }
        }
    }

    return RimNumber;
}

/*! Формирование сокращенной римской дроби
    \param[in] RimNumber строка которую ввел пользователь
    \param[out] FinalFraction сокращенная дробь в римской системе счисления, записанная в виде строки
*/
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

    // Перевод числителя и знаменателя в арабскую систему счисления
    ArabicNumerator = ConvertToArabicNumber(RimNumerator);

    ArabicDenominator = ConvertToArabicNumber(RimDenominator);

    // Сокращение числителя и знаменателя дроби
    FractionReduction(AbbreviatedValues, ArabicNumerator, ArabicDenominator);

    // Присвоение сокращенных значений числителя и знаменателя
    ArabicNumerator = AbbreviatedValues[0];
    ArabicDenominator = AbbreviatedValues[1];
    
    // Если после сокращения знаменатель 1
    if (ArabicDenominator == 1)
    {
        // Перевести числитель в римскую систему счисления
        RimNumerator = ConvertToRimNumber(ArabicNumerator);

        // Сбор сокращенной дроби в римской системе счисления
        AbbreviatedFraction += RimNumerator;
    }
    else
    {
        // Перевод числителя и знаменателя в римскую систему счисления
        RimNumerator = ConvertToRimNumber(ArabicNumerator);
        
        RimDenominator = ConvertToRimNumber(ArabicDenominator);

        // Сбор сокращенной дроби в римской системе счисления
        AbbreviatedFraction += RimNumerator + '/' + RimDenominator;
    }
    
    return AbbreviatedFraction;
}

/*! Проверка наличия и корректности дроби
    \param[in] Fraction строка которую ввел пользователь
    \param[out] Fraction если содержимое прошло проверку или Error если содержимое не соответсвует заданному формату
*/
string FractionCheck(string Fraction)
{
    int lenght = Fraction.length(); // Длина строки
    string numerator; // Числитель
    string denominator; // Знаменатель
    int countM = 0; // Кол-во символов M


    numerator = Fraction.substr(0, Fraction.find('/'));
    denominator = Fraction.substr(Fraction.find('/') + 1);

    //Пустая строка
    if (Fraction.empty())
    {
        throw Exception("Неудалось обнаружить дробь", "5");
    }

    //Отсутсвует знак деления между римскими числами
    if (Fraction.find("/") == string::npos)
    {
        throw Exception("Отсутствует знак деления между римскими числами", "6");
    }

    //Присутсвуют пробелы
    for (int i = 0; i < lenght; i++)
    {
        if (Fraction[i] == ' ')
        {
            throw Exception("Неверный формат записи дроби", "7");
        }
    }

    //Неизвестный символ используйте римские числа
    for (int i = 0; i < lenght; i++)
    {
        if ((Fraction[i] != 'I') && (Fraction[i] != 'V') && (Fraction[i] != 'X') && (Fraction[i] != 'L') && (Fraction[i] != 'C') && (Fraction[i] != 'D') && (Fraction[i] != 'M') && (Fraction[i] != '/'))
        {
            throw Exception("Введены недопустимые символы. Используйте I, V, X, L, C, D, M для записи римского числа", "8");
        }
    }

    //Отсутствие числителя или знаменателя дроби
    for (int i = 0; i < lenght; i++)
    {
        //Отсутсвует числитель дроби
        if (Fraction[i] == '/' && Fraction[i - 1] == '\0')
        {
            throw Exception("Отсутсвует числитель дроби", "9");
        }
        //Отсутсвует знаменатель дроби
        if (Fraction[i] == '/' && Fraction[i + 1] == '\0')
        {
            throw Exception("Отсутсвует знаменатель дроби", "10");
        }
    }

    //Выход за пределы
    for (int i = 0; i < lenght; i++)
    {
        if (Fraction[i] == 'M')
        {
            countM++;
            if (countM == 10 && Fraction[i + 1] != '/' && Fraction[i + 1] != '\0')
            {
                throw Exception("Число не принадлежит диапазону [1… 10000]", "11");
            }
        }
    }

    //Неверные сочетания с цифрами I V X L D
    if (Fraction.find("IL") != -1 || Fraction.find("IC") != string::npos || Fraction.find("ID") != string::npos || Fraction.find("IM") != string::npos || Fraction.find("VV") != string::npos || Fraction.find("VX") != string::npos || Fraction.find("VL") != string::npos || Fraction.find("VC") != string::npos || Fraction.find("VD") != string::npos || Fraction.find("VM") != string::npos || Fraction.find("XD") != string::npos || Fraction.find("XM") != string::npos || Fraction.find("LL") != string::npos || Fraction.find("LC") != string::npos || Fraction.find("LD") != string::npos || Fraction.find("LM") != string::npos || Fraction.find("DD") != string::npos || Fraction.find("DM") != string::npos)
    {
        throw Exception("Число не соответствует правилам записи римских цифр", "12");
    }

    //Неверные сочетания с цифрами больше 1-го I X C перед числами
    if (Fraction.find("IIV") != string::npos || Fraction.find("IIX") != string::npos || Fraction.find("XXL") != string::npos || Fraction.find("XXC") != string::npos || Fraction.find("CCD") != string::npos || Fraction.find("CCM") != string::npos)
    {
        throw Exception("Число не соответствует правилам записи римских цифр", "12");
    }
    //Проверка на повтор больше 3-х раз
    if (Fraction.find("IIII") != string::npos || Fraction.find("XXXX") != string::npos || Fraction.find("CCCC") != string::npos)
    {
        throw Exception("Число не соответствует правилам записи римских цифр", "12");
    }

    return Fraction;
}

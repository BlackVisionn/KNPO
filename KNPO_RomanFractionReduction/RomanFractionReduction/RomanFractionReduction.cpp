﻿#include <iostream>
#include <string>
#include <fstream>
#include "Prototypes.h"
#include <Windows.h>
using namespace std;
int main()
{
    SetConsoleCP(1251); // Установка кодовой страницы win-cp 1251 в поток ввода
    SetConsoleOutputCP(1251); // Установка кодовой страницы win-cp 1251 в поток вывода
    string pathIn;
    string pathOut;
    string Fraction;
    cin >> pathIn;
    try
    {
        Fraction = readFile(pathIn);
    }
    catch (Exception& exception)
    {
        cout << exception.what() << ". " << "Код ошибки: " << exception.getErrorCode();
        return 0;
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
        throw Exception("Отсутствует расширение файла", "1");
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
        while (getline(readFile, Text))
        {
            Fraction += Text;
        }
    }
    readFile.close(); // Закрытие файла

    return Fraction; // Полученное содержимое файла 

}

/*! Запись результата выполнения программы в txt файл
    \param[in] FinalFraction результат выполнения программы
*/
void writeToFile(string Result, string pathOut)
{
    string fileExtension; // Расширение файла
    const string exp_fileExtension = ".txt"; // Ожидаемое расширение файла
      
    // У файла отсутствует расширение
    if (pathOut.find(".txt") == string::npos)
    {
        throw Exception("Отсутствует расширение файла", "1");
    }
    // Получение расширения файла
    else
    {
        fileExtension = pathOut.substr(pathOut.find_last_of('.'));
    }

    // Было неверно указано расширение файла
    if (exp_fileExtension != fileExtension)
    {
        throw Exception("Неверно указано расширение файла. Файл должен иметь расширение .txt", "2");
    }

    // Запись результата работы программы в файл
    ofstream writeToFile;
    if (!writeToFile.is_open()) // Неверный путь к файлу
    {
        throw Exception("Неверно указан файл с выходными данными. Возможно файл не существует", "4");
    }
    // Непосредственно запись результата работы программы в файл
    else
    {
        writeToFile << Result;
    }
    writeToFile.close(); // Закрытие файла
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

    // Если разряд тысяч присутствует (не является нулем), то переходим к переводу числа с  момента перевода разряда тысяч
    if (discharges[0] != 0)
    {
        casenum = 1;
    }
    // Если разряд сотен присутствует (не является нулем), то переходим к переводу числа с  момента перевода разряда сотен
    else if (discharges[1] != 0)
    {
        casenum = 2;
        m += 1;
    }
    // Если разряд десятых присутствует (не является нулем), то переходим к переводу числа с  момента перевода разряда десятых
    else if (discharges[2] != 0)
    {
        casenum = 3;
        m += 2;
    }
    // Если разряд единиц присутствует (не является нулем), то переходим к переводу числа с  момента перевода разряда единиц
    else if (discharges[3] != 0)
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
        if (discharges[m] != 0)
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

        if (discharges[m] != 0)
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
        if (discharges[m] != 0)
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

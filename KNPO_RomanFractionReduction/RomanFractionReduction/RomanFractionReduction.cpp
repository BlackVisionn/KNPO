#include <iostream>
#include <string>
#include <fstream>
#include "Prototypes.h"
using namespace std;
int main()
{
    setlocale(LC_ALL, "ru");
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


#include <iostream>
#include <string>
#include "Prototypes.h"
using namespace std;
int main()
{

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
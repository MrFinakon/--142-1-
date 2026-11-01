#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/** @brief считывает с клавиатуры значение с плавающей точкой
 * @return считанное значение
 */
double get_double();

/**
 * @brief вычисляет значение функции Y
 * @param x значение параметра x
 * @param a значение параметра a
 * @return рассчитанное значение
 */
double Y(const double x, const double a);

/**
 * @brief точка входа в программу
 * @return возвращает 0, если программа выполнена корректно
 */
int main()
{
    const double a=1.36;
    printf("Введите значение для переменной x:\n");
    double x=get_double();
    printf("Результат вычислений:%.4lf\n", Y(x,a));
    return 0;
}

double get_double()
{
    double s=0.0;
    if (scanf("%lf",&s)!=1)
    {
        printf("Ошибка: введите число\n");
        exit(1);
    }
    return s;
}

double Y(const double x, const double a)
{
    if (x<0.5)
    {
        return (M_PI/2) + x*a - exp(a*x);
    }
    else
    {
        return pow(x,3)*a + 28;
    }
}
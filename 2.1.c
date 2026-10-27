#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/** @brief считывает с клавиатуры значение с плавающей точкой
 * @return считанное значение
 */
double get_double();

/**
 * @brief проверяет количество отрицательных чисел
 * @param a значение параметра a
 * @param b значение параметра b
 * @param c значение параметра c
 * @return количество отрицательных чисел
 */
int check_negative(const double a, const double b, const double c);

/**
 * @brief вычисляет абсолютное значение суммы чисел
 * @param a значение параметра a
 * @param b значение параметра b
 * @param c значение параметра c
 * @return рассчитанное значение
 */
double abs_sum(const double a, const double b, const double c);

int main()
{
    printf("Введите три числа:\n");
    double a=get_double();
    double b=get_double();
    double c=get_double();
    printf("Количество отрицательных чисел:%d\n",check_negative(a,b,c));
    printf("Абсолютное значение суммы чисел:%lf\n", abs_sum(a,b,c));
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

int check_negative(const double a, const double b, const double c)
{
    int count=0;
    if (a<0) count++;
    if (b<0) count++;
    if (c<0) count++;
    return count;
}

double abs_sum(const double a, const double b, const double c)
{
    return fabs(a+b+c);
}
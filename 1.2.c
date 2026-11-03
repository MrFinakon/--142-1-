#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/** @brief считывает с клавиатуры значение с плавающей точкой
 * @return считанное значение
 */
double get_double();

/**
 * @brief вычисляет скорость лодки по течению
 * @param v-скорость лодки
 * @param v1-скорость течения
 * @return рассчитанное значение
 */
double V2(const double v, const double v1);

/**
 * @brief вычисляет путь ,пройденный лодкой по течению
 * @param V2-скорость лодки по течению
 * @param t-время в пути
 * @return рассчитанное значение
 */
double S(const double V2, const double t);

/**
 * @brief точка входа в программу
 * @return возвращает 0, если программа выполнена корректно
 */
int main()
{
    double v=get_double();
    double v1=get_double();
    double t=get_double();
    printf("Path is: %.2f", S(V2(v, v1),t));
    return 0;
}

double V2(const double v, const double v1)
{
    return v+v1;
}

double S(const double V2, const double t)
{
    return V2*t;
}

double get_double()
{
    double s=0.0;
    if (scanf("%lf",&s)!=1)
        {
            printf("Error");
            exit(1);
        }
    return s;
}

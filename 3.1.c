#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
#include <stdbool.h>

/**
 * @brief считывает с клавиатуры значение с плавающей точкой
 * @return считанное значение
 */
double get_double();

/**
 * @brief проверяет корректность шага табулирования
 * @param step шаг табулирования
 */
void check_step(const double step);

/**
 * @brief проверяет корректность границ отрезка
 * @param x_begin начало отрезка
 * @param x_end конец отрезка
 */
void check_segment(const double x_begin, const double x_end);

/**
 * @brief проверяет, входит ли точка в область определения функции
 * @param x значение аргумента
 * @return true, если функция определена в точке, иначе false
 */
bool is_OOF(const double x);

/**
 * @brief вычисляет значение функции в заданной точке
 * @param x значение аргумента
 * @return рассчитанное значение функции
 */
double get_Y(const double x);

/**
 * @brief точка входа в программу
 * @return возвращает 0, если программа выполнена корректно
 */
int main()
{
    printf("Введите начало отрезка:\n");
    double x_begin=get_double();
    printf("Введите конец отрезка:\n");
    double x_end=get_double();
    printf("Введите шаг:\n");
    double step=get_double();
    check_step(step);
    check_segment(x_begin, x_end);

    for (double x=x_begin; x<x_end+step/2.0; x+=step)
    {
        if (is_OOF(x))
        {
            printf("x=%lf, y=%lf\n",x,get_Y(x));
        }
        else
        {
            printf("x=%lf, y не определено\n",x);
        }
    }
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

void check_step(const double step)
{
    if (step<=0)
    {
        printf("Ошибка: шаг должен быть положительным\n");
        exit(1);
    }
}

void check_segment(const double x_begin, const double x_end)
{
    if (x_begin>x_end)
    {
        printf("Ошибка: начало отрезка должно быть меньше или равно концу отрезка\n");
        exit(1);
    }
}

bool is_OOF(const double x)
{
    return (1.0-x>=-FLT_EPSILON) && (fabs(cos(x))>=FLT_EPSILON);
}

double get_Y(const double x)
{
    return sqrt(1.0-x)-tan(x);
}
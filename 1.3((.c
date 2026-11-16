#include <stdio.h>
#include <math.h>
#include <stdlib.h>

static const int C_STEEL = 500;

/** @brief считывает с клавиатуры значение с плавающей точкой
 * @return считанное значение
 */
double get_double();

/** @brief считывает с клавиатуры значение с плавающей точкой для массы
 * @return считанное значение
 */
double get_mass();

/**
 * @brief вычисляет разницу между t и t0
 * @param t-конечная температура
 * @param t0-начальная температура
 * @return рассчитанное значение
 */
int delta_t(const int t, const int  t0);

/**
 * @brief вычисляет количество теплоты
 * @param m-масса
 * @param c-удельная теплоемкость
 * @param delta_t-разница между t и t0
 * @return рассчитанное значение
 */
double Q(const double m, const int c, const int delta_t);

/**
 * @brief точка входа в программу
 * @return возвращает 0, если программа выполнена корректно
 */
int main()
{
    printf("Введите массу детали:");
    double m=get_mass();
    printf("Введите начальную температуру:");
    int t0=get_double();
    printf("Введите конечную температуру:");
    int t=get_double();
    printf("Количество теплоты: %.2f", Q(m,C_STEEL,delta_t(t,t0)));
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

double get_mass()
{
    double s=get_double();
    if (s<=0.0)
        {
            printf("Ошибка: масса должна быть больше 0\n");
            exit(1);
        }
    return s;
}

int delta_t(const int t, const int  t0)
{
    return t-t0;
}

double Q(const double m, const int c, const int delta_t)
{
    return c*m*delta_t;
}
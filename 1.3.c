#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/** @brief считывает с клавиатуры значение с плавающей точкой
 * @return считанное значение
 */
double get_double();

/** @brief считывает с клавиатуры значение с плавающей точкой для массы
 * @return считанное значение
 */
double get_mass();

/** @brief считывает с клавиатуры значение с плавающей точкой для температуры
 * @return считанное значение
 */
int get_temp();

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

int main()
{
    int c=500;
    printf("Введите массу детали:");
    double m=get_mass();
    printf("Введите начальную температуру:");
    int t0=get_temp();
    printf("Введите конечную температуру:");
    int t=get_temp();
    printf("Количество теплоты: %.2f", Q(m,c,delta_t(t,t0)));
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

int get_temp()
{
    int s=0;
    if (scanf("%d",&s)!=1)
        {
            printf("Ошибка: температура должна быть задана числом\n");
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

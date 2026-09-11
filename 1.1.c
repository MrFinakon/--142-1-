#include<stdio.h>
#include<math.h>
/**
 * @brief вычисляет значение функции A по заданному значению
 * @param x значение параметра x
 * @param y значение параметра x
 * @param z значение параметра x
 * @return рассчитанное значение
 */
double A(const double x, const double y, const int z);

/**
 * @brief вычисляет значение функции B по заданному значению
 * @param x значение параметра x
 * @param y значение параметра x
 * @param z значение параметра x
 * @return рассчитанное значение
 */
double B(const double x, const double y, const int z);

/**
 * @brief точка входа в программу
 * @return возвращает 0, если программа выполнена корректно
 */
int main()
{
    const double x=0.29;
    const double y=3.7;
    const int z=-1;
    printf("a=%.5f", A(x,y,z));
    printf("b=%.5f", B(x,y,z));
    return 0;
}

double A(const double x, const double y, const int z)
{
    return 3*pow(x,y) * log(y) + exp(z*x);
}

double B(const double x, const double y, const int z)
{
    return (fabs(2*y*z)/(sin(x)*sin(x)))-((pow(x,2))/3);
}
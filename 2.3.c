#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/** @brief считывает с клавиатуры значение с плавающей точкой
 * @return считанное значение
 */
double get_double();

/**
 * @brief проверяет помещаются ли дома без поворота
 * @param a значение параметра a(ширина по горизонтали)
 * @param b значение параметра b(высота по вертикали)
 * @param p значение параметра p
 * @param q значение параметра q
 * @param r значение параметра r
 * @param s значение параметра s
 * @return если дома помещаются, то 1, если нет, то 0
 */
int check_without_rotation(double a, double b, double p, double q, double r, double s);

/**
 * @brief проверяет возможно ли разместить два дома на участке со всеми возможными поворотами
 * @return если дома можно разместить, то 1, если нельзя, то 0
 */
int check_placement(const double a, const double b, const double p, const double q, const double r, const double s);

/**
 * @brief точка входа в программу
 * @return возвращает 0, если программа выполнена корректно
 */
int main()
{
    printf("Введите значения (два) для размера участка:\n");
    double a=get_double();
    double b=get_double();
    printf("Введите значения (два) для размера первого дома:\n");
    double p=get_double();
    double q=get_double();
    printf("Введите значения (два) для размера второго дома:\n");
    double r=get_double();
    double s=get_double();
    
    if (check_placement(a,b,p,q,r,s)==1)
    {
        printf("Результат: Можно\n");
    }
    else
    {
        printf("Результат: Нельзя\n");
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

    if (s<=0)
    {
        printf("Ошибка: число должно быть больше 0");
        exit(1);
    }
    return s;
}

int check_without_rotation(double a, double b, double p, double q, double r, double s)
{
    double max_height=0.0;
    double max_width=0.0;
    // Находим максимальную высоту, если дома стоят в ряд по горизонтали
    if (q>s)
    {
        max_height=q;
    }
    else
    {
        max_height=s;
    }
    // Находим максимальную ширину, если дома стоят в ряд по вертикали
    if (p > r)
    {
        max_width=p;
    } else
    {
        max_width=r;
    }

    if ((p+r<=a) && (max_height<=b))
    {
        return 1; // Влезли горизонтально
    }
    if ((q+s<=b) && (max_width<=a)) 
    {
        return 1; // Влезли вертикально
    }
    return 0; // Вообще не влезли
}

int check_placement(const double a, const double b, const double p, const double q, const double r, const double s)
{
    // Перебираем все 4 варианта поворота домов на 90 градусов
    if (check_without_rotation(a, b, p, q, r, s)) return 1;
    if (check_without_rotation(a, b, p, q, s, r)) return 1;
    if (check_without_rotation(a, b, q, p, r, s)) return 1;
    if (check_without_rotation(a, b, q, p, s, r)) return 1;
    return 0;
}
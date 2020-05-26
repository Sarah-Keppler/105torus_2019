/*
** EPITECH PROJECT, 2019
** 105torus
** File description:
** Calculate equations.
*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "include/my.h"

float calc_equation(float *coord, float x)
{
    double res = (pow(x, 4.0) * coord[0]);
    res += (pow(x, 3.0) * coord[1]);
    res += (pow(x, 2.0) * coord[2]);
    res += (pow(x, 1.0) * coord[3]);
    res += coord[4];
    return (res);
}

int nb_digits(int times)
{
    int nb = 0;
    
    while (times != 0) {
        times /= 10;
        ++nb;
    }
    return (nb);
}

char *put_printf(int times)
{
    int nb_digit = nb_digits(times);
    char *prec = malloc(sizeof(char) * (nb_digit + 5));
    char *begin = malloc(sizeof(char) * (nb_digit + 5));

    if (NULL == prec || NULL == begin)
        return (NULL);
    prec = my_strcpy(prec, "%.");
    gcvt(times, nb_digit, begin);
    prec = my_strcat(prec, begin);
    prec[2 + nb_digit] = 'f';
    prec[3 + nb_digit] = '\n';
    prec[4 + nb_digit] = '\0';
    free(begin);
    return (prec);
}

char bisection_method(float *coord, float a, float b)
{
    static int times = 1;
    char *print = put_printf(times);
    float c = (a + b) / 2;
    float equation[3] = {calc_equation(coord, a),
                         calc_equation(coord, b),
                         calc_equation(coord, c)};
    if ((equation[0] * equation[2]) <= 0)
        b = c;
    else
        a = c;
    printf("x = ");
    printf(print, c);
    if (times < coord[5]) {
        ++times;
        bisection_method(coord, a, b);
    }
    free(print);
    return ('0');
}

char error(char **av)
{
    if (!('0' < av[1][0] && '4' > av[1][0])) {
        printf("Wrong first arg !\n");
        return ('1');
    }
    for (int i = 2; 7 > i; ++i) {
        if (0 == my_str_isint_float(av[i])) {
            printf("Wrong arguments.\n");
            return ('1');
        }
    }
    if (0 > atoi(av[7]) || 0 == my_str_isnum(av[7])) {
        printf("Wrong last argument.\n");
        return ('1');
    }
    return ('0');
}

void disp_hflag(void)
{
    printf("USAGE\n    ./105torus opt a0 a1 a2 a3 a4 n\n\n");
    printf("DESCRIPTION\n   opt        method option:\n");
    printf("                  1 for the bisection method\n");
    printf("                  2 for Newton's method\n");
    printf("                  3 for the secant method\n");
    printf("   a[0-4]     coefficients of the equation\n");
    printf("   n          precision (the application of the polynomial to the solution should\n");
    printf("              be smaller than 10^-n)\n");
}

int main(int ac, char **av)
{
    if (2 != ac && 8 != ac) {
        printf("Wrong numbers of arguments !\n");
        return (84);
    }
    if ('-' == av[1][0] && 'h' == av[1][1]) {
        disp_hflag();
        return (84);
    } else if (2 == ac) {
        printf("~ Wrong first parameter.\n");
        return (84);
    }
    if ('1' == error(av))
        return (84);
    float coord[6] = {atof(av[6]), atof(av[5]), atof(av[4]), atof(av[3]), atof(av[2]), atoi(av[7])};
    if ('1' == av[1][0])
        bisection_method(coord, 0, 1);
    return (0);
}

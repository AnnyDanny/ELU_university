#include <stdio.h>

int my_mult(int param_1, int param_2)
{
    int res = 0;

    res = param_1 * param_2;

    return res;
}

int main()
{
    int nbr1 = 0;
    int nbr2 = 1;
    int res = 0;

    res = my_mult(nbr1, nbr2);
    printf("%d/n", res);

    return 0;
}

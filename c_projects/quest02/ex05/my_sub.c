#include <stdio.h>

int my_sub(int param_1, int param_2)
{
    int res = 0;

    res = param_1 - param_2;

    return res;
}

int main()
{
    int nbr1 = -10;
    int nbr2 = 10;
    int res = 0;

    res = my_sub(nbr1, nbr2);
    printf("%d/n", res);

    return 0;
}

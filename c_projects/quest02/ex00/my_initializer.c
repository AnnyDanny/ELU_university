#include <stdio.h>


void my_initializer(int* param_1)
{
    *param_1 = 0;
}


int main(void)
{
    int n = 12;
    my_initializer(&n);
    printf("%d\n", n);

    return 0;
}

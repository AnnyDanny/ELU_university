#include <stdio.h>


void my_swap(int* param_1, int* param_2)
{
    int temp = 0;

    temp = *param_1;
    *param_1 = *param_2;
    *param_2 = temp;
}


int main()
{
    int n1 = 12;
    int n2 = 21;
    my_swap(&n1, &n2);
    printf("n1: %d\nn2: %d\n", n1, n2);

    return 0;

}
#include "stdio.h"
#include <stdlib.h>


int* my_range(int param_1, int param_2)
{
    if (param_1 >= param_2)
    {
        int *nullptr = NULL;
        return nullptr;
    }
    int size_of_array = param_2 - param_1;
    int *res = malloc(size_of_array * sizeof *res);
    for (int i = 0; i < size_of_array; ++i)
    {
        res[i] = param_1;
        param_1++;
    }
    return res;
}


int main()
{
    int p1 = 10;
    int p2 = 11;
    int *res = {0};

    res = my_range(p1, p2);
    int len_of_res = (int)(sizeof(res) / sizeof(res[0]));
    printf("len_of_array: %d\n", len_of_res);
    for (int i = 0; i < len_of_res + 1; ++i)
    {
        printf("%d", res[i]);
        printf("\n");
    }



    return 0;
}

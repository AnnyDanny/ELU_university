#include <stdio.h>
#include <stdbool.h>

#ifndef STRUCT_INTEGER_ARRAY
#define STRUCT_INTEGER_ARRAY
typedef struct s_integer_array
{
    int size;
    int* array;
} integer_array;
#endif


bool my_is_sort(integer_array* param_1)
{
    int asc = 0;
    int desc = 0;

    for (int i = 0; i < param_1->size-1; ++i)
    {
        for (int j = i + 1; j < param_1->size; ++j)
        {
            if (param_1->array[i] == param_1->array[j])
            {
                continue;
            }
            else if (param_1->array[i] > param_1->array[j])
            {
                desc += 1;
            }
            else
            {
                asc += 1;
            }
        }

        if (desc > 0 && asc == 0)
        {
            return true;
        }
        else if (asc > 0 && desc == 0)
        {
            return true;
        }
        return false;
    }
}

int main()
{
    int size1 = 5;
    //int array1[] = {10, 2, 3, 3, 0, -1};
    //int array1[] = {2, 3, 5, 6, 8, 9};
    int array1[] = {22, 22, 22, 22, 33};
    //int array1[] = {55, 55, 4, 55, 3, 55};
    //int array1[] = {};
    //int array1[] = {1029383, 0, 1, 273849450, 1029383};
    //int n = 1;
    //int n2 = n << 2;
    //int n3 = n2 >> 1;
    //printf("n2: %d\n", n2);
    //printf("n3: %d\n", n3);

    integer_array param_1 = {size1, array1};
    bool res = my_is_sort(&param_1);
    printf("%d\n", res);
    /*int i = 0;
    while (i < param_1.size)
    {
        printf("%d\n", param_1.array[i]);
        ++i;
    }*/


    return 0;
}

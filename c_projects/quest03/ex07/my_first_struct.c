#include <stdio.h>

#ifndef STRUCT_INTEGER_ARRAY
#define STRUCT_INTEGER_ARRAY
typedef struct s_integer_array
{
    int size;
    int* array;
} integer_array;
#endif


void my_first_struct(integer_array* param_1)
{
    printf("%d\n", param_1->size);
    int i;
    for(i = 0; i < param_1->size; ++i)
    {
        printf("%d\n ", param_1->array[i]);
    }
}

int main()
{
    int size1 = 6;
    int array1[] = {10, 2, 3, 3, 0, -1};
    integer_array param_1 = {size1, array1};

    my_first_struct(&param_1);
    return 0;
}

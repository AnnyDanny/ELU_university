#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#ifndef STRUCT_STRING_ARRAY
#define STRUCT_STRING_ARRAY
typedef struct s_string_array
{
    int size;
    char** array;
} string_array;
#endif

#ifndef STRUCT_INTEGER_ARRAY
#define STRUCT_INTEGER_ARRAY
typedef struct s_integer_array
{
    int size;
    int* array;
} integer_array;
#endif


int len_of_str(char *str)
{
    int len = 0;
    for (; str[len] != '\0'; ++len);
    return len;
}

integer_array* my_count_on_it(string_array* param_1)
{
    int *arr;
    arr = (int *) malloc(param_1->size * sizeof(int));
    integer_array *st = (integer_array *) malloc(sizeof(integer_array));
    for (int i = 0; i < param_1->size; ++i)
    {
        arr[i] = len_of_str(param_1->array[i]);
    }
    st->array = arr;
    st->size = param_1->size;

    return st;
}

void my_print_elements_array(integer_array* param_1)
{
    for (int i = 0; i < param_1->size; ++i)
    {
        printf("%d\n", param_1->array[i]);
    }
}

int main()
{
    integer_array *ist;
    string_array st;
    char arr[][4] = {"aBc"};
    st.size = 1;


    st.array = (char**)malloc(sizeof(char*) * st.size);

    for (int i = 0; i < st.size; i++)
    {
        st.array[i] = (char*)malloc(sizeof(char) * (strlen(arr[i]) + 1));
        strcpy(st.array[i], arr[i]);
    }

    ist = my_count_on_it(&st);
    my_print_elements_array(ist);

    for (int i = 0; i < st.size; i++)
    {
        free(st.array[i]);
    }
    free(st.array);

    return 0;
}
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


int len_of_str(char *str)
{
    int len = 0;
    for (; str[len] != '\0'; ++len);
    return len;
}

char *my_strcat(char *destination, const char *source)
{
    int len_of_dest = len_of_str(destination);
    for (int i = 0; source[i] != '\0'; ++i, ++len_of_dest)
    {
        destination[len_of_dest] = source[i];
    }
    destination[len_of_dest] = '\0';
    return destination;
}


char* my_join(string_array* param_1, char* param_2)
{
    if (param_1->size == 0)
    {
        return NULL;
    }
    int nmb_of_chars = 0;
    int nmb_of_sep = len_of_str(param_2);
    for (int i = 0; i < param_1->size; ++i)
    {
        nmb_of_chars += len_of_str(param_1->array[i]);
    }
    nmb_of_chars += (nmb_of_sep * (param_1->size - 1));
    char *res = (char *)malloc(nmb_of_chars + 1);
    res[0] = '\0';
    for (int i = 0; i < param_1->size; ++i)
    {
        res = my_strcat(res, param_1->array[i]);
        if (i + 1 < param_1->size)
        {
            res = my_strcat(res, param_2);
        }
    }
    return res;
}


int main()
{
    string_array st;
    char arr[][0] = {};
    st.size = 0;
    char *separator = "";
    char *res = "";

    st.array = (char**)malloc(sizeof(char*) * st.size);

    for (int i = 0; i < st.size; i++)
    {
        st.array[i] = (char*)malloc(sizeof(char) * (strlen(arr[i]) + 1));
        strcpy(st.array[i], arr[i]);
    }

    res = my_join(&st, separator);

    printf("res: %s\n", res);

    for (int i = 0; i < st.size; i++)
    {
        free(st.array[i]);
    }
    free(st.array);

    return 0;
}
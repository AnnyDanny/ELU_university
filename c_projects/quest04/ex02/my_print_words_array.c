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


int my_putchar(char c) {
  return write(1, &c, 1);
}

void my_putstr(char* param_1)
{
    int i = 0;

    while (param_1[i] != '\0')
    {
        my_putchar(param_1[i]);
        i++;
    }
    my_putchar('\n');
}

void my_print_words_array(string_array* param_1)
{
    for (int i = 0; i < param_1->size; ++i)
    {
        my_putstr(param_1->array[i]);
    }
}


int main()
{
    string_array st;
    char arr[][4] = {"abc", "def", "kgh"};
    st.size = 3;

    st.array = (char**)malloc(sizeof(char*) * st.size);

    for (int i = 0; i < st.size; i++)
    {
        st.array[i] = (char*)malloc(sizeof(char) * (strlen(arr[i]) + 1));
        strcpy(st.array[i], arr[i]);
    }

    my_print_words_array(&st);

    for (int i = 0; i < st.size; i++)
    {
        free(st.array[i]);
    }
    free(st.array);

    return 0;
}

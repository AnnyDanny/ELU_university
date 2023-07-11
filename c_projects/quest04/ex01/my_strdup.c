#include "stdio.h"
#include <stdlib.h>


int len_of_array(char *str)
{
    int len = 0;
    for (; str[len] != '\0'; ++len);
    return len;
}

char* my_strdup(char* param_1)
{
    char *res;
    int number_of_elements = len_of_array(param_1);

    res = malloc(number_of_elements * sizeof(char *));

    for (int i = 0; i < number_of_elements; ++i)
    {
        res[i] = param_1[i];
    }
    return res;
}


int main()
{
    char *str = "";
    char *res = my_strdup(str);

    printf("res: %s\n", res);

    return 0;
}

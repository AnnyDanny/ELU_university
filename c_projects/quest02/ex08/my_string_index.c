#include <stdio.h>


int my_string_index(char* param_1, char param_2)
{
    int i = 0;
    int res = 0;

    while (param_1[i] != '\0')
    {
        if (param_2 == param_1[i])
        {
            res = i;
            break;
        }
        else
        {
            res = -1;
        }
        i++;
    }
    return res;
}

int main()
{
    char *str = "aaaaa";
    char c = 'b';
    int res = 0;

    res = my_string_index(str, c);
    printf("%d/n", res);
    return 0;
}

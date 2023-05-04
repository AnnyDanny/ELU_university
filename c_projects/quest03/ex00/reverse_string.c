#include <stdio.h>

int len_of_str(char *str)
{
    int i = 0;

    while (str[i] != '\0')
    {
        i++;
    }
    return i;
}

char* reverse_string(char* param_1)
{
    int len = len_of_str(param_1);
    char res[len];
    int i = 0;

    len--;
    for (int i = 0; len >= i; ++i, --len)
    {
        char c = param_1[len];
        param_1[len] = param_1[i];
        param_1[i] = c;
    }
    return param_1;
}


int main()
{
    char s[] = "Hello";
    char *r = NULL;

    r = reverse_string(s);
    printf("%s", r);
    return 0;
}

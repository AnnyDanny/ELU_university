#include <stdio.h>
#include <ctype.h>


char* my_upcase(char* param_1)
{
    int i = 0;

    while (param_1[i] != '\0')
    {
        if ((param_1[i] >= 'a') && (param_1[i] <= 'z'))
        {
            param_1[i] = param_1[i] - ('a' - 'A');
        }
        i++;
    }

    return param_1;
}

int main()
{
    char str1[5] = "hello";
    char *resstr = "";

    resstr = my_upcase(str1);
    printf("%s/n", resstr);

    return 0;
}

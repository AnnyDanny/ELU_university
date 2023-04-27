#include <stdio.h>


int my_strlen(char* param_1)
{
    int i = 0;
    int count = 0;

    while (param_1[i] != '\0')
    {
        count++;
        i++;
    }

    return count;
}

int main()
{
    char *str = "ThE C4k3 Is a L|3";
    int res = 0;
    res = my_strlen(str);

    printf("%d\n", res);

    return 0;
}

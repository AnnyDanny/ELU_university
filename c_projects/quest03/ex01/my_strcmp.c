#include <stdio.h>


int my_strcmp(char* param_1, char* param_2)
{
    int i = 0;

    while (param_1[i] != '\0')
    {
        if (param_1[i] > param_2[i])
        {
            return 1;
        }
        else if (param_1[i] < param_2[i])
        {
            return -1;
        }
        ++i;
    }
    return 0;
}


int main()
{
    char *s1 = "abc";
    char *s2 = "abc";

    printf("my_strcmp -> %d\n", my_strcmp(s1, s2));

    return 0;
}

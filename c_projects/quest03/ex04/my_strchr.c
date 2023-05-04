#include <stdio.h>


char* my_strchr(char* param_1, char param_2)
{
    int i = 0;

    while (param_1[i] != '\0')
    {
        if (param_1[i] == param_2)
        {
            return &param_1[i];
        }
        ++i;
    }

    return NULL;
}


int main()
{
    //char dst[100] = {0};
    char *src = "abc";
    char c = 'd';
    char *dest = my_strchr(src, c);

    printf("dest: %s\n", dest);

    return 0;
}

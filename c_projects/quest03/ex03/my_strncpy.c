#include <stdio.h>
#include <string.h>

int src_len(char *src)
{
    int len = 0;

    while (src[len] != '\0')
    {
        ++len;
    }

    return len;
}

char* my_strncpy(char* param_1, char* param_2, int param_3)
{
    int i = 0;
    int len_of_src = 0;

    len_of_src = src_len(param_2);

    while (i <= param_3 - 1)
    {
        param_1[i] = param_2[i];
        ++i;
    }
    printf("len_of_src: %d\n", len_of_src);
    printf("param_3: %d\n", param_3);
    if (len_of_src > param_3)
    {
        while (param_1[i] != '\0')
        {
            param_1[i] = 0;
            ++i;
        }
    }
    param_1[i] = '\0';

    return param_1;
}


int main() {
    char dst[100] = {0};
    char *src = "abc";

    printf("my_strncpy -> %s\n", my_strncpy(dst, src, 2));

    return(0);
}

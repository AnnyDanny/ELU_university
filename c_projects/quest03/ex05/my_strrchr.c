#include <stdio.h>

char* my_strrchr(char* param_1, char param_2)
{
    int saveIndex = 0;

    for (int i = 0; param_1[i] != '\0'; ++i)
    {
        if (param_1[i] == param_2)
        {
            saveIndex = i;
        }
        if (param_1[i + 1] == '\0' && saveIndex != 0)
        {
            return &param_1[saveIndex];
        }
    }
    return NULL;
}


int main()
{
    char *str = "121212";
    char c = '2';
    char *dest = my_strrchr(str, c);

    printf("%s\n", dest);

    return 0;
}

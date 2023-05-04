#include <stdio.h>
#include <stdbool.h>


int len_of_str(char *str)
{
    int len = 0;

    for(; str[len] != '\0'; ++len);

    return len;
}

bool my_strncmp(const char *str1, const char *str2)
{
    int i = 0;

    for (; str1[i] != '\0'; ++i)
    {
        if (str1[i] == str2[i])
        {
            if (str2[i + 1] == '\0')
            {
                return true;
            }
        }
    }
    return false;
}


char* my_strstr(char* param_1, char* param_2)
{
    int len_of_param2 = len_of_str(param_2);
    int j = 0;

    if (len_of_param2 == 0)
    {
        return param_1;
    }
    for (int i = 0; param_1[i] != '\0'; ++i)
    {
        if (param_1[i] == param_2[0])
        {
            bool res = my_strncmp(&param_1[i], param_2);
            if (res == true)
            {
                return &param_1[i];
            }
        }
    }
    return NULL;
}


int main()
{
    char *str1 = "mississippi";
    char *str2 = "issip";
    //char *str3 = "issip";
    char *res = my_strstr(str1, str2);
    //bool res2 = my_strncmp(str3, str2);

    printf("res: %s\n", res);

    return 0;
}


/*
#include <stdbool.h>
#include <stddef.h>  // for size_t


size_t strlen(const char *s)
{
    size_t len = 0;
    while (*s++) len++;
    return len;
}

bool strncmp(const char *s1, const char *s2, size_t n)
{
    while (n--)
        if (*s1++ != *s2++)
            return false;
    return true;
}

char* strstr(const char* haystack, const char* needle)
{
    size_t len_needle = strlen(needle);
    if (len_needle == 0) return (char*) haystack;
    while (*haystack)
    {
        if (*haystack == *needle)
        {
            if (strncmp(haystack, needle, len_needle))
                return (char*) haystack;
        }
        haystack++;
    }
    return NULL;
}

*/
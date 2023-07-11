#include <stdio.h>
#include <string.h>
#include <stdlib.h>



//return a single char
char *fct(char *s)
{
    char *res = (char*)malloc(strlen(s) + 1);
    int index = 0;
    int end_index = 0;
    int len_of_str = 0;

    for (int i = 0; s[i] != '\0'; ++i)
    {
        if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z'))
        {
            index = i;
            break;
        }
    }
    for (int i = index; s[i] != '\0'; ++i)
    {
        if (!((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z')))
        {
            end_index = i;
            break;
        }
    }
    for (int i = end_index + 1; s[i] != '\0'; ++i)
    {
        res[i - end_index - 1] = s[i];
    }
    len_of_str = strlen(res);

    if (!((res[len_of_str - 1] >= 'A' && res[len_of_str - 1] <= 'Z') || (res[len_of_str - 1] >= 'a' && res[len_of_str - 1] <= 'z')))
    {
        res[len_of_str] = ' ';
        len_of_str += 1;
    }

    for(int i = index; i < end_index; ++i)
    {
        res[len_of_str + i - index] = s[i];
    }

    return res;
}

// from a sentence, put the first word at the end of the string
//"   this is a sentence wioth multiple words separated by whitespaces    "
//"is a sentence wioth multiple words separated by whitespaces this"
int main(int ac, char **av)
{
    char *s = "   this is a sentence wioth multiple words separated    by  whitespaces    ";

    printf("%s\n", fct(s));
}
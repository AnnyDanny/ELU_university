#include <stdio.h>

char *arr = "global";
void my_initializer(char** param_1)
{
    *param_1 = arr;
}

void my_initializer2(char* param_1)
{
    printf("param_1 before: %s\n", param_1);
    param_1 = arr;
    printf("param_1 after: %s\n", param_1);
}


int main(void)
{
    char c = 'a';
    int n = 4;
    char *p = &&c;
    char **d = &p;
    **d = 'z';
    //d->p->c == z
    // 0x1 - char c = 'a'
    // 0x2 - int n = 4
    // 0x3 - int n = 4
    // 0x4 - int n = 4
    // 0x5 - int n = 4
    // 0x6 - char *p = &c
    // 0x7 - char *p = &c
    // 0x8 - char *p = &c
    // 0x9 - char *p = &c
    // 0x10 - char *p = &c
    // 0x11 - char *p = &c
    // 0x12 - char *p = &c
    // 0x13 - char *p = &c


    // 0x14 - char **d = &p
    // 0x15 - char **d = &p
    // 0x16 - char **d = &p
    // 0x17 - char **d = &p
    // 0x18 - char **d = &p
    // 0x19 - char **d = &p
    // 0x20 - char **d = &p
    // 0x21 - char **d = &p
    c = 'b';
    *p = 'c';
    p = &n;
    char str[][3] = {"ab"};
    char str2[] = "ac";
    char *str3 = "ad";
    //my_initializer(str);
    my_initializer(&str2);
    my_initializer2(str3);
    //printf("%s\n", str);
    printf("%s\n", str2);
    printf("%s\n", str3);

    return 0;
}


/*

1 byte = 8 bits
1 char = 1 byte
1 int = 4 byte

2^8 = 256
*/
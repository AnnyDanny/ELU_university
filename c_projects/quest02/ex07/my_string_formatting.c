#include <stdio.h>


void my_string_formatting(char* param_1, char* param_2, int param_3)
{
    printf("Hello, my name is %s %s I'm %d.", param_1, param_2, param_3);
}

int main()
{
    my_string_formatting("Hanna", "Danylova", 31);
    return 0;
}

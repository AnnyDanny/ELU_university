#include <stdio.h>
#include <stdlib.h>

char* my_spaceship(char* param_1)
{
    int state = 1;
    int x = 0;
    int y = 0;
    char * direction = "up";

    for (int i = 0; param_1[i] != '0'; ++i)
    {
        if (param_1[i] == 'R')
        {
            state += 1;
            if (state > 4)
            {
                state = 1;
            }
        }
        else if (param_1[i] == 'L')
        {
            state -= 1;
            if (state < 1)
            {
                state = 4;
            }
        }
        else if (param_1[i] == 'A')
        {
            if (state == 1)
            {
                y -= 1;
            }
            else if (state == 2)
            {
                x += 1;
            }
            else if (state == 3)
            {
                y += 1;
            }
            else
            {
                x -= 1;
            }
        }
    }
    if (state == 2)
    {
        direction = "right";
    }
    else if (state == 3)
    {
        direction = "down";
    }
    else if (state == 4)
    {
        direction = "left";
    }

    char *buffer = (char * )malloc(100);
    sprintf(buffer, "{x: %d, y: %d, direction: '%s'}", x, y, direction);

    return buffer;
}

int main ()
{
    char *str = "RAARA";
    char *res = my_spaceship(str);

    printf("res: %s\n", res);

    return 0;
}

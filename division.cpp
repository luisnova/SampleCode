// divide two numbers
// gcc division.c -ggdb
// gdb --args executablename arg1 arg2 arg3

#include <stdio.h>
#include <stdlib.h> 

int main(int argc, const char* argv[])
{
    if (argc != 3)
    {
       printf("wrong number of arguments\n");
       exit(0);
    }

    int x, xi;
    int y;
    int result = 0;
    int tmp;
    int sh = sizeof(unsigned) * 8;
	
    x = xi = atoi( argv[1] );
    y = atoi( argv[2] );

    while (sh > 0)
    {
        sh--;

        tmp = x >> sh;
        result = result << 1;
        if (tmp >= y)
        {
            result += 1;
            x -= y << sh;
        }
    }

    printf("x: %i, y: %i, x/y: %i\n", xi, y, result);
}

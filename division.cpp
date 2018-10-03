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

    int x, x_original;
    int divisor;
    int result = 0;
    int temp;
    int shift = sizeof(unsigned) * 8;
	
    x = x_original = atoi( argv[1] );
    divisor = atoi( argv[2] );

    while (shift > 0)
    {
        shift--;

        temp = x >> shift;
        result = result << 1;
        if (temp >= divisor)
        {
            result += 1;
            x -= divisor << shift;
        }
    }

    printf("x: %i, y: %i, x/y: %i\n", x_original, divisor, result);
}

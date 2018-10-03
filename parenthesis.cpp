#include <stdio.h>
#include <stdlib.h> 

void print_paren(int original, int n, int open, int closed, char *prefix)
{
    if (n==0)
    {
        prefix[0] = '\0';
        prefix -= original;
        printf("%s\n", prefix);
    }
    else
    {	
      	if ((open-closed) > 0)
      	{
     	    prefix[0] = ')';
            print_paren(original, n-1, open, closed+1, &prefix[1]);
	    }
	    if (open < original/2)
	    {
	        prefix[0] = '(';
            print_paren(original, n-1, open+1, closed, &prefix[1]);
	    }
    }
}

int main(int argc, const char* argv[])
{
    if (argc != 2)
    {
       printf("wrong number of arguments\n");
       exit(0);
    }

    int n = atoi( argv[1] );
    char * prefix = (char *) malloc (n * 2);
    print_paren( n*2, n*2, 0, 0, prefix);
}

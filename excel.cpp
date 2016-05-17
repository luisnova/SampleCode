// excel index
// gcc excel.c -lm -ggdb
// gdb --args executablename arg1 arg2

#include <stdio.h>
#include <string.h> 
#include <stdlib.h>
#include <math.h> 

int char_value( char c )
{
    if ( c >= 'a' && c <= 'z' )
        return ( c - 'a' + 1 );
    else if ( c >= 'A' && c <= 'Z' )
        return ( c - 'A' + 1);
    else
        return 0;
}

unsigned count( const char * str )
{
    if (str[0] == '\0') 
        return 0;

    int len = (int) strlen(str);
    int first = char_value(str[0]);
    unsigned sum = first * pow( 26, (len - 1) );
    return ( sum + count( &str[1] ) ); 
}

int main(int argc, const char* argv[])
{
    if (argc != 2)
    {
       printf("wrong number of arguments\n");
       exit(0);
    }

    printf("input: %s, index: %u\n", argv[1], count( argv[1] ) );
}

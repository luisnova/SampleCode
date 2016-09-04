#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int numLetters(char num)
{
   if (num=='7' || num=='9')
      return 4;
   else
      if ( num<='8' && num>='2' )
         return 3;
   
   return 0;
}
 
char getCharKey( int number, int place )
{
   switch(number)
   {
   case 2:
     if (place==1) return 'A'; 
     else if (place==2) return 'B';
     else return 'C';
     break;
   case 3:
     if (place==1) return 'D'; 
     else if (place==2) return 'E';
     else return 'F';
     break;
   case 4:
     if (place==1) return 'G'; 
     else if (place==2) return 'H';
     else return 'I';
     break;
   case 5:
     if (place==1) return 'J'; 
     else if (place==2) return 'K';
     else return 'L';
     break;
   case 6:
     if (place==1) return 'M';
     else if (place==2) return 'N';
     else return 'O';
     break;
   case 7:
     if (place==1) return 'P';
     else if (place==2) return 'Q';
     else if (place==3) return 'R';
     else return 'S';
     break;
   case 8:
     if (place==1) return 'T';
     else if (place==2) return 'U';
     else return 'V';
     break;
   case 9:
     if (place==1) return 'W';
     else if (place==2) return 'X';
     else if (place==3) return 'Y';
     else return 'Z';
     break;
   default:
     return '?';
   }
}

void printPhone( char * phone, int position )
{
   int len = strlen( phone );
   if (position == len)
   {
      printf("%s\n", phone);
      return;
   }

   char c = phone[ position ];
   if ( c <= '9' && c >= '2' )
   {
      for (int place=1; place<=numLetters(c); place ++)
      {
         phone[position] = getCharKey( c-'0', place );
         printPhone( phone, position+1 );
         phone[position] = c;
      }
   }
   else
      printPhone( phone, position+1 );
}

int main(int argc, char* argv[])
{
   if (argc != 2)
   {
      printf("wrong number of arguments\n");
      exit(0);
   }

   char * phone = argv[1];
   printPhone( phone, 0 );
}


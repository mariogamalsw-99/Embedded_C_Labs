// Online C compiler (editor)
// Write and run C online using this editor.

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
void get_usr_num(int *num);
int Flush(void);

// start of program function declaration
void scan_string(char* str,const int size);
// end of program function declaration
int main()
{

    char cmd = 'y';
    do
    {
        ////start of program
        // inputs
        char in1_string[50];

        printf("enter  string:\n");
        scan_string(in1_string,50);
     
       
      
        //string iterator
        char *str1_it = in1_string;
  
        //cpy string into str2
        while (*str1_it != '\0')
        {
          if(*str1_it>='a' &&*str1_it<='z' )
          {
            *str1_it-=('a'-'A');
          }
          else if(*str1_it>='A' &&*str1_it<='Z' )
          {
            *str1_it+=('a'-'A');
          }
          str1_it++;
        }

        //outpt
        printf("outstr:%s\n",in1_string);
        
        /// end of program
        printf("please press enter to continue");
        Flush();
        printf("if you need another calculatoin press 'y'.\n");
        cmd = getchar();
    } while (cmd == 'y' &&   Flush());
    printf("program end.");

    return 0;
}

// start of program function impelementation
void scan_string(char* str,const int size)
{
    int i=0;
    for( i=0;i<size-1;i++)
    {
        scanf("%c",str+i);
        if(*(str+i)=='\n')
        break;
    }
    *(str+i)='\0';
  
}
// end of program function impelementation
void get_usr_num(int *num)
{
    int status = 0;
    do
    {
        status = scanf("%d", num);
        if (status != 1)
        {
            Flush();
            printf("please enter numbers only!!\n");
        }

    } while (status != 1);
}
int Flush(void)
{
    while (getchar() != '\n')
        ;
    return 1;
}


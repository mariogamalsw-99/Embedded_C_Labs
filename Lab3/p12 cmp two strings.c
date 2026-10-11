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
        char in1_string[50],in2_string[50];
        printf("enter first string:\n");
        scan_string(in1_string,50);
        printf("enter second string:\n");
        scan_string(in2_string,50);
       
        //compare result
        int cmp_res=0;
        //string iterator
        char *str1_it = in1_string;
        char *str2_it = in2_string;
        while (*str1_it != '\0'&&cmp_res==0)
        {
          cmp_res=*(str1_it)-*(str2_it);
          str1_it++;
          str2_it++;
        }
        //outpt
        printf("compare res :%4d\n",cmp_res);
        
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


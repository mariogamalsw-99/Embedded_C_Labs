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
        char in_string[50];
        printf("enter string:\n");
        // scanf("%49s[^\r]",in_string);
        scan_string(in_string,50);
        //  scanf("%[^\n]%*c", &in_string);
        // len
        int str_len = 0;
        //string iterator
        char *str_it = in_string;
        while (*str_it != '\0')
        {
            str_len++;
            str_it++;
        }
        //outpt
        printf("lengtn of string :%4d\n",str_len);
        
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


// Online C compiler (editor)
// Write and run C online using this editor.

#include <stdio.h>
#include <math.h>
void get_usr_num(int* num);
void Flush( void );
int main() {


    char cmd='y';
    do
        {
            ////start of program
                //inputs
                int a,b;
                
                printf("Enter first number:");
                get_usr_num(&a);
                printf("Enter second number:");
                get_usr_num(&b);
             
             for(int i=a;i<=b;i++)
             {
                 if(i%2==0)
                 {
                     printf(">%d is even number.\n",i);
                 }
                 else
                 {
                     printf(">%d is odd number.\n",i);
                 }
             }

            ///end of program
                Flush( );
                printf("if you need another calculatoin press 'y'.\n");
                cmd=getchar();
        }while(cmd=='y');
        printf("program end.");

    
    return 0;
}


void get_usr_num(int* num)
{
    int status=0;
    do
        {
           status= scanf("%d",num);
            if(status!=1)
            {
                Flush();
                printf("please enter numbers only!!\n");
            }
            
        }
        while (status!=1);
}
void Flush( void ) {
    while ( getchar() != '\n' )
        ;
}
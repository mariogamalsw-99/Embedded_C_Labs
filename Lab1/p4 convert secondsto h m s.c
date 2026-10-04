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
                int userin;
                printf("Enter total seconds:");
                get_usr_num(&userin);
                int total_sec=userin;
                int h,m,s;

                h=total_sec/3600;
                total_sec%=3600;
            
                m=total_sec/60;
                total_sec%=60;

                s=total_sec;
                
             
                printf(">> %d is equal:\n >> %d hours,%d minutes and %d seconds.\n",userin,h,m,s);
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
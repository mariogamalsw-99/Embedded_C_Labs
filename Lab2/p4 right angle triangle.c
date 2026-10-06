// Online C compiler (editor)
// Write and run C online using this editor.

#include <stdio.h>
#include <math.h>
void get_usr_num(int* num);
void Flush( void );

//start of program function declaration

//end of program function declaration
int main() {


    char cmd='y';
    do
        {
            ////start of program
                //inputs
                int a;
                do
                    {
                        printf("Enter size of triangle(rows):");
                        get_usr_num(&a);
                    } 
                    while((a<0)&&printf("Please enter positive integer only.\n"));
            for(int i=0;i<a;i++)
                {
                    for(int j=0;j<=i;j++)
                        {
                            printf("*");
                        }
                    printf("\n");
                }
                
                
            
          

            ///end of program
                Flush( );
                printf("if you need another calculatoin press 'y'.\n");
                cmd=getchar();
        }while(cmd=='y');
        printf("program end.");

    
    return 0;
}

//start of program function impelementation

//end of program function impelementation
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
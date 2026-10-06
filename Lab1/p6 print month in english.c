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
                int a;
                do
                    {
                        printf("Enter first number:");
                        get_usr_num(&a);
                    }
                    while((a<1||a>12)&&printf("Please enter number between 1 and 12\n"));
            //honstly i used chatgpt to write me this switch case only   
      switch (a)
        {
            case 1:
                printf("January\n");
                break;
            case 2:
                printf("February\n");
                break;
            case 3:
                printf("March\n");
                break;
            case 4:
                printf("April\n");
                break;
            case 5:
                printf("May\n");
                break;
            case 6:
                printf("June\n");
                break;
            case 7:
                printf("July\n");
                break;
            case 8:
                printf("August\n");
                break;
            case 9:
                printf("September\n");
                break;
            case 10:
                printf("October\n");
                break;
            case 11:
                printf("November\n");
                break;
            case 12:
                printf("December\n");
                break;
            default:
                printf("Invalid month number\n");
                break;
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
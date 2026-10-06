// Online C compiler (editor)
// Write and run C online using this editor.

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
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
                int x=
                            (rand()%101)+1
                            ,user_input;
                        printf("Guess the number?");
                do
                    {
                        get_usr_num(&user_input);
                        //check input
                    if(user_input==x)
                    {
                                        printf("you are RIGHT!!\n");
                                        break;
                    }
                    //hint for distance          
                        switch(abs(x-user_input))
                                            {
                                                                case 1 ... 5:
                                                                printf("you are too close!\n");
                                                                break;
                                                                case 6 ... 10 :
                                                                printf("you are close!\n");
                                                                break;
                                                                case 11 ... 50:
                                                                printf("you are far!\n");
                                                                break;
                                                                case 51 ... 100:
                                                                printf("you are too far!\n");
                                                                break;
                                                                default :
                                                                printf("you are too too far away!\n");
                                                                
                                                                
                                            }
                    //hint for direction
                                        if(user_input>x)
                                                            printf("number is less than your guess.\n");
                                        else
                                                            printf("number is greater than your guess.\n");
                                                            
                    } 
                    while((x!=user_input)&&printf("Guess again?"));
   
                
                
            
          

            ///end of program
                Flush( );
                printf("if you need another round press 'y'.\n");
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
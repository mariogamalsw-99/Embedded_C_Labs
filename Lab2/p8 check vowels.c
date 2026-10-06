// Online C compiler (editor)
// Write and run C online using this editor.

#include <stdio.h>
#include <math.h>
void get_usr_char(char* num);
void Flush( void );

//start of program function declaration

//end of program function declaration
int main() {


    char cmd='y';
    do
        {
            ////start of program
                //inputs
                char a;
                char valid_letter=0;
                do
                    {
                        printf("Enter the letter:");
                        get_usr_char(&a);
                        if((a<='z'&&a>='a') || (a<='Z'&&a>='A'))
                        {
                            valid_letter=1;
                        }
                        else
                        {
                             valid_letter=0;
                        }
                    } 
                    while((valid_letter==0)&&printf("Please enter letters only.\n"));
           
            switch (a)
                {
                    case 'a':
                    case 'e':
                    case 'i':
                    case 'o':
                    case 'u':
                    case 'A':
                    case 'E':
                    case 'I':
                    case 'O':
                    case 'U':
                        printf("%c is Vowel letter.\n",a);
                        break;
                    case 'y':
                    case 'Y':
                        printf("%c is somtimes considered as Vowel letter.\n",a);
                        break;
                    default:
                          printf("%c is Consonant letter.\n",a);
                    
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
void get_usr_char(char* num)
{
    int status=0;
    do
        {
           status= scanf("%c",num);
            if(status!=1)
            {
                Flush();
                printf("please enter chars only!!\n");
            }
            
        }
        while (status!=1);
}
void Flush( void ) {
    while ( getchar() != '\n' )
        ;
}
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
       printf("primes in range %d : %d is :\n",a,b);
             int isprime=1;
            if(a<0)
            {
                printf(">>range must start from positive integer.\n");
                    continue;
            }
            if(b<a)
            {
                 printf(">>socend number must be greater than firstnumber.\n");
                    continue;
            }
            
             for(int i=a;i<=b;i++)
             {
                if(i==0)
                {
                    continue;
                }
                else if (i==1)
                {
                     isprime=1;
                        continue;
                }
                else
                {
                    // 100 = 1* 100 || 2 * 50 || 4 * 25|| .... so the square root of 100 (10*10) is the max multiplication can get 10 
                 for(int j=2;j<=sqrt(i);j++)
                     {
                         if(i%j==0)
                         {
                             isprime=0;
                             break;
                         }
                     }
                }
                 
                 if(isprime==1)
                     printf(">>%d is prime.\n",i);
                 isprime=1;
             
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
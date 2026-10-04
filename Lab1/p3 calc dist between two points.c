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
                int x1,y1,x2,y2;
                printf("Enter x then y for point1:");
                get_usr_num(&x1);
                get_usr_num(&y1);
                printf("Enter x then y for point2:");
                get_usr_num(&x2);
                get_usr_num(&y2);
                
                double dist=sqrt(pow(((double)x1-(double)x2),2.0)+pow(((double)y1-(double)y2),2.0) );
                printf(">>Distance between point1 and point2 is : %.3f \n",dist);
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
// Online C compiler (editor)
// Write and run C online using this editor.

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
void get_usr_num(int *num);
void Flush(void);


// start of program function declaration

// end of program function declaration
int main()
{

    char cmd = 'y';
    do
    {
        ////start of program
        // inputs
        int dec_num = 0;
        do
        {
            printf("Enter the number:");
            get_usr_num(&dec_num);

        } while ((dec_num < 0||dec_num>255) && printf("number must be positive integer only.\n"));
        //asssume it is 8- bit num
        unsigned char* bin_arr=(char*) calloc(8,sizeof(char));
        unsigned char base=128;
        for(int i=7;i>=0;i--,base=base>>1)
        {
            if(dec_num>=base)
            {
                bin_arr[i]=1;
                dec_num-=base;
            }
        }
        //print the binary value
        printf("binray number : 0b");
        for(int i=7;i>=0;i--)
        {
            printf("%d",bin_arr[i]);
            if(i==4)
            {
                printf("-");
            }
        }
        printf("\n");
        free(bin_arr);
        /// end of program
        Flush();
        printf("if you need another calculatoin press 'y'.\n");
        cmd = getchar();
    } while (cmd == 'y');
    printf("program end.");

    return 0;
}

// start of program function impelementation

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
void Flush(void)
{
    while (getchar() != '\n')
        ;
}
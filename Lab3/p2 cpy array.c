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
        int size = 0;
        do
        {
            printf("Enter size of array:");
            get_usr_num(&size);

        } while ((size < 0) && printf("Size must be positive integer only.\n"));

        // allocate the size
        int *arr = (int *)calloc(size, sizeof(int));
        // get array elements
        printf("Enter array elements:\n");
        for (int i = 0; i < size; i++)
        {
            printf("%d .", i + 1);
            get_usr_num((arr + i));
        }

        // copy to another array
        int *arr2 = (int *)calloc(size, sizeof(int));
        for (int i = 0; i < size; i++)
        {
            arr2[i] = arr[i];
        }
        // print old and new array
        printf("arr1 \t arr2\n");
        for (int i = 0; i < size; i++)
        {
            printf("%4d \t %4d\n", arr[i], arr2[i]);
        }
        printf("\n");

        free(arr);
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
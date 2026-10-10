// Online C compiler (editor)
// Write and run C online using this editor.

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
void get_usr_num(int *num);
void Flush(void);
void swap(int *arr, int a_index, int b_index);
void sort(int *arr, int size);

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

        } while ((size <= 0) && printf("Size must be positive integer only.\n"));

        // allocate the size
        int *arr = (int *)calloc(size, sizeof(int));
        // get array elements
        printf("Enter array elements:\n");
        for (int i = 0; i < size; i++)
        {
            printf("%d .", i + 1);
            get_usr_num((arr + i));
        }

        sort(arr, size);
            // print  array
        printf("arr sorted");
        for (int i = 0; i < size; i++)
        {
            printf("%4d ", arr[i]);
        }
        printf("\n");
        // count prv_val appearances and keep prv_val
        int prv_c = 0;
        int prv_val = arr[0];
        printf("The unique elements in array:\n");
        // print unique duplicate
        for (int i = 1; i < size; i++)
        {
            // same as prev
            if (arr[i] == prv_val)
            {
                prv_c++;
            }
            else
            {

                if (prv_c == 0)
                {
                    printf("%d\n", prv_val);
                }
                prv_val = arr[i];
                prv_c = 0;
            }
        }
        // handle last elment is unique
        if (prv_c == 0)
        {
            printf("%d\n", prv_val);
        }
    

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
void swap(int *arr, int a_index, int b_index)
{
    int temp = arr[a_index];
    arr[a_index] = arr[b_index];
    arr[b_index] = temp;
}
void sort(int *arr, int size)
{
    // bubble sort
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - 1 - i; j++)
        {
            // arrange ascend
            if (arr[j] > arr[j + 1])
            {
                swap(arr, j, j + 1);
            }
        }
    }
}
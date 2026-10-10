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
        int dup_c = 0;
        int prv_val = arr[0];
        // count duplicate
        for (int i = 1; i < size; i++)
        {
            if (arr[i] == arr[i - 1])
            {
                dup_c++;
                // pass all elements with this val
                prv_val = arr[i];
                while (arr[i] == prv_val && i < size)
                    i++;
            }
        }
        printf("number of duplicates:%4d.\n", dup_c);
        // print  array
        printf("arr");
        for (int i = 0; i < size; i++)
        {
            printf("%4d ", arr[i]);
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
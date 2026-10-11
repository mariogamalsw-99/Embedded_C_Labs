// Online C compiler (editor)
// Write and run C online using this editor.

#include <stdio.h>

#include <stdlib.h>
void get_usr_num(int *num);
void Flush(void);

// start of program function declaration
int get_max(int* arr,int size);
int get_min(int* arr,int size);
void swap(int *arr, int a_index, int b_index);
void sort(int *arr, int size);
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

       //get min and max values
       int min=get_min(arr,size),max=get_max(arr,size);
       printf("max:%4d , min:%4d\n",max,min);
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
int get_max(int* arr,int size)
{
    int max_v=arr[0];
    for ( int i=1;i<size;i++)
    {
        if(max_v<arr[i])
        {
            max_v=arr[i];
        }
    }
    return max_v;
}
int get_min(int* arr,int size){
    int min_v=arr[0];
    for ( int i=1;i<size;i++)
    {
        if(min_v>arr[i])
        {
            min_v=arr[i];
        }
    }
    return min_v;
}
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
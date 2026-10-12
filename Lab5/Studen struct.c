#include <stdio.h>
#include <stdlib.h>
#define NAMESIZE 30
typedef struct
{
    char name[NAMESIZE];
    int age;
    float total_marks;
} student;

void get_usr_num(int *num);
void get_usr_float(float *);
void Flush(void);
void scan_string(char *str, const int size);
//structfunctions
void get_student_input(student *);
void disp_student_info(student *);
void swap(student *arr, int a_index, int b_index);
void sort_std(student *arr, int size);


int main()
{
    // inputs
    int size = 0;
    do
    {
        printf("Enter num of students:");
        get_usr_num(&size);

    } while ((size < 0) && printf("um of students must be positive integer only.\n"));

    // allocate the size
    student *stud_arr = (student *)calloc(size, sizeof(student));
    // get array elements
    for (int i = 0; i < size; i++)
    {
        get_student_input((stud_arr+i));
    }
    printf("%30s \t %5s \t %5s","Student Name","age","Total Marks\n");
    //for calc avg get sum 
    double sum_m=0;
    for (int i = 0; i < size; i++)
    {
        sum_m+=stud_arr[i].total_marks;
        disp_student_info((stud_arr+i));
    }
    //sort students
    sort_std(stud_arr,size);
    printf("Avg total marks:%5.2f\nHigher Marks:%5.2f\n",(sum_m/size),(stud_arr[0].total_marks) );
    printf("TOP 3 Ranked.\n");
    for(int i=0;i<3&&i<size;i++)
    {
        printf("#%d .%s (%5.2f)\n",i+1,stud_arr[i].name,stud_arr[i].total_marks);
    }
    free(stud_arr);
    return 0;
}

void get_student_input(student * mystd)
{
    static int i=1;
       printf("Enter student%d:\n", i);
        printf("name:");
        scan_string(mystd->name, NAMESIZE);
        printf("age:");
        get_usr_num(&(mystd->age));
        printf("total mark:");
        get_usr_float(&(mystd->total_marks));
    i++;
}
void disp_student_info(student * mystd)
{
    printf("%30s \t %2dY \t %5.2fM\n",mystd->name,mystd->age,mystd->total_marks);
}
void sort_std(student *arr, int size)
{
    // bubble sort
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - 1 - i; j++)
        {
            // arrange ascend
            if (arr[j].total_marks < arr[j + 1].total_marks)
            {
                swap(arr, j, j + 1);
            }
        }
    }
}
void swap(student *arr, int a_index, int b_index)
{
    student temp = arr[a_index];
    arr[a_index] = arr[b_index];
    arr[b_index] = temp;
}
void get_usr_num(int *num)
{
    int status = 0;
    do
    {
        status = scanf("%d", num);
        if (status != 1)
        {
            Flush();
            printf("please enter positive only!!\n");
        }
        Flush();
    } while (status != 1);
}
void get_usr_float(float *num)
{
    int status = 0;
    do
    {
        status = scanf("%f", num);
        if (status != 1)
        {
            Flush();
            printf("please enter  float number only!!\n");
        }
        Flush();
    } while (status != 1);
}
void Flush(void)
{
    while (getchar() != '\n')
        ;
}
void scan_string(char *str, const int size)
{
    int i = 0;
    for (i = 0; i < size - 1; i++)
    {
        scanf("%c", str + i);
        if (*(str + i) == '\n')
            break;
    }
    *(str + i) = '\0';
}
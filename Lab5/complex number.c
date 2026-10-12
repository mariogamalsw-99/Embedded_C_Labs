#include <stdio.h>
#include <stdlib.h>
// struct
typedef struct
{
    float r;
    float i;
} complex_number;

// functions
complex_number add_complex(const complex_number, const complex_number);
complex_number multipy_complex(const complex_number, const complex_number);
void get_usr_complex(complex_number *);
void print_complex(const complex_number *);
//internal function
static void Flush(void)
{
    while (getchar() != '\n')
        ;
}
static void get_usr_float(float * num)
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
//app
int main()
{
    complex_number x,y;
    printf("enter x:\n");
    get_usr_complex(&x);
    printf("enter y:\n");
    get_usr_complex(&y);
    complex_number sum=add_complex(x,y);
    complex_number prod=multipy_complex(x,y);
    printf("x+y=");
    print_complex( &sum);
    printf("\n");
    printf("x*y=");
    print_complex( &prod);
    printf("\n");
    return 0;
}


/// implementatoin
complex_number add_complex(const complex_number x, const complex_number y)
{
    complex_number res;
    res.i = x.i + y.i;
    res.r = x.r + y.r;
    return res;
}
complex_number multipy_complex(const complex_number x, const complex_number y)
{
    complex_number res;
    res.i = ((x.r*y.i)+(x.i*y.r));
    res.r = ((x.r*y.r)-(x.i*y.i));
    return res;
}
void get_usr_complex(complex_number * comp_ptr)
{
    printf("Enter Real Part:");
    get_usr_float(&(comp_ptr->r));
    printf("Enter Imaginary Part:");
    get_usr_float(&(comp_ptr->i));
}

void print_complex(const complex_number *comp_ptr )
{
    printf("%f + %fi",comp_ptr->r,comp_ptr->i);
}

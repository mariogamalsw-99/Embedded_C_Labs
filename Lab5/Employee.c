#define DEBUG
#define IDSIZE 16
#define NAMESIZE 30
#define COMPANYSIZE 15
#include <string.h>
#include <stdio.h>
typedef enum
{
    EMP_TYPE_FULL_TIME,
    EMP_TYPE_PART_TIME,
    EMP_TYPE_INTERN
} EEmployeeType;
typedef enum
{
    EMP_DEPART_DEVELOPMENT,
    EMP_DEPART_TESTING,
    EMP_DEPART_CICD,
    EMP_DEPART_MANGMENT
} EEmployeeDepartment;
typedef struct
{
    char id[IDSIZE];
    char name[NAMESIZE];
    EEmployeeDepartment department;
    EEmployeeType type;
    bool deleted;
    union
    {
        unsigned int hourly_rate;
        unsigned int salary;
    };
} Employee_t;

// statci variables for company employee
// physical size (hold delted employees)
static unsigned int s_Company_size = 4;
static unsigned int s_Company_size_logical = 4;

static Employee_t s_Company_HR[COMPANYSIZE] =

    {
        {.id = "00001",
         .name = "Mario Gamal",
         .department = EMP_DEPART_DEVELOPMENT,
         .type = EMP_TYPE_FULL_TIME,
         .salary = __UINT16_MAX__},
        {.id = "00002",
         .name = "Hamada S",
         .department = EMP_DEPART_MANGMENT,
         .type = EMP_TYPE_FULL_TIME,
         .salary = 5000},
        {.id = "00003",
         .name = "kareem sanad",
         .department = EMP_DEPART_TESTING,
         .type = EMP_TYPE_PART_TIME,
         .hourly_rate = 50},
        {.id = "00004",
         .name = "Mahmoud Mohamed",
         .department = EMP_DEPART_CICD,
         .type = EMP_TYPE_INTERN,
         .hourly_rate = 10},
};

// public functions
void EMP_DispAllEmp();
void EMP_AddEmployee(Employee_t);
void EMP_RemoveEmployee(Employee_t);
void EMP_FilterByDepartment(EEmployeeDepartment, Employee_t searchResults[], unsigned int *searchSize, int maxResults);
void EMP_FilterByEmployeeType(EEmployeeType t, Employee_t searchResults[], unsigned int *searchSize, int maxResults);
unsigned int EMP_TotalPayrll();
Employee_t EMP_SearchByID(char *);
// static functions
char *depToStr(EEmployeeDepartment d)
{

    switch (d)
    {
    case EMP_DEPART_DEVELOPMENT:
        return "Development Department";
    case EMP_DEPART_TESTING:
        return "Testing Department";
    case EMP_DEPART_CICD:
        return "CI/CD Department";
    case EMP_DEPART_MANGMENT:
        return "Mangment Department";
    default:
        return "Department not defined!!";
    }
}
char *typToStr(EEmployeeType t)
{

    switch (t)
    {
    case EMP_TYPE_FULL_TIME:
        return "Full Time Employee";
    case EMP_TYPE_INTERN:
        return "Intern Employee";
    case EMP_TYPE_PART_TIME:
        return "Part Time Employee";

    default:
        return "Employee Type not defined!!";
    }
}
char *typToUnitStr(EEmployeeType t)
{

    switch (t)
    {
    case EMP_TYPE_FULL_TIME:
        return "$";
    case EMP_TYPE_INTERN:
    case EMP_TYPE_PART_TIME:
        return "$/h";
    default:
        return "Employee Type not defined!!";
    }
}
void dispEmp(Employee_t e)
{
    printf("%-5s|%-20s |%-30s|%-20s|%d%s\n", e.id, e.name, depToStr(e.department), typToStr(e.type), e.salary, typToUnitStr(e.type));
}
int main()
{
    EMP_DispAllEmp();
    printf("\t\t____ADD new 2emp____\n");
    Employee_t e={
        .id="Temp1",
        .name="Ay7aga",
        .type=EMP_TYPE_INTERN,
        .department=EMP_DEPART_TESTING,
        .hourly_rate=12
    };
    EMP_AddEmployee(e);
    Employee_t e2={
        .id="Temp2",
        .name="BlaBla",
        .type=EMP_TYPE_FULL_TIME,
        .department=EMP_DEPART_MANGMENT,
        .salary=50000
    };
    EMP_AddEmployee(e2);
    EMP_DispAllEmp();
    printf("\t\t____Remove  emp____\n");
    EMP_RemoveEmployee(e);
    EMP_DispAllEmp();
    unsigned int serchsize=5;
    Employee_t saerchres[5];
    EMP_FilterByDepartment(EMP_DEPART_MANGMENT,saerchres,&serchsize,3);
    EMP_FilterByEmployeeType(EMP_TYPE_PART_TIME,saerchres,&serchsize,3);
    Employee_t me= EMP_SearchByID("00001");
    printf("returned in main emp:");
    dispEmp(me);
    
    
    EMP_DispAllEmp();
    printf("total payroll=%d\n",EMP_TotalPayrll());

   return 0;

}
// function definetion
void EMP_DispAllEmp()
{
    for (int i = 0; i < s_Company_size; i++)
    {
        if (!s_Company_HR[i].deleted)
            dispEmp(s_Company_HR[i]);
    }
}
void EMP_AddEmployee(Employee_t e)
{
    s_Company_HR[s_Company_size++] = e;
    s_Company_size_logical++;
}
void EMP_RemoveEmployee(Employee_t e)
{
    for (int i = 0; i < s_Company_size; i++)
    {
        if ((strcmp(e.id, s_Company_HR[i].id) == 0) && (strcmp(e.name, s_Company_HR[i].name) ==0))
        {
            s_Company_HR[i].deleted = 1;
            s_Company_size_logical--;
            break;
        }
    }
}
void EMP_FilterByDepartment(EEmployeeDepartment d, Employee_t searchResults[], unsigned int *searchSize, int maxResults)
{

    *searchSize = 0;
    for (int i = 0; i < s_Company_size; i++)
    {
        if (d == s_Company_HR[i].department && !s_Company_HR[i].deleted)
        {
            searchResults[*searchSize] = s_Company_HR[i];
            (*searchSize)++;
            if ((*searchSize) >= maxResults)
            {
                break;
            }
        }
    }
#ifdef DEBUG
    printf("The results for filter by %s:\n", depToStr(d));
    for (int j = 0; j < *searchSize; j++)
    {
        dispEmp(searchResults[j]);
    }
#endif
}
void EMP_FilterByEmployeeType(EEmployeeType t, Employee_t searchResults[], unsigned int *searchSize, int maxResults)
{

    *searchSize = 0;
    for (int i = 0; i < s_Company_size; i++)
    {
        if (t == s_Company_HR[i].type && !s_Company_HR[i].deleted)
        {
            searchResults[*searchSize] = s_Company_HR[i];
            (*searchSize)++;
            if ((*searchSize) >= maxResults)
            {
                break;
            }
        }
    }

#ifdef DEBUG
    printf("The results for filter by %s:\n", typToStr(t));
    for (int j = 0; j < *searchSize; j++)
    {
        dispEmp(searchResults[j]);
    }
#endif
}
unsigned int EMP_TotalPayrll()
{
    unsigned int res = 0;
    for (int i = 0; i < s_Company_size; i++)
    {
        if (!s_Company_HR[i].deleted)
        {
            switch (s_Company_HR[i].type)
            {
            case EMP_TYPE_PART_TIME:
            case EMP_TYPE_INTERN:
                res += (s_Company_HR[i].hourly_rate * 40);
                break;
            case EMP_TYPE_FULL_TIME:
                res += s_Company_HR[i].salary;
                break;
            default:
                printf("OUT of Scope employee type\n");
                break;
            }
        }
    }

    return res;
}
Employee_t EMP_SearchByID(char *srchtxt)
{
    Employee_t res = {.id="notfount",.name= "notfound",.department= -1,.type= -1,.hourly_rate= -1};
    for (int i = 0; i < s_Company_size; i++)
    {
        if (!s_Company_HR[i].deleted && strcmp(s_Company_HR[i].id, srchtxt) == 0)
        {
            res = s_Company_HR[i];
            break;
        }
    }
#ifdef DEBUG
    printf("The results for filter by %s:\n", srchtxt);

    dispEmp(res);

#endif
    return res;
}
#include "mysting.h"
#include <stdlib.h>
char *mystr_memchr(char *s, char ch, unsigned int size)
{
    char *ptr = s;
    unsigned int i;
    for (i = 0; i < size; i++, ptr++)
    {
        if (*ptr == ch)
        {
            break;
        }
    }
    if (i >= size)
        return nullptr;
    else
        return ptr;
}
int mystr_memcmp(void *p1, void *p2, unsigned int size)
{
    // iterator
    char *ptr1_it = (char *)p1;
    char *ptr2_it = (char *)p2;
    int cmp_res = 0;
    unsigned int i;
    for (i = 0; i < size && cmp_res == 0; i++, ptr1_it++, ptr2_it++)
    {
        cmp_res = *(ptr1_it) - *(ptr2_it);
    }
    return cmp_res;
}
void mystr_memcpy(void *pDest, void *pSrc, unsigned int size)
{
    // iterator
    char *ptr_dest_it = (char *)pDest;
    char *ptr_src_it = (char *)pSrc;
    unsigned int i;
    for (i = 0; i < size; i++, ptr_src_it++, ptr_dest_it++)
    {
        *(ptr_dest_it) = *(ptr_src_it);
    }
}
void mystr_memmove(void *pDest, void *pSrc, unsigned int size)
{
    // iterator
    char *ptr_dest_it = (char *)pDest;
    char *ptr_src_it = (char *)pSrc;
    char buffer[size];
    unsigned int i;
    for (i = 0; i < size; i++, ptr_src_it++)
    {
        buffer[i] = *(ptr_src_it);
    }
    for (i = 0; i < size; i++, ptr_dest_it++)
    {
        *(ptr_dest_it) = buffer[i];
    }
}

void mystr_memset(void *pDest, char val, unsigned int size)
{
    // iterator
    char *ptr_dest_it = (char *)pDest;
    unsigned int i;
    for (i = 0; i < size; i++, ptr_dest_it++)
    {
        *(ptr_dest_it) = val;
    }
}

char *mystr_strcat(char *pDest, char *pSrc)
{
    char *ptr_dest_it = pDest;
    // get the end of dest sting
    while (*ptr_dest_it != '\0')
    {
        ptr_dest_it++;
    }
    char *ptr_src_it = pSrc;
    // concat src
    while (*ptr_src_it != '\0')
    {
        *ptr_dest_it = *ptr_src_it;
        ptr_dest_it++;
        ptr_src_it++;
    }
    // add null in dest
    *ptr_dest_it = '\0';
    return pDest;
}
char *mystr_strchr(char *pDest, char c)
{
    char *res = nullptr;
    char *ptr_dest_it = pDest;
    while (*ptr_dest_it != '\0')
    {
        if (c == *ptr_dest_it)
        {
            res = ptr_dest_it;
            break;
        }
        ptr_dest_it++;
    }
    return res;
}
int mystr_strcmp(char *str1, char *str2)
{
    int cmp_res = 0;
    // string iterator
    char *str1_it = str1;
    char *str2_it = str2;
    while (*str1_it != '\0' && cmp_res == 0)
    {
        cmp_res = *(str1_it) - *(str2_it);
        str1_it++;
        str2_it++;
    }
    return cmp_res;
}
char *mystr_strcpy(void *strDest, void *strSrc)
{
    // iterator
    char *ptr_dest_it = strDest;
    char *ptr_src_it = strSrc;

    while (*ptr_src_it != '\0')
    {
        *(ptr_dest_it) = *(ptr_src_it);
        ptr_src_it++;
        ptr_dest_it++;
    }
    //add null char in end of dest
    *ptr_dest_it='\0';
    return strDest;
}
unsigned int mystr_strspn(char *str, const char *srch)
{
    unsigned int res = 0;
    char *search_it = srch;
    while (*str != '\0')
    {
        // search for all chars in str
        bool isexist = 0;
        search_it = srch;
        while (*search_it != '\0')
        {
            if (*search_it == *str)
            {
                isexist = 1;
                break;
            }
            search_it++;
        }
        if (isexist)
        {
            break;
        }
        res++;
        str++;
    }
    return res;
}
unsigned int mystr_strlen(char* str)
{
    unsigned int res=0;
    while(*str!='\0')
    {
        res++;
        str++;
    }
    return res;
}

char* mystr_strncat(char *pDest, char *pSrc,unsigned int n)
{
    char *ptr_dest_it = pDest;
    // get the end of dest sting
    while (*ptr_dest_it != '\0')
    {
        ptr_dest_it++;
    }
    char *ptr_src_it = pSrc;
    // concat src
    for (int i=0 ;i<n;i++ )
    {
        //Guard to stop coping if n exceeds null
        if(*ptr_src_it == '\0')
        {
            return nullptr;
        }
        *ptr_dest_it = *ptr_src_it;
        ptr_dest_it++;
        ptr_src_it++;
    }
    // add null in dest
    *ptr_dest_it = '\0';
    return pDest;
}
int mystr_strncmp(char *str1, char *str2,unsigned int n)
{
     int cmp_res = 0;
    // string iterator
    char *str1_it = str1;
    char *str2_it = str2;
     for (int i=0 ;i<n&&cmp_res==0;i++ )
    {
        //Guard to stop coping if n exceeds null
        if(*str1_it == '\0')
        {
            return -1;
        }
        cmp_res = *(str1_it) - *(str2_it);
        str1_it++;
        str2_it++;
    }
    return cmp_res;
}
char* mystr_strncpy(void *strDest, void *strSrc,unsigned int n)
{
     // iterator
    char *ptr_dest_it = strDest;
    char *ptr_src_it = strSrc;

    for (int i=0 ;i<n;i++ )
    {
        //Guard to stop coping if n exceeds null
        if(*ptr_src_it == '\0')
        {
            return nullptr;
        }
        *(ptr_dest_it) = *(ptr_src_it);
        ptr_src_it++;
        ptr_dest_it++;
    }
    return strDest;
}
char* mystr_strrchr(char *pDest, char c)
{
    char *res = nullptr;
    char *ptr_dest_it = pDest;
    while (*ptr_dest_it != '\0')
    {
        if (c == *ptr_dest_it)
        {
            res = ptr_dest_it;
        }
        ptr_dest_it++;
    }
    return res;
}
char* mystr_strstr(char * str, char* search)
{
    char *res = nullptr;
    char *ptr_str_it = str;
    while (*ptr_str_it != '\0')
    {
        if (mystr_strncmp(ptr_str_it,search,mystr_strlen(search))==0 )
        {
            res = ptr_str_it;
            break;
        }
        ptr_str_it++;
    }
    return res;
}

char *mystr_strtok(char *str, const char *delimeters)
{
    static char *s_str_it = nullptr;
    static char *s_res = nullptr;
    if (s_res == nullptr)
        s_res = (char *)malloc(sizeof(char));
    // if new string set it as str_it
    if (str != nullptr)
        s_str_it = str;
    // error no string is called and or all string tokens are already returned
    if (s_str_it == nullptr)
        return nullptr;
    unsigned int tok_size = mystr_strspn(s_str_it, delimeters);
    // free previous tok and allocate new one
    if (tok_size != 0)
    {
        free(s_res);
        s_res = (char *)malloc((tok_size + 1) * sizeof(char));
        mystr_strncpy(s_res, s_str_it, tok_size);
        s_res[tok_size] = '\0';
        s_str_it += tok_size + 1;
        return s_res;
    }
    else // retur null
    {
        return nullptr;
    }
}
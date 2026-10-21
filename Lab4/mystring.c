#include "mysting.h"
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
    int cmp_res = 0;
    unsigned int i;
    for (i = 0; i < size && cmp_res == 0; i++, ptr_src_it++, ptr_dest_it++)
    {
        *(ptr_dest_it) =*(ptr_src_it);
    }
}
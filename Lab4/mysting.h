#ifndef MYSTING_H
#define MYSTING_H

//Get a pointer to the first byte in a block of memory which contains a specified value
char* mystr_memchr(char*,char,unsigned int);
int mystr_memcmp(void* p1,void* p2,unsigned int size);
void mystr_memcpy(void *pDest, void *pSrc, unsigned int size);
#endif /* COMPLEX_NUMBER_H */

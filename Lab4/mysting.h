#ifndef MYSTING_H
#define MYSTING_H

// Get a pointer to the first byte in a block of memory which contains a specified value
char *mystr_memchr(char *, char, unsigned int);
int mystr_memcmp(void *p1, void *p2, unsigned int size);
void mystr_memcpy(void *pDest, void *pSrc, unsigned int size);
void mystr_memmove(void *pDest, void *pSrc, unsigned int size);
void mystr_memset(void *pDest, char val, unsigned int size);
char *mystr_strcat(char *pDest, char *pSrc);
int mystr_strcmp(char *, char *);
char *mystr_strcpy(void *strDest, void *strSrc);
char *mystr_strchr(char *pDest, char c);
unsigned int mystr_strspn(char *str, const char *srch);
unsigned int mystr_strlen(char *str);
char *mystr_strncat(char *pDest, char *pSrc, unsigned int n);
int mystr_strncmp(char *, char *, unsigned int n);
char *mystr_strncpy(void *strDest, void *strSrc, unsigned int n);
char *mystr_strrchr(char *pDest, char c);
char *mystr_strstr(char *str, char *search);
char *mystr_strtok(char *str, const char *delimeters);
#endif /* COMPLEX_NUMBER_H */

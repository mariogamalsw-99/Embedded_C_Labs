#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BOOKTITLESIZE 30
#define BOOKAUTHORSIZE 30
#define LIBRSRYSIZE 10

// book status
typedef enum
{
    BOOK_IS_AVAILABLE,
    BOOK_IS_NOT_AVAILABLE
} EBookStatus;
// bookcategory
typedef enum
{
    BOOK_CATEGORY_FICTION,
    BOOK_CATEGORY_NON_FICTION,
    BOOK_CATEGORY_SCIENCE,
    BOOK_CATEGORY_TECHNOLOGY,
    BOOK_CATEGORY_HISTORY,
    BOOK_CATEGORY_BIOGRAPHY,
    BOOK_CATEGORY_FANTASY,
    BOOK_CATEGORY_MYSTERY,
    BOOK_CATEGORY_ROMANCE,
    BOOK_CATEGORY_SELF_HELP,
    BOOK_CATEGORY_EDUCATION,
    BOOK_CATEGORY_POETRY,
    BOOK_CATEGORY_COMICS,
    BOOK_CATEGORY_CHILDREN,
    BOOK_CATEGORY_OTHER,
    BOOK_CATEGORY_COUNT
} EBookCategory;

// book struct
typedef struct
{
    char title[BOOKTITLESIZE];
    char author[BOOKAUTHORSIZE];
    float price;
    EBookCategory category;
    EBookStatus isAvailable;
} Book_t;
// private variables
// system books max 100 book
static Book_t s_library[LIBRSRYSIZE] = {
    {.title = "Clean Code",
     .author = "Robert C. Martin",
     .price = 500,
     .category = BOOK_CATEGORY_TECHNOLOGY,
     .isAvailable = BOOK_IS_AVAILABLE},
    {.title = "The C Programming Language",
     .author = "Brian Kernighan",
     .price = 350,
     .category = BOOK_CATEGORY_TECHNOLOGY,
     .isAvailable = BOOK_IS_AVAILABLE},
    {.title = "The Hobbit",
     .author = "J.R.R. Tolkien",
     .price = 250,
     .category = BOOK_CATEGORY_FANTASY,
     .isAvailable = BOOK_IS_AVAILABLE},
    {.title = "1984",
     .author = "George Orwell",
     .price = 200,
     .category = BOOK_CATEGORY_HISTORY,
     .isAvailable = BOOK_IS_AVAILABLE},
    {.title = "The Pragmatic Programmer",
     .author = "Andrew Hunt",
     .price = 450,
     .category = BOOK_CATEGORY_SCIENCE,
     .isAvailable = BOOK_IS_AVAILABLE}};
static unsigned char s_book_count = 5;
// public functions
void LIBM_AddNewBook();
void LIBM_SearchBook(char *srchtxt, int *search_results, int *search_results_size, int search_limit);
void LIBM_ChangeStatus(int bookID, EBookStatus newStatus);
void LIBM_CountInCatg(EBookCategory catg);
void LIBM_PrintAllBooks();

// internal functions
static void Flush(void)
{
    while (getchar() != '\n')
        ;
}
static void GetUsrNum(int *num)
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
static void GetUsrFloat(float *num)
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
static void GetUsrBookCatg(EBookCategory *mycatg)
{
    do
    {
        GetUsrNum((int *)mycatg);
    } while ((*mycatg < 0) || (*mycatg >= BOOK_CATEGORY_COUNT) && printf(">>Please pirck from printed numbers only<<<\n"));
}
static void ScanString(char *str, const int size)
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
static void PrintCatgMap()
{
    printf("0. Fiction\n");
    printf("1. Non-Fiction\n");
    printf("2. Science\n");
    printf("3. Technology\n");
    printf("4. History\n");
    printf("5. Biography\n");
    printf("6. Fantasy\n");
    printf("7. Mystery\n");
    printf("8. Romance\n");
    printf("9. Self-Help\n");
    printf("10. Other\n");
}
static const char *GetCatgName(EBookCategory catg)
{
    switch (catg)
    {
    case BOOK_CATEGORY_FICTION:
        return "Fiction";
    case BOOK_CATEGORY_NON_FICTION:
        return "Non-Fiction";
    case BOOK_CATEGORY_SCIENCE:
        return "Science";
    case BOOK_CATEGORY_TECHNOLOGY:
        return "Technology";
    case BOOK_CATEGORY_HISTORY:
        return "History";
    case BOOK_CATEGORY_BIOGRAPHY:
        return "Biography";
    case BOOK_CATEGORY_FANTASY:
        return "Fantasy";
    case BOOK_CATEGORY_MYSTERY:
        return "Mystery";
    case BOOK_CATEGORY_ROMANCE:
        return "Romance";
    case BOOK_CATEGORY_SELF_HELP:
        return "Self-Help";
    case BOOK_CATEGORY_OTHER:
        return "Other";
    default:
        return "Unknown Category";
    }
}
static void GetBookCateg(Book_t *book_ptr)
{
    // print
    PrintCatgMap();
    printf(">Which Category is this book(pick number from previous list):");
    GetUsrBookCatg(&(book_ptr->category));
}
static void PrintBookInfo(Book_t *book_ptr)
{
    printf("|Title: %-30s\t", book_ptr->title);
    printf("|Author: %-30s\t", book_ptr->author);
    printf("|Price: %.2f\t", book_ptr->price);
    printf("|Category: %-20s\t", GetCatgName(book_ptr->category));
    printf("|Status: %-20s\n", (book_ptr->isAvailable == BOOK_IS_AVAILABLE) ? "Available" : "Not Available");
}
// main to test the library management functions
int main()
{
    // LIBM_AddNewBook();
    LIBM_PrintAllBooks();
    int search_results_size = 10;
    int arr[10];
    LIBM_ChangeStatus(3, BOOK_IS_NOT_AVAILABLE);
    LIBM_SearchBook("19", arr, &search_results_size, 10);
    LIBM_ChangeStatus(3, BOOK_IS_AVAILABLE);
    LIBM_SearchBook("19", arr, &search_results_size, 10);
    LIBM_CountInCatg(BOOK_CATEGORY_TECHNOLOGY);
    return 0;
}

// implement
void LIBM_AddNewBook()
{
    // check library size
    if (s_book_count < LIBRSRYSIZE)
    {

        printf("Add book number%d:\n", s_book_count + 1);
        printf(">Book Title:");
        ScanString(s_library[s_book_count].title, BOOKTITLESIZE);
        printf(">Book Authour:");
        ScanString(s_library[s_book_count].author, BOOKAUTHORSIZE);
        printf(">Book Price:");
        GetUsrFloat(&(s_library[s_book_count].price));
        GetBookCateg(s_library + s_book_count);
        // default status for new book is available
        s_library[s_book_count].isAvailable = BOOK_IS_AVAILABLE;
        // move to next book location
        s_book_count++;
    }
    else
    {
        printf("SORRY library is full it has % books. !!!!!!!!!!\n", LIBRSRYSIZE);
    }
}
// return array of book ids that match the search text in title or author and search limit to limmit the size
void LIBM_SearchBook(char *srchtxt, int *search_results, int *search_results_size, int search_limit)
{
    *search_results_size = 0;
    // i index for search_results array
    int i = 0;
    for (int j = 0; j < s_book_count; j++)
    {
        if (strstr(s_library[j].title, srchtxt) != NULL || strstr(s_library[j].author, srchtxt) != NULL)
        {
            search_results[i++] = j;
            (*search_results_size)++;
            if (*search_results_size >= search_limit)
                break;
        }
    }
    printf("Search results for '%s':\n", srchtxt);
    for (int k = 0; k < *search_results_size; k++)
    {
        printf("Book ID: %d\t", search_results[k] + 1);
        PrintBookInfo(&s_library[search_results[k]]);
    }
}

void LIBM_ChangeStatus(int bookID, EBookStatus newStatus)
{
    s_library[bookID].isAvailable = newStatus;
}
void LIBM_CountInCatg(EBookCategory catg)
{
    int count = 0;
    for (int i = 0; i < s_book_count; i++)
    {
        if (s_library[i].category == catg)
        {
            count++;
        }
    }
    printf("Number of books in category '%s': %d\n", GetCatgName(catg), count);
}
void LIBM_PrintAllBooks()
{
    printf("Library has %d books:\n", s_book_count);
    for (int i = 0; i < s_book_count; i++)
    {
        printf("Book ID: %d\t", i + 1);
        PrintBookInfo(&s_library[i]);
    }
}
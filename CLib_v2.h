#ifndef DEF_CLIBV2
#define DEF_CLIBV2

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifdef __WIN32__
    #define CLEAR "cls"
#else
    #define CLEAR "clear"
#endif

typedef struct Coords
{
    int x;
    int y;
    int z;
} Coords;


/*###########################
    ALLOCATION CHECKING
############################*/

/* #ADDED TO DOC
    Checks if a pointer points on NULL
    If the adress given in parameter is NULL (or 0), it stops the program with an error code
*/
void check_alloc(void* p);

/* #ADDED TO DOC
    Checks if a pointer points on NULL
    If the adress given in parameter is NULL (or 0), it returns 0.

    RETURN VALUES
    0 → Pointer is NULL or 0
    1 → Pointer is not NULL or not 0
*/
int check_alloc_noExit(void* p);


/*###########################
      ARRAY MANAGEMENT
############################*/

/* #ADDED TO DOC
    Returns a two dimensionnal integers array (array of arrays)

    Parameters:
        int dim1 → the number of sub-arrays
        int dim2 → the size of sub-arrays

    /!\ WARNING /!\
        Using this function may cause the program to stop if a problem occurs with memory allocation due to use of check_alloc() function
*/
int** new_2D_int_array(int dim1, int dim2);

/* #ADDED TO DOC
    Returns a two dimensionnal float array (array of arrays)

    Parameters:
        int dim1 → the number of sub-arrays
        int dim2 → the size of sub-arrays

    /!\ WARNING /!\
        Using this function may cause the program to stop if a problem occurs with memory allocation due to use of check_alloc() function
*/
float** new_2D_float_array(int dim1, int dim2);

/* #NOT FONCTIONNAL
    Frees a two dimensionnal array of any type

    Parameters:
        void** array → the 2D array to free
        int dim1 → the number of sub-arrays
*/
void free_2D_array(void** array, int dim1);


/*###########################
      RANDOM MANAGEMENT
############################*/

/*  #ADDED TO DOC
    Inits the random for a program

    USE: put this function at the beginning of the main() function
*/
void init_random();

/* #ADDED TO DOC
    Returns an integer between the two specified bounds
    This function detects which bound is the lower one

    Parameters:
        int infBound → lower bound
        int supBound → upper bound
*/
int random_int(int infBound, int supBound);


/*###########################
      STRING MANAGEMENT
############################*/

/*
    Reads a string from user input (stdin) (dynamic allocation, needs to be freed)

    Return value: string read from user input
*/
char* getString();

/*
    Reads a string from stream or file (dynamic allocation, needs to be freed)

    Return value : string read from stream or file
*/
char* getString_stream(FILE* stream);

/*################################
      LINKED LISTS MANAGEMENT
#################################*/

//#ADDED TO DOC
//Linked list
typedef struct LList
{
    int val;
    struct LList* next;
    struct LList* prev;
} LList;

/* #ADDED TO DOC
    Inits a Linked list (LList)

    Return value: pointer on the first element of the LList
*/
LList* init_LList(int size);

/* #ADDED TO DOC
    Frees a Linked list (LList) from the node given as parameter
*/
void free_partialLList(LList* myList);

/* #ADDED TO DOC
    Frees the entire LList given as parameter

    Parameters:
        LList* myList → pointer on any element (node) of the LList
*/
void free_LList(LList* myList);

/* #ADDED TO DOC
    Jumps to the next element (node) (if existing) in the LList given as parameter

    Parameters
        LList* myList → pointer on a LList element (node)
*/
void next_LList(LList* myList);

/* #ADDED TO DOC
    Jumps to the previous element (node) (if existing) in the LList given as parameter

    Parameters
        LList* myList → pointer on a LList element (node)
*/
void prev_LList(LList* myList);

/* #ADDED TO DOC
    Returns the size of the linked list given as parameter

    Parameters:
        LList myList → Any element (node) of a linked list
*/
int size_LList(LList myList);

/* #ADDED TO DOC
    Sets the active element of the given LList to its first element

    Parameters:
        LList* myList → pointer on any element of a LList
*/
void goFirst_LList(LList* myList);

/*#ADDED TO DOC
    Sets the active element of the given LList to its last element

    Parameters:
        LList* myList → pointer on any element of a LList
*/
void goLast_LList(LList* myList);

/* #ADDED TO DOC
    Adds an element to the end of a LList (by creating a new node at its end)

    DOES NOT CHANGE THE ACTIVE LLIST ELEMENT

    Parameters
        LList* myList → pointer on any element of the LList
        int value → value to add to the LList
*/
void pushback_LList(LList* myList, int value);

/* #ADDED TO DOC
    Removes the last element (node) from the given LList

    Parameters:
        LList* myList → pointer on any element of the LList

    Return value:
        Value of the last element of the given LList
*/
int pop_LList(LList* myList);

/* #ADDED TO DOC
    Returns the index (subscript) of the active element in the given LList

    Parameters:
        LList* myList → pointer on the active element of the LList

    Return value:
        Index (subscript) of the given element (node) in the LList
*/
int getPos_LList(LList* myList);

/* #ADDED TO DOC
    Inserts a new element (node) right after the active element of the given LList

    Parameters:
        LList* myList → pointer on the active element of the LList
        int value → value to insert
*/
void insertNext_LList(LList* myList, int value);

/* #ADDED TO DOC
    Inserts a new element (node) right before the active element of the given LList

    Parameters:
        LList* myList → pointer on the active element of the LList
        int value → value to insert
*/
void insertPrev_LList(LList* myList, int value);

/* #ADDED TO DOC
    Removes the active element (node) in the given LList

    Parameters:
        LList* myList → pointer on the element to remove to the LList

    Return value:
        Value of the removed element (node)
*/
int remove_LList(LList* myList);


/*##############################
      ERGONOMY MANAGEMENT
###############################*/

/*
    Clears console screen, regardless of the OS
*/
void clear_screen();

#endif

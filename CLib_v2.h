#ifndef DEF_CLIBV2
#define DEF_CLIBV2

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


/*###########################
    ALLOCATION CHECKING
############################*/

/*
    Checks if a pointer points on NULL
    If the adress given in parameter is NULL (or 0), it stops the program with an error code
*/
void check_alloc(void* p);

/*
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

/*
    Returns a two dimensionnal integers array (array of arrays)

    Parameters:
        int dim1 → the number of sub-arrays
        int dim2 → the size of sub-arrays

    /!\ WARNING /!\
        Using this function may cause the program to stop if a problem occurs with memory allocation due to use of check_alloc() function
*/
int** new_2D_int_array(int dim1, int dim2);

/*
    Returns a two dimensionnal float array (array of arrays)

    Parameters:
        int dim1 → the number of sub-arrays
        int dim2 → the size of sub-arrays

    /!\ WARNING /!\
        Using this function may cause the program to stop if a problem occurs with memory allocation due to use of check_alloc() function
*/
float** new_2D_float_array(int dim1, int dim2);

/*
    Frees a two dimensionnal array of any type

    Parameters:
        void** array → the 2D array to free
        int dim1 → the number of sub-arrays
*/
void free_2D_array(void** array, int dim1);


/*###########################
      RANDOM MANAGEMENT
############################*/

/*
    Inits the random for a program

    USE: put this function at the beginning of the main() function
*/
void init_random();

/*
    Returns an integer between the two specified bounds
    This function detects which bound is the lower one

    Parameters:
        int infBound → lower bound
        int supBound → upper bound
*/
int random_int(int infBound, int supBound);

#endif

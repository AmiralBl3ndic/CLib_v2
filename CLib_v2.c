#include "CLib_v2.h"


/*###########################
    ALLOCATION CHECKING
############################*/

void check_alloc(void* p)
{
    if (!p)
        exit(EXIT_FAILURE);
}


int check_alloc_noExit(void* p)
{
    if (!p)
        return 0;

    return 1;
}



/*###########################
      ARRAY MANAGEMENT
############################*/

int** new_2D_int_array(int dim1, int dim2)
{
    int i = 0;
    int** array = (int**) malloc(dim1 * sizeof(int*));
    check_alloc(array);

    for (i = 0; i < dim2; i++)
    {
        array[i] = (int*) malloc(dim2 * sizeof(int));
        check_alloc(array[i]);
    }

    return array;
}


float** new_2D_float_array(int dim1, int dim2)
{
    int i = 0;
    float** array = (float**) malloc(dim1 * sizeof(float*));
    check_alloc(array);

    for (i = 0; i < dim2; i++)
    {
        array[i] = (float*) malloc(dim2 * sizeof(float));
        check_alloc(array[i]);
    }

    return array;
}


void free_2D_array(void** array, int dim1)
{
    int i = 0;

    for (i = 0; i < dim1; i++)
        free(array[i]);

    free(array);
}


/*###########################
      RANDOM MANAGEMENT
############################*/

void init_random()
{
    srand(time(NULL));
}


int random_int(int infBound, int supBound)
{
    if (infBound < supBound)
        return rand()%(supBound - infBound) + infBound;

    if (infBound > supBound)
        return rand()%(infBound - supBound) + supBound;

    return infBound;
}


/*###########################
      STRING MANAGEMENT
############################*/

char* getString()
{
    char* string = (char*) malloc(sizeof(char));
    char read;
    int chars = 1;

    while ((read = getchar()) != '\n')
    {
        string = (char*) realloc(string, ++chars * sizeof(char));
        string[chars - 2] = read;
    }

    string[chars - 1] = '\0';

    return string;
}


char* getString_stream(FILE* stream)
{
    char* string = (char*) malloc(sizeof(char));
    char read;
    int chars = 1;

    while ((read = fgetc(stream)) != '\n')
    {
        string = (char*) realloc(string, ++chars * sizeof(char));
        string[chars - 2] = read;
    }

    string[chars - 1] = '\0';

    return string;
}

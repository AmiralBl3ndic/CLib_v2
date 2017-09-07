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


/*TODO
    void pushback(int* array, int value)
*/

/*TODO
    pop(int* array)

    ==> Will need to free the array
*/

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


/*################################
      LINKED LISTS MANAGEMENT
#################################*/

LList* init_LList(int size)
{
    if (size <= 0)
        return NULL;

    int i = 0;
    LList *myList = malloc(sizeof(LList));
    LList *ret = myList;

    //Init LList
    for (i = 1; i < size; i++)
    {
        myList->next = malloc(sizeof(LList));
        check_alloc(myList->next);
        myList = myList->next;
    }

    myList->next = NULL;

    return ret;
}


void free_partialLList(LList* myList)
{
    if (myList->next != NULL)
        free_partialLList(myList->next);

    free(myList);
}


void free_LList(LList* myList)
{
    //Going to the first element (node)
    goFirst_LList(myList);

    //Freeing the list
    free_partialLList(myList);
}


void next_LList(LList* myList)
{
    if (myList->next != NULL)
        myList = myList->next;
}


void prev_LList(LList* myList)
{
    if (myList->prev != NULL)
        myList = myList->prev;
}


int size_LList(LList myList)
{
    int size = 1;
    LList *tmpList = myList.next;

    goFirst_LList(tmpList);

    //Computing the size of the list
    while (tmpList->next != NULL)
    {
        size++;
        tmpList = tmpList->next;
    }

    return size;
}


void goFirst_LList(LList* myList)
{
    while (myList->prev != NULL)
        myList = myList->prev;
}


void goLast_LList(LList* myList)
{
    while (myList->next != NULL)
        myList = myList->next;
}


void pushback_LList(LList* myList, int value)
{
    LList *tmp = myList;

    goLast_LList(tmp);

    //Allocating the new element
    tmp->next = malloc(sizeof(LList));
    check_alloc(tmp->next);

    //Setting the "new" last element
    (tmp->next)->prev = tmp;
    (tmp->next)->next = NULL;
    (tmp->next)->val = value;
}


int pop_LList(LList* myList)
{
    LList *tmp = myList;
    int ret;

    goLast_LList(tmp);

    ret = tmp->val;
    tmp = tmp->prev;

    free(tmp->next);

    tmp->next = NULL;

    return ret;
}


int getPos_LList(LList* myList)
{
    LList* tmp = myList;
    int pos = 0;

    goFirst_LList(tmp);

    while (tmp != myList)
    {
        tmp = tmp->next;
        pos++;
    }

    return pos;
}


void insertNext_LList(LList* myList, int value)
{
    LList* newElement = malloc(sizeof(LList));
    check_alloc(newElement);

    //Setting the new element
    newElement->next = myList->next;
    newElement->prev = myList;
    newElement->val = value;
    myList->next = newElement;
}


void insertPrev_LList(LList* myList, int value)
{
    LList* newElement = malloc(sizeof(LList));

    newElement->next = myList;
    newElement->prev = myList->prev;
    newElement->val = value;
    myList->prev = newElement;
}


int remove_LList(LList* myList)
{
    int value = myList->val;

    (myList->prev)->next = myList->next;
    (myList->next)->prev = myList->prev;

    free(myList);

    return value;
}


/*##############################
      ERGONOMY MANAGEMENT
###############################*/

void clear_screen()
{
    system(CLEAR);
}

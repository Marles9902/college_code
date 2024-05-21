// Marwin Gonzales 027340883
// CECS 326 assignment 5 myShm.h
// terminal input: NONE
// description: *provided in assignment* used to structure the shared memory segment and the unnamed semaphore

#include <semaphore.h>

struct CLASS
{
    int index;              // Index to next available response slot
    int response[10];       // Each child writes its child number and lucky number here
    sem_t semUnnamed;       // initialize unnamed semaphore to be used for controlling access to the shared index variable
};
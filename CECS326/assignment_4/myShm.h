// Marwin Gonzales 027340883
// CECS 326 assignment 4 myShm.h
// terminal input: NONE
// description: *provided in assignment* used to structure the shared memory segment

struct CLASS
{
    int index;              // Index to next available response slot
    int response[10];       // Each child writes its child number and lucky number here
};
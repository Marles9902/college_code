// Marwin Gonzales 027340883
// CECS 326 assignment 3 slave.cpp
// terminal input: NONE
// description: outputs its child number as well as shared memory segment name passed from exec()

// initialization (taken from slides)
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <cstring>
#include <fcntl.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <cerrno>
#include <sys/wait.h>
#include "myShm.h"
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    // variable declaration
    int numProcess = stoi(argv[1]); // integer holding user-input number of processes
    char *shm_name = argv[2]; // pointer character holding user-input name of shared memory
    int shm_fd; // integer holding file descriptor of shared memory
    void *shm_base; // pointer holding base address of shared memory
    struct CLASS *mySharedMem; // pointer to structure in header file

    // display slave initialization
    cout << "Slave begins execution" << endl; // Give user visual indection execution is successfull 
    cout << "I am child number " << numProcess << ", received shared memory name " << shm_name << endl;  

    // shm_open() - creates and opens new POSIX shared memory segment
    shm_fd = shm_open(shm_name, O_CREAT | O_RDWR, 0666); 
    // ftruncate() - precisely adjusts the size of the shared memory segment
    ftruncate(shm_fd, 4096);
    // mmap() - creates new mapping in virtual space address of calling process
    shm_base = mmap(0, 4096, PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0); 
    // assign shared memory address to pointer to structure variable
    mySharedMem = (struct CLASS *)shm_base; // Assigning starting address to variable mySharedMem 
    // point to variable in structure
    int index = mySharedMem -> index;

    // update child process number and index 
    mySharedMem -> response[index] = numProcess;
    mySharedMem -> index = index + 1; 

    // display slave update and termination 
    cout << "I have written my child number to slot " << index << " and updated index to " << index + 1 << endl; 
    cout << "Child " << numProcess << " closed to shared memory and terminates " << endl;

    return 0; 
};
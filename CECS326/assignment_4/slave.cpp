// Marwin Gonzales 027340883
// CECS 326 assignment 4 slave.cpp
// terminal input: NONE
// description: outputs its child number as well as shared memory segment name passed from exec(), asks for value to be shared in memory

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
#include <semaphore.h>
using namespace std;

int main(int argc, char *argv[])
{
    // variable declaration
    int numProcess = stoi(argv[1]); // integer holding user-input number of processes
    char *shm_name = argv[2]; // pointer character holding user-input name of shared memory
    char *sem_name = argv[3]; // pointer character holding user-input name of semaphore
    int shm_fd; // integer holding file descriptor of shared memory
    void *shm_base; // pointer holding base address of shared memory
    struct CLASS *mySharedMem; // pointer to structure in header file
    int lucky_number;

    // display slave initialization
    cout << "Slave begins execution" << endl; // Give user visual indection execution is successfull
    cout << "I am child number " << numProcess << ", received shared memory name " << shm_name << " and " << sem_name << endl;

    // shm_open() - creates and opens new POSIX shared memory segment
    shm_fd = shm_open(shm_name, O_CREAT | O_RDWR, 0666);
    // ftruncate() - precisely adjusts the size of the shared memory segment
    ftruncate(shm_fd, 4096);
    // mmap() - creates new mapping in virtual space address of calling process
    shm_base = mmap(0, 4096, PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);
    // assign shared memory address to pointer to structure variable
    mySharedMem = (struct CLASS *)shm_base; // Assigning starting address to variable mySharedMem
    // sem_open() - creates a new POSIX semaphore or opens an existing semaphore
    sem_t *mutex_sem = sem_open(sem_name, O_RDWR);
    // sem_wait() - decrements (locks) the semaphore
    sem_wait(mutex_sem);
    // point to variable in structure
    int index = mySharedMem -> index;

    // prompt user for integer input
    cout << "Child numnber " << numProcess << ": What is my lucky number?" << endl;
    cin >> lucky_number;

    // update child process number, input, and index
    mySharedMem -> response[index] = numProcess;
    mySharedMem -> response[index+1] = lucky_number;
    mySharedMem -> index = index + 2;

    // display slave update and termination
    cout << "I have written my child number to slot " << index << " and my lucky number to slot " << index + 1 << ", and updated index to " << index + 2 << endl;
    cout << "Child " << numProcess << " closed access to shared memory and terminates " << endl;

    // sem_post() - increments (unlocks) the semaphore
    sem_post(mutex_sem);

    return 0;
};
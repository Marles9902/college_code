// Marwin Gonzales 027340883
// CECS 326 assignment 5 master.cpp
// terminal input: ./master x my_shm_name sem_name
// description: takes integer for amount of child processes, takes string for name of shared memory and a semaphore, 
//              creates unnamed and named semaphore, forks and executes child processes

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

    // display master initialization
    cout << "Master begins execution" << endl;
    cout << "Master created a shared memory segment named " << shm_name << endl;
    cout << "Master initializes index in the shared structure to zero" << endl;
    cout << "Master created an unnamed semaphore for controlling access to the shared index variable" << endl;
    cout << "Master created a named semaphore " << sem_name << " for I/O control" << endl;

    // initialize: shared memory and semaphore
    // shm_open() - creates and opens new POSIX shared memory segment
    shm_fd = shm_open(shm_name, O_CREAT | O_RDWR, 0666);
    // ftruncate() - precisely adjusts the size of the shared memory segment
    ftruncate(shm_fd, 4096);
    // mmap() - creates new mapping in virtual space address of calling process
    shm_base = mmap(0, 4096, PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);
    // assign shared memory address to pointer to structure variable
    mySharedMem = (struct CLASS *)shm_base;

    // *** NEW *** 
    // sem_init() - initializes the unnamed semaphore at the address pointed to by sem
    sem_init(&(mySharedMem->semUnnamed), 1, 1);

    // sem_open() - creates a new POSIX semaphore or opens an existing semaphore
    sem_t *semNamed = sem_open(argv[3], O_CREAT | O_RDWR, 0666, 1);
    // point to variable in structure and assign starting value
    mySharedMem -> index = 0;

    // display child process execution
    cout << "Master created " << numProcess << " child processes to execute slave" << endl;
    cout << "Master waits for all child processes to terminate" << endl;

    // loop for the amount of processes inputted by user
    for(int i = 1; i <= numProcess; i++)
    {
        // process ID variable
        pid_t pid;
        // fork() - starts new process which is a copy of the one that calls it
        pid = fork();

        // if process ID is equal to 0
        if(pid == 0)
        {
            // exec() - replaces current process executable with new one
            execlp("./slave", "slave", to_string(i).c_str(), shm_name, sem_name, NULL);
        }
    }

    // loop for the amount of processes inputted by user
    for(int i = 0; i < numProcess; i++)
    {
        // wait() - blocks calling process until at least one child process exits
        wait(NULL);
    }

    // display child process termination
    cout << "Master received termination signals from all " << numProcess << " child processes" << endl;
    cout << "Updated content of shared memory segment after access by child processes:" << endl;

    // loop for the amount of indexes of child processes from structure
    for(int i = 0; i < mySharedMem->index; i++)
    {
        // display content of shared memory (integer value from myShm struct)
        cout << mySharedMem->response[i] << endl;  // Displays integer elements in shared memory segment
    }

    // terminate: shared memory and semaphore
    // sem_close() - closes the named semaphore
    sem_close(semNamed);
    // sem_unlink() - removes the named semaphore
    sem_unlink(sem_name);

    // *** NEW ***
    // sem_destroy() - destroys the unnamed semaphore at the address pointed to by sem
    sem_destroy(&(mySharedMem->semUnnamed));

    // munmap() - deletes the mappings for the specified address range
    munmap(mySharedMem, 4096);
    // shm_unlink() - removes a shared memory object name
    shm_unlink(shm_name);

    // display termination
    cout << "Master remmoved both the unnamed and named semaphores" << endl;
    cout << "Master closed access to shared memory, removed shared memory segment, and is exiting" << endl;

    // exit() - terminates calling process
    exit(0);
    return 0;
};
// Marwin Gonzales 027340883
// CECS 326 assignment 3 master.cpp
// terminal input: ./master x my_shm_name
// description: takes integer for amount of child processes, takes string for name of shared memory, forks and executes child processes

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

    // display master initialization
    cout << "Master begins execution" << endl;
    cout << "Master created a shared memory segment named " << shm_name << endl; 

    // shm_open() - creates and opens new POSIX shared memory segment
    shm_fd = shm_open(shm_name, O_CREAT | O_RDWR, 0666); 
    // ftruncate() - precisely adjusts the size of the shared memory segment
    ftruncate(shm_fd, 4096);
    // mmap() - creates new mapping in virtual space address of calling process
    shm_base = mmap(0, 4096, PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0); 
    // assign shared memory address to pointer to structure variable
    mySharedMem = (struct CLASS *)shm_base; 
    // point to variable in structure and assign starting value 
    mySharedMem -> index = 1;

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
            execlp("./slave", "slave", to_string(i).c_str(), shm_name, NULL); 
        }
    }

    // loop for the amount of processes inputted by user 
    for(int i = 1; i < numProcess; i++) 
    {
        // wait() - blocks calling process until at least one child process exits
        wait(NULL); 
    }

    // display child process termination
    cout << "Master received termination signals from all " << numProcess << " child processes" << endl; 
    cout << "Updated content of shared memory segment after access by child processes:" << endl; 

    // loop for the amount of indexes of child processes from structure
    for(int i = 1; i < mySharedMem->index; i++) 
    {
        // display content of shared memory (integer value from myShm struct)
        cout << mySharedMem->response[i] << endl;  // Displays integer elements in shared memory segment 
    }

    // display termination
    cout << "Master removed shared memory segment, and is exiting " << endl; // Last display message before progam is terminated 
    
    // exit() - terminates calling process
    exit(0);
    return 0; 
};
// Marwin Gonzales 027340883
// CECS 326 assignment 1 parent.cpp
// terminal input: ./parent name_1 name_2 ... name_k
// description: takes input of multiple names, calls child process to make sentences, outputs own sentences

#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
    //output amount of children using argument counter excluding program name
    cout << "I have " << argc -1 << " children." << endl;

    // loop process for amount of names inputted
    for(int i = 1; i < argc; i++)
    {
        // integer type representing process ID
        pid_t pid;
        // fork(): created a new process (for each name)
        pid = fork();

        // if there is somehow a negative amount of processes
        if(pid < 0)
        {
            // display error
            cout << "Fork failed." << endl;
            return 1;
        }
        // if there is no process running
        else if(pid == 0)
        {
            // execlp(): replace the process' address space with a new program
            execlp("./child", "child", to_string(i).c_str(), argv[i], NULL);
        }
        // if there is at least one process running
        else
        {
            // wait(): suspend calling another process until child process ends
            wait(NULL);
        }
    }

    // once all the child processes end, display concluding message
    cout << "All child processes terminated. Parent exits." << endl;
    // exit(): terminates program
    exit(0);

    return 0;
};

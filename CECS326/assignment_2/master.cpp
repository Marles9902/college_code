// Marwin Gonzales 027340883
// CECS 326 assignment 2 master.cpp
// terminal input: ./master x (x = number of senders/receivers)
// description: take integer input and output sequence of sentences

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
using namespace std;

int main(int argc, char* argv[])
{
    // variable declaration for master pid, sender/receiver pid, queue id, and number of processes
    int pid = getpid();
    pid_t cpid;
    int qid = msgget(IPC_PRIVATE, IPC_EXCL|IPC_CREAT|0600);
    int numProcess = stoi(argv[1]);

    // output for setup 
    cout << "Master, PID " << pid << ", begins execution" << endl;
    cout << "Master acquired a message queue, id " << qid << endl;
    cout << "Master created " << numProcess << " child processes to serve as a sender" << endl;
    cout << "Master created " << numProcess << " child processes to serve as a receiver" << endl;
    cout << "Master waits for all child processes to terminate" << endl;

    // loop for the amount of processes inputted
    for(int i = 0; i < numProcess; i++)
    {
        // fork, execute, terminate sender program
        cpid = fork();
        if(cpid == 0)
        {  
            execlp("./sender", "sender", to_string(qid).c_str(), NULL);
            exit(0);
        }
    }
    
    // loop for the amount of processes inputted
    for(int i = 0; i < numProcess; i++)
    {
        // fork, execute, terminate receiver program
        cpid = fork();
        if(cpid == 0)
        {
            execlp("./receiver", "receiver", to_string(qid).c_str(), NULL);
            exit(0);
        }
    }
    
    // wait for all processes to terminate, output end message, terminate master program
    while(wait(NULL) != -1);
    msgctl(qid, IPC_RMID, NULL);
    cout << "Master received termination signals from all child processes, removed message queue, and terminates" << endl;
    exit(0);

    return 0;
}

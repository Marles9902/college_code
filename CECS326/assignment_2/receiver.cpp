// Marwin Gonzales 027340883
// CECS 326 assignment 2 receiver.cpp
// terminal input: none
// description: output message, receive and output message, send receipt

#include <sys/types.h>
#include <sys/msg.h>
#include <string.h>
#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
using namespace std;

struct msg_buf
{
    long mtype; 
    char message[70];
};

int main(int argc, char* argv[])
{
    // variable declaration for struct usage, sender pid, queue id, size of message
    msg_buf msg;
    int pid = getpid();
    int qid = stoi(argv[1]);
    int size = sizeof(msg)-sizeof(long);

    // output for setup 
    cout << "Receiver, PID " << pid << ", begins execution" << endl;
    cout << "Receiver with PID " << pid << " received message queue id " << qid << " through commandline argument" << endl;
    
    // receive the message from sender program and output it 
    msgrcv(qid, (struct msg_buf *)&msg, size, 113, 0);
    cout << "Receiver with PID " << pid << " retrieved the following message from message queue" << endl;
    cout << msg.message << endl;

    // mtype of the receipt message 
    msg.mtype = 114;
    sprintf(msg.message, "Receiver with PID %d acknowledges receipt of message", pid);

    // send the receipt message, output terminate 
    msgsnd(qid, (struct msg_buf *)&msg, size, 0);
    cout << "Receiver with PID " << pid << " sent the following acknowledgement message into message queue" << endl;
    cout << msg.message << endl;
    cout << "Receiver with PID " << pid << " terminates" << endl;

    return 0;
}
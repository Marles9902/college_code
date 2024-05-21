// Marwin Gonzales 027340883
// CECS 326 assignment 2 sender.cpp
// terminal input: none
// description: output message, take input, send input to receiver, receive receipt 

#include <sys/types.h>
#include <sys/msg.h>
#include <string.h>
#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
using namespace std;

// struct taken from slides (edited for personal use)
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
    cout << "Sender, PID, " << pid << ", begins execution" << endl;
    cout << "Sender with PID " << pid << ", received message queue id " << qid << " through commandline" << endl;
    cout << "Sender with PID " << pid << ": Please input your message" << endl;
    
    // input message from user 
    cin.getline(msg.message, 50);
    // mtype for the actual message 
    msg.mtype = 113;
    // send message through structure
    msgsnd(qid, (struct msg_buf *)&msg, size, 0);
    cout << "Sender with PID " << pid << " sent the following message into message queue: " << msg.message << endl;

    // receive receipt and output it, output terminate
    msgrcv(qid, (struct msg_buf*)&msg, size, 114, 0);
    cout << "Sender with PID " << pid << " receives the following acknowledgement message " << endl;
    cout << msg.message << endl;
    cout << "Sender with PID " << pid << " terminates" << endl;
    return 0;
}
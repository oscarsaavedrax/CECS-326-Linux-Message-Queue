/***********************************************************************
 * Programmer	: Oscar Saavedra
 * Class	    : CECS 326-01
 * Due Date	    : October 4, 2022
 * Description	: This program demonstrates how processes have 
 *      interprocess communication through the use of a message queue
 *      in Linux. This master.cc program acquires a message queue from
 *      the kernal and creates two child processes, sender and receiver.
 *      This program outputs its process ID, the message queue ID, 
 *      the process IDs of the sender and receiver processes it has 
 *      created, then waits for both child processes to terminate. The 
 *      program then removes the message queue and exits.
 ***********************************************************************/

#include <iostream>
#include <string>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

using namespace std;

int main()
{
    cout << "Master, PID " << getpid() << ", begins execution" << endl;

    // Create variables
    int msg_queue_id_int;
    pid_t sender_pid, receiver_pid;
    
    // Acquire a message queue
    msg_queue_id_int = msgget(IPC_PRIVATE, IPC_EXCL | IPC_CREAT | 0600);
    // Convert int to char*
    string msg_queue_str = to_string(msg_queue_id_int);
    char* msg_queue_id = const_cast<char*>(msg_queue_str.c_str());

    // Create char array to send each process information
    char* process_info[] = {msg_queue_id, NULL};

    cout << "Master acquired a message queue, id " << msg_queue_id_int << endl;

    // Create sender process
    sender_pid = fork();
    if(sender_pid < 0)
    {
        cout << "Fork failed" << endl;
        return 1;
    }
    else if(sender_pid == 0)
    {
        cout << "Master created a child process with PID " << getpid() << " to execute sender" << endl;
        
        // Execute sender process
        execv("./sender", process_info);
        //exit(0);
    }
    wait(0);

    // Create receiver process
    receiver_pid = fork();
    if(receiver_pid < 0)
    {
        cout << "Fork failed" << endl;
        return 1;
    }
    else if(receiver_pid == 0)
    {
        cout << "Master created a child process with PID " << getpid() << " to execute receiver" << endl;
        
        // Execute sender process
        execv("./receiver", process_info);
        exit(0);
    }
    wait(0);

    // Remove the message queue
    msgctl(msg_queue_id_int, IPC_RMID, NULL);

    // Waiting for both children processes to terminate
    while(wait(NULL) != -1);

    cout << "Master waits for both child processes to terminate" << endl;
    cout << "Master received termination signals from both child processes ";
    cout << "removed message queue, and terminates" << endl;

    return 0;
}
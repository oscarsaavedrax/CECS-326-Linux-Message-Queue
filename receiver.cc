/***********************************************************************
 * Programmer	: Oscar Saavedra
 * Class	    : CECS 326-01
 * Due Date	    : October 4, 2022
 * Description	: This program demonstrates how processes have 
 *      interprocess communication through the use of a message queue
 *      in Linux. This receiver.cc program outputs a message to identify 
 *      itself, and show the message queue id it obtained from the exec()
 *      system call that invokes its execution. The program then 
 *      retrieves a message from the message queue, sends an 
 *      acknowledgement to the sender program, and outputs the message 
 *      on the screen.
 ***********************************************************************/

#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

using namespace std;

const int MAX_MSG_LENGTH = 100;

// Declare global message buffer
struct message_buffer 
{
    long message_type;
    char message[MAX_MSG_LENGTH];
};

int main(int argc, char** argv)
{
    message_buffer message;
    int message_size = sizeof(message) - sizeof(long);

    cout << "Receiver, PID " << getpid() << ", begins execution" << endl;
    cout << "Receiver received message queue id " << argv[0] << " through commandline parameter" << endl;

    msgrcv(atoi(argv[0]), (struct message_buffer *)&message, message_size, 114, 0);
    cout << "Receiver acknowledged receipt of message" << endl;
    cout << "Receiver: Retrieved the following message from message queue" << endl;
    cout << message.message << endl;

    cout << "Receiver terminates" << endl;

    return 0;
}
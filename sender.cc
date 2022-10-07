/***********************************************************************
 * Programmer	: Oscar Saavedra
 * Class	    : CECS 326-01
 * Due Date	    : October 4, 2022
 * Description	: This program demonstrates how processes have 
 *      interprocess communication through the use of a message queue
 *      in Linux. This sender.cc program outputs process ID and the 
 *      message queue ID it obtained from the exec() system call that 
 *      invokes its execution. The program prompts a user for a line of 
 *      input, sends the input line to the receiver program via the 
 *      message queue created by the master program. This program
 *      waits for an acknowledgement from receiver program of the receipt 
 *      of message, then terminates.
 ***********************************************************************/

#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

using namespace std;

// Max length of the message
const int MAX_MSG_LENGTH = 100;

// Declare global message buffer
struct message_buffer 
{
    long message_type;
    char message[MAX_MSG_LENGTH];
};

int main(int argc, char** argv)
{
    // Create variables
    message_buffer message;
    int message_size = sizeof(message) - sizeof(long);
    
    // Output Sender PID and message queue ID
    cout << "Sender, PID " << getpid() << ", begins execution" << endl;
    cout << "Sender received message queue id " << argv[0] << " through commandline parameter" << endl;
    
    // Get message from the user
    cout << "Sender: Please input your message" << endl;
    cin.getline (message.message, MAX_MSG_LENGTH);

    // Send message to message queue
    message.message_type = 114;
    msgsnd(atoi(argv[0]), (struct message_buffer *)&message, message_size, 0);
    cout << "Sender sent message to message queue" << endl;

    // Terminate sender process
    cout << "Sender receives acknowledgement of receipt of message" << endl;
    cout << "Sender terminates" << endl;
    return 0;
}
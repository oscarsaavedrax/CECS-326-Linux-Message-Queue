/***********************************************************************
 * Programmer	: Oscar Saavedra
 * Class	    : CECS 326-01
 * Due Date	    : October 4, 2022
 * Description	: This program demonstrates how processes have 
 *      interprocess communication through the use of a message queue
 *      in Linux. This sender.cc program outputs a message to identify 
 *      itself, and show the message queue id it obtained from the exec() 
 *      system call that invokes its execution. The program prompts user 
 *      for a line of input, sends the input line to the receiver program
 *      via the message queue created by the master program. This program
 *      waits for an acknowledgement from receiver program of the receipt 
 *      of message, then terminates.
 ***********************************************************************/


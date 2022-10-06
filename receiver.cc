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


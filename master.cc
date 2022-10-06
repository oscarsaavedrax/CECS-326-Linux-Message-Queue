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


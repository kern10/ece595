#include "usertraps.h"

void main (int x)
{
	int fork_pid;
	Printf("Hello World!\n");
	Printf("LAB01: Implementing User Trap\n");
	/*********************************************************
	 * Getpid() is a system call to the OS to print the 
	 * current process ID. I forked a new process to 
	 * demonstrate the PID changing as the process changes.
	 ********************************************************/
	Getpid(); /* Show current process ID */
	fork_pid = Fork(); /* Fork another process */
	
	if(fork_pid < 0){/* ERROR OCCURED */ exit(-1);}
	else if(fork_pid == 0){/* CHILD PROCESS */ Getpid();}
	else{/* PARENT PROCESS */ 
		Getpid();	
		}
	/******************************************************
	 * Note: The parent pid should be equivalent to the 
	 * 		 first pid called prior to forking.
	 ******************************************************/
	
	while(1); // Use CTRL-C to exit the simulator
}

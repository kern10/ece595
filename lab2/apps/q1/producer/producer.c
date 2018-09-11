#include "lab2-api.h"
#include "usertraps.h"
#include "misc.h"

#include "q1.h"

void main (int argc, char *argv[])
{
  	shared_mem * smem;  // Circular buffer handle     
  	uint32 h_mem;      	// Handle to the shared memory page
  	lock_t l_proc; 		// Lock for exclusive code
	sem_t sem_proc;		// Semaphore to signal the original process that we're done
	int lock_status;	// Lock function return values
	int i=0;				// Incrementer
	char hello[12] = "Hello World";	// Value placed in buffer	
	int next;			// Circular buffer accessory
	int chars_left=0;	// Incrementer for placing chars of "Hello World"

  	if (argc != 4) { 
    	Printf("Usage: "); Printf(argv[0]); Printf(" <handle_to_shared_memory_page> <handle_to_page_mapped_lock> <handle_to_page_mapped_semaphore>\n"); Exit();
  	} 

  	// Convert the command-line strings into integers for use as handles
  	h_mem = dstrtol(argv[1], NULL, 10);
  	l_proc = dstrtol(argv[2], NULL, 10);
	sem_proc = dstrtol(argv[3], NULL, 10);

 	// Map shared memory page into this process's memory space
  	if ((smem = (shared_mem *)shmat(h_mem)) == NULL) {
    	Printf("Could not map the virtual address to the memory in "); Printf(argv[0]); Printf(", exiting...\n"); Exit();
 	}


	// Access shared memory and place characters one by one
	while(i < 11)
	{
		// Get the lock
		if(lock_acquire(l_proc))
		{
			if(smem->head != ((smem->tail+1)%(smem->maxbuf)))
			{
				smem->buffer[smem->tail] = hello[i];
				Printf("Producer %d inserted: %c\n",Getpid(), hello[i]);
				smem->tail = (smem->tail+1)%smem->maxbuf;
				i++;
			}
			
		}
	}

  	// Signal the semaphore to tell the original process that we're done
  	Printf("producer: PID %d is complete. Killing it.\n", Getpid());  
  	if(sem_signal(sem_proc) != SYNC_SUCCESS) 
	{
	    	Printf("Bad semaphore s_procs_completed (%d) in ", sem_proc); 
		Printf(argv[0]); 
		Printf(", exiting...\n");
	    	Exit();
  	}
}

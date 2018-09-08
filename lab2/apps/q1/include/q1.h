#ifndef __USERPROG__
#define __USERPROG__

typedef struct shared_mem {
	int numprocs;
	char * buffer;
	int head;
	int tail;
	int maxbuf;
} shared_mem;

#define PRODUCER_RUN "producer.dlx.obj"


#endif

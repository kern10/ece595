#ifndef __USERPROG__
#define __USERPROG__

typedef struct shared_mem {
	int numprocs;
	char * const buffer;
	int head;
	int tail;
	const int BUFFER_SIZE;
} shared_mem;

#define PRODUCER_RUN "producer.dlx.obj"
#define CONSUMER_RUN "consumer.dlx.obj"

#endif

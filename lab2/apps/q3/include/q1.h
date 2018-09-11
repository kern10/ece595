#ifndef __USERPROG__
#define __USERPROG__

typedef struct circular_buffer {
	int numprocs;
	char * buffer;
	int head;
	int tail;
	int maxbuf;
} circular_buffer;

#define PRODUCER_RUN "producer.dlx.obj"
#define CONSUMER_RUN "consumer.dlx.obj"

#endif

# Programming Assignment 2 (NOTES)
## Shared Memory
> Since DLXOS does not have thread support, a new mechanism has been introduced to enable two processes to communicate. Two or more processes share part of their address space through two functions.  

### 1. __request a handle to a chunk of shared memory:__  

> - user program wants to use shared memory -> calls a trap to signal OS   
> - trap returns a handle identifying a physical shared memory segment   
> - if two processes wish to share the same memory segment, they must have the same handle  
> - handles are shared between processes through command-line args when one process forks another  
> Have one single parent process request a handle to a shared memory segment. Then pass that handle to the child during forking.  

### 2. __request the address of a chunk of shared memory given its handle:__  
> Use API to handle mapping of addresses, ie. dynamic address translation  
```C
// Using API
buffer * b = (buffer *)get_shared_memory_address_from_handle(handle);

// Ordinary access method of shared memory
b->item1 = 5;
```
---  

## Circular Buffers
> Classic producer-consumer problem is generally implemented through the use of a shared circular buffer  
#### circular buffers typically are used to implement producer-consumer problem  
> head --> index to first availible slot in buffer space array  
> tail --> index to first full slot in buffer space array  
> buffer --> an array to hold data  

__before consumer process removes an item from buffer...__  
```C
// Check for empty condition  
if (head == tail) 
{  
	// buffer empty
}
else  
{  
	// buffer not empty  
}
```

__before producer process can put an item into the buffer...__  
```C
// Check for full condition  
if ((head + 1) % BUFFER_SIZE == tail)
{
	// buffer full
}
else  
{  
	// buffer not full  
}  
```

---

## Implementing circular buffer  

__data structure definition__  
```C
// Define data structure
typedef struct {
	uint8_t * const buffer;
	int head;
	int tail;
	const int BUFFER_SIZE;
} prod_cons_c_buffer_t;
```

__producer function__  
```C
int producer(prod_cons_c_buffer_t * cbuf, uint8_t data)
{
	// Check for full condition
	if ((cbuf->head + 1) % (cbuf->BUFFER_SIZE) == (cbuf->tail))
	{
		// buffer full
		return -1;
	}
	int next = cbuf->(cbuf->head + 1);
	if (next >= cbuf->BUFFER_SIZE)
	{
		// Go back to start
		next = 0;
	}

	// Push into buffer
	cbuf->buffer[cbuf->head] = data;

	// Change the circular buffer's head
	cbuf->head = next;	

	return 0;
}
```

__consumer function__  
```C
int consumer(prod_cons_c_buffer_t * cbuf, uint8_t * data)
{
	if (cbuf->head == cbuf->tail)
	{
		// buffer empty
		return -1;
	}

	// Buffer is NOT empty
	int next = cbuf->tail + 1;
	// start at beginning
	if (next >= cbuf->BUFFER_SIZE)
	{
		next = 0;
	}

	// Read data
	*data = cbuf->buffer[cbuf->tail];
	
	cbuf->tail = next;
	
	return 0;
}
```


## END README.md

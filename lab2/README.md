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
> buffer space --> an array to hold data  

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


## END README.md

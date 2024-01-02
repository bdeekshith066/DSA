/*Dynamic memory allocation is a programming concept that allows you to allocate memory during the execution of a program. 
Unlike static memory allocation, where memory is allocated at compile-time, dynamic memory allocation allows you to allocate memory at runtime,
 based on the program's needs.*/ 

//Types of Dynamic Memory Allocation:
// 1 Malloc (Memory Allocation):

    /*Function: void* malloc(size_t size);
    Allocates a specified number of bytes of memory.
    Returns a pointer to the beginning of the allocated memory.
    Memory content is uninitialized*/
#include<stdlib.h>

    int *arr;
arr = (int*)malloc(5 * sizeof(int));

// Use the allocated memory

free(arr);  // Don't forget to free the memory when done


/*2. Calloc (Contiguous Allocation):

Function: void* calloc(size_t num_elements, size_t element_size);
Allocates memory for an array of elements, each with a specified size.
Returns a pointer to the beginning of the allocated memory.
Memory content is initialized to zero.*/

int *arr;
arr = (int*)calloc(5, sizeof(int));

// Use the allocated memory

free(arr);  // Don't forget to free the memory when done


/*3 Realloc (Re-allocation):

Function: void* realloc(void* ptr, size_t new_size);
Changes the size of the memory block pointed to by ptr to new_size bytes.
Returns a pointer to the beginning of the reallocated memory.
Preserves the existing content, and uninitialized bytes may be added.*/


int *arr;
arr = (int*)malloc(5 * sizeof(int));

// Use the allocated memory

arr = (int*)realloc(arr, 10 * sizeof(int));

// Use the reallocated memory

free(arr);  // Don't forget to free the memory when done







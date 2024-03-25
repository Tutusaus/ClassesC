// C program to understand difference between
// pointer to an integer and pointer to an
// array of integers.
#include <stdio.h>

int main()
{
	// Pointer to an integer
	/*
    int *p;
	
	// Pointer to an array of 5 integers
	int (*ptr)[5];
	int arr[5];
	
	// Points to 0th element of the arr.
	p = arr;
	
	// Points to the whole array arr.
	ptr = &arr;
	
	printf("p = %p, ptr = %p\n", p, ptr);
	
	p++;
	ptr++;
	
	printf("p = %p, ptr = %p\n", p, ptr);
    */
    //--------------------------------------------

    int arr[] = {3,5,6,7,9};
    int *p = arr;
    int (*ptr)[5] = &arr;
     
    printf("p = %p, ptr = %p\n", p, ptr);
    printf("*p = %d, *ptr = %p, **ptr = %d\n", *p, *ptr, **ptr);
     
    printf("sizeof(p) = %lu, sizeof(*p) = %lu\n",sizeof(p), sizeof(*p));
    printf("sizeof(ptr) = %lu, sizeof(*ptr) = %lu\n",sizeof(ptr), sizeof(*ptr));

    //--------------------------------------------
	
	return 0;
}

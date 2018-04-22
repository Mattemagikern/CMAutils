#ifndef XMALLOC_H
#define XMALLOC_H

#include <stdlib.h>
#include <stdio.h>
void* xmalloc(size_t size){
	void* p = malloc(size);
	if (p==NULL){
		fprintf(stderr, "out of memory");
		exit(1);
	}	
	return p;
}

#endif

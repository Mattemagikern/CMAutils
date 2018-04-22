#ifndef SINGLYLINKEDLIST_H
#define SINGLYLINKEDLIST_H

#include <stddef.h>
typedef struct singlylinkedlist_node singlylinkedlist_node;
typedef struct singlylinkedlist singlylinkedlist; 

/*
 * A node-object representing the container
 */
struct singlylinkedlist_node {
	singlylinkedlist_node *next;
	void *value;
};


/*
 * An object representing our singlylinkedlist
 */
struct singlylinkedlist {
	singlylinkedlist_node *last;
	size_t size;
};

/*
 * The constructor of singlylinkedlist
 * Returns a pointer to a list
 */
singlylinkedlist* new_sll();

/*
 * Inserts a void* into the front of this list
 */
void sll_insert_front(singlylinkedlist *sll, void *value);

/*
 * Inserts a void* into the back of this list
 */
void sll_insert_back(singlylinkedlist *sll, void *value);

/*
 * Peeks the head of this list
 * @return a void* containing the value
 */
void* sll_get_front(singlylinkedlist *sll);

/*
 * Peeks the tail of this list
 * @return a void* containing the value
 */
void* sll_get_back(singlylinkedlist *sll);


/*
 * Pops the head of this list
 * @Return a void* containing the popped value
 */
void* sll_pop_front(singlylinkedlist *sll);





#endif

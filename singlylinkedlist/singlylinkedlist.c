/*
 * An implementation of singlylinkedlist.
 * This is a first implementation by Alexander Hansson as he studies C-programming
 *
 * @Author: Alexander.hansson4@gmail.com
 * @Version: 2018-04-22
 * @TODO:
 * 	Figure out if there is any way to use templates in C
 * 	It would be nice to be able to return by copy and store by copy
 *	Update version with xmalloc instead o malloc
 *	Use memcpy to store and return things
 *	Possibly a get() method?
 *	sort, reverse, contains?	
 */


#include <stdlib.h>
#include "singlylinkedlist.h"
#include <stdio.h>

/* The constructor of singlylinkedlist
 * Returns a pointer to a list
 */
singlylinkedlist* new_sll(){
	singlylinkedlist* list = malloc(sizeof(singlylinkedlist));
	if (list==NULL){
		fprintf(stderr, "Out of memory\n");
		exit(1);
	}
	list->last=NULL;
	list->size=0;
}


/*
 * Inserts a void* into the front of this list
 */
void sll_insert_front(singlylinkedlist* sll, void* value){
	if(sll->last==NULL){
		sll->last = malloc(sizeof(singlylinkedlist_node));
		if (sll->last == NULL){
			fprintf(stderr, "Out of memory\n");
			exit(1);
		}
		sll->last->next=sll->last;
		sll->last->value = value;
	}else{
		singlylinkedlist_node* temp = sll->last->next;
		sll->last->next = malloc(sizeof(singlylinkedlist_node));
		if (sll->last->next == NULL){
			fprintf(stderr, "Out of memory\n");
			exit(1);
		}
		sll->last->next->next = temp;
		sll->last->next->value=value;
	}
	sll->size+=1;
}


/*
 * Inserts a void* into the back of this list
 */
void sll_insert_back(singlylinkedlist* sll, void* value){
	if(sll->last==NULL){
		sll->last = malloc(sizeof(singlylinkedlist_node));
		if (sll->last == NULL){
			fprintf(stderr, "Out of memory");
			exit(1);
		}
		sll->last->next = sll->last;
		sll->last->value = value;
	}else{
		singlylinkedlist_node* temp = malloc(sizeof(singlylinkedlist_node));
		if (sll->last == NULL){
			fprintf(stderr, "Out of memory");
			exit(1);
		}
		temp->next = sll->last->next;
		sll->last->next = temp;
		temp->value = value;
		sll->last = temp;
	}
	sll->size+=1;
}


/*
 * Peeks the head of this list
 * @return a void* containing the value
 */
void *sll_get_front(singlylinkedlist *sll){
	if (sll->last != NULL){
		sll->size-=1;
		return sll->last->next->value;
	}
	return NULL;
}

/*
 * Peeks the tail of this list
 * @return a void* containing the value
 */
void *sll_get_back(singlylinkedlist *sll){
	if(sll->last != NULL) {
		sll->size-=1;
		return sll->last->value;
	}
	return NULL;
}


/*
 * Pops the head of this list
 * @Return a void* containing the popped value
 */
void *sll_pop_front(singlylinkedlist *sll){
	if(sll->last==NULL) return NULL;
	else if(sll->last == sll->last->next){
		void* value = sll->last->value;
		free(sll->last);
		sll->last=NULL;
		sll->size=0;
		return value;
	}else{
		singlylinkedlist_node *temp = sll->last->next;
		sll->last->next = sll->last->next->next;
		void* value = temp->value;
		free(temp);
		sll->size-=1;
		return value;
	}
}




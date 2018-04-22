#include "singlylinkedlist.h"
#include <stdio.h>
int main(){
	int a =5, b=6, c =10;
	singlylinkedlist* sll = new_sll();

	sll_insert_front(sll,&a);
	sll_insert_front(sll,&b);
	sll_insert_back(sll,&c);
	printf("sll.getfirst: %d\n",*(int*)sll_get_front(sll));
	printf("sll.getback: %d\n",*(int*)sll_get_back(sll));
	
	//looping
	while(sll_get_front(sll) != NULL) 
		printf("popping sll: %d\n",*(int*)sll_pop_front(sll));
	return 0;


}

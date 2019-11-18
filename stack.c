#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

//TODO - upravit pro pripad semestralky -> transmitteru 


stack *create_stack(uint stack_size, uint item_size){
	stack *temp;
	if ( !stack_size || !item_size) return NULL;     
	
	temp = (stack *) malloc(sizeof(stack));
	if(!temp) return NULL;
	
	temp->data = (char *) malloc(item_size * stack_size);
	if (!temp->data){              
		free(temp);                
		return NULL;
	}
	temp->stack_size = stack_size;
	temp->item_size = item_size;
	temp->sp = -1; 
	
}



int push_stack(stack *s, void *item) {
	int i;
	if (!s || !item || s->sp >=(int) s->stack_size - 1 ) return RET_ERR;       
//	if (s->sp >= s->size - 1) return RET_ERR;                           
	s->sp++;                                                           
	
	for (i = 0; i < s->item_size; i++)
		((char *) s->data)[s->sp * s->item_size + i] = ((char *) item)[i];  

	return RET_OK;
}




int pop_stack(stack *s, void *item) {
	int i;
	if (!s || !item || s->sp < 0 ) return RET_ERR;                                                          
	
	for (i = 0; i < s->item_size; i++)
		((char *) item)[i] = s->data[s->sp * s->item_size + i] ; 

		s->sp--;                                  

	return RET_OK;
}




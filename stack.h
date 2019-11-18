#ifndef _STACK_H
#define _STACK_H


#define RET_OK 1
#define RET_ERR 0

typedef unsigned int uint;

typedef struct {
	char *data;   //osmibitovy datovy typ = char
	uint item_size;
	uint stack_size;
	int sp;  // ukazatel od spod nelze uit protoze by mel hodnotu minus jedna kdyz je to praydne -> proto int 
} stack;


stack *create_stack(uint stack_size, uint item_size);
int push_stack(stack *s, void *item);
int pop_stack(stack *s, void *item);
int free_stack(stack **s);

#endif

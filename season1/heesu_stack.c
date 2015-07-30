#include <stdio.h> // printf
#include <stdlib.h> // malloc

#define INITIAL_SIZE 1
#define MULTIPLE_SPACE 2

typedef int element;
typedef struct _stack {
	int top;
	int capacity;
	element* list;
} Stack;
typedef enum {false, true} bool;

Stack* createStack();
// push an item and return stack length.
int push(Stack* stack, element item);
// pop an item and return it.
element pop(Stack* stack);
bool isFull(Stack* stack);
bool isEmpty(Stack* stack);
void stackFull(Stack* stack);
void stackEmpty(Stack* stack);

Stack* createStack() {
	Stack* stack = (Stack*)malloc(sizeof(Stack));
	stack->capacity = INITIAL_SIZE;
	stack->list = (element*)malloc(stack->capacity * sizeof(element));
	stack->top = -1;
	return stack;
}

bool isEmpty(Stack* stack) {
	return (stack->top <= -1);
}

void stackEmpty(Stack* stack) {
	fputs("Nothing to pop, it's EMPTY!\n", stderr);
	exit(-1);
}

element pop(Stack* stack) {
	if(isEmpty(stack)) stackEmpty(stack);
	return stack->list[stack->top--];	
}

bool isFull(Stack* stack) {
	return (stack->top >= stack->capacity -1);
}

void stackFull(Stack* stack) {
//	printf("10 %d\n", stack->capacity);
//	stack->capacity *= MULTIPLE_SPACE;
//	printf("20 %d\n", stack->capacity);
//	element* tmp = (element*)realloc(stack->list, stack->capacity * sizeof(element));
//	printf("30 %p %p\n", tmp, stack->list);
//	free(stack->list);
//	printf("40 %p %p\n", tmp, stack->list);
//	stack->list = tmp;
//	printf("50 %p\n", stack->list);

	stack->capacity *= MULTIPLE_SPACE;
	element* tmp = (element*)realloc(stack->list, stack->capacity * sizeof(element));
	if(!tmp) {
		free(tmp);
		fputs("No usable RAM more", stderr);
		exit(-1);
	}
}

int push(Stack* stack, element item) {
	if(isFull(stack)) stackFull(stack);
	stack->list[++stack->top] = item;
	return stack->top +1;
}

void printStack(Stack* stack) {
	for(int i=0; i<=stack->top; i++)
		printf("%d ",stack->list[i]);
	printf("\n");
}

int main() {
	Stack* stack = createStack();
	printf("[%d]", push(stack, 24));
	printStack(stack);
	printf("[%d]", push(stack, 92));
	printStack(stack);
	printf("[%d]", push(stack, 7));
	printStack(stack);
	printf("[%d]", pop(stack));
	printStack(stack);
	printf("[%d]", pop(stack));
	printStack(stack);
	printf("[%d]", pop(stack));
	printStack(stack);
	printf("[%d]", push(stack, 19));
	printStack(stack);
	printf("[%d]", pop(stack));
	printStack(stack);
	printf("[%d]", pop(stack));
	printStack(stack);
	printf("[%d]", push(stack, 37));
	printStack(stack);
	printf("[%d]", pop(stack));

	return 0;
}

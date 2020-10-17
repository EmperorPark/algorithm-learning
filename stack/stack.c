#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Stack {
	int buf[15];
	int top;
}Stack;

void Push(Stack *stack, int data);
int Pop(Stack *stack);
int IsFull(Stack *stack);
int IsEmpty(Stack *stack);
void InitStack(Stack * stack);


void InitStack(Stack *stack) {
	stack->top = -1;
}

int IsFull(Stack *stack) {
	return (stack->top + 1) == 15;
}

int IsEmpty(Stack *stack) {
	return stack->top == -1;
}

void Push(Stack *stack, int data) {
	if (IsFull(stack)) {
		printf("Stack Full Error\n");
		return;
	}
	stack->top++;
	stack->buf[stack->top] = data;
}

int Pop(Stack *stack) {
	int re = 0;
	if (IsEmpty(stack)) {
		printf("Stack Empty Error\n");
		return re;
	}
	re = stack->buf[stack->top];
	stack->top--;
	return re;
}

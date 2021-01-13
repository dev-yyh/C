#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct ArrayStack {
  int top;
  int capacity;
  int* array;
} Stack;

/* 주어진 capacity 크기로 stack을 생성하는 함수 */
Stack* createStack(int capacity) {
  Stack* stack = (Stack*)malloc(sizeof(Stack));
  if (!stack)
    return NULL;
  stack->capacity = capacity;
  stack->top = -1;
  stack->array = (int*)malloc(stack->capacity * sizeof(int));
  return stack;
}

/* 스택이 비어있는지 확인하는 함수. */
int isEmpty (Stack* stack) {
  return (stack->top == -1);
}

/* 스택이 가득찼는지 확인하는 함수. */
int isFull (Stack* stack) {
  return (stack->top == stack->capacity - 1);
}

/* top 위치에 있는 값을 가져오는 함수 */
int peek (Stack* stack) {
  if(isEmpty(stack))
    return INT_MIN;  
  return stack->array[stack->top];
}

/* 스택에 값을 추가하는 함수 */
void push(Stack *stack, int data) {
  if (isFull(stack))
    printf("Stack is full\n");
  else {
     /* top을 1증가시키고 값을 top에 저장함 */
    stack->array[++stack->top] = data;
    printf("%d pushed to stack\n", data);
  }
}

/* 스택에 값을 삭제하는 함수 */
int pop(Stack* stack) {
  if (isEmpty(stack)) {
    printf("Stack is empty\n");
    return INT_MIN;
  }
  else /* top의 값을 1 감소시킴 */
    return (stack->array[stack->top--]);
}

void main() 
{
  Stack* stack = createStack(3);
  
  push(stack, 1);
  push(stack, 2);
  push(stack, 3);
  push(stack, 4);
  
  printf("%d poped from stack\n", pop(stack));
}

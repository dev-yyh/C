#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct ListStack
{
  int data;
  struct ListStack *next;
} Stack;

int IsEmptyStack (Stack *Top)
{
  return (Top == NULL);
}

void push (Stack **Top, int data)
{
  Stack *newNode = NULL;
  
  newNode = (Stack*)malloc(sizeof(Stack));
  if(newNode == NULL)
  {
    printf("Stack is full\n");
    return;
  }
  /* 리스트 맨 앞에 새로운 노드를 추가합니다. */
  newNode->data = data;
  newNode->next = *Top;
  *Top = newNode;
  
  printf("%d pushed to stack\n", data);
}

int pop (Stack **Top)
{
  Stack *temp = NULL;
  int data = 0;
  if(IsEmptyStack(*Top))
  {
    printf("Stack is Empty\n");
    return INT_MIN;
  }
  else
  { /* Top 위치(리스트 맨 앞)에 있는 노드를 제거합니다 */
    temp = *Top;
    *Top  = temp->next;
    data = temp->data;
    free(temp);
  }
  return data;
}

void main(void)
{
  Stack *S =NULL;

  push(&S, 1);
  push(&S, 2);
  push(&S, 3);

  printf("%d poped from stack\n", pop(&S));
}

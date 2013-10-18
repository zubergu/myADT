#include "stack.h"

int get_value(void)
{
  int val;
  
  printf("Input value to be pushed on stack: ");
  while(scanf("%d", &val)!=1)
  {
    printf("Value has to be integer. Try again.\n");
    scanf("%*s");
  }
  while(getchar()!='\n')
    continue;
  return val;
}
    
void push(StackT * stack_ptr)
{
  Element * new_element;
  
  if((new_element=malloc(sizeof(Element)))==NULL)
  {
    printf("Couldn't create new element.\n");
    return;
  }
  new_element->value=get_value();
  new_element->prev=(*stack_ptr);
  (*stack_ptr)=new_element;
}

int pop(StackT * stack_ptr, int * empty_flag)
{
  Element * current;
  int value;
  
  current=(*stack_ptr);
  if(current==NULL)
  {
    printf("Stack is empty.\n");
    *empty_flag=1;
    return -1;
  }
  value=current->value;
  (*stack_ptr)=current->prev;
  free(current);
  *empty_flag=0;
  return value;
}

void top(StackT stack)
{
  if(stack==NULL)
    printf("Stack is currently empty.\n");
  else
    printf("Ther is %d on top of the stack.\n", stack->value);
}


void print_stack(StackT stack)
{
  printf("\t\t*** TOP ***\n\n");
  while(stack!=NULL)
  {
    printf("\t\t   %d\n", stack->value);
    stack=stack->prev;
  }
  printf("\n\t\t***BOTTOM***\n");
}

void remove_stack(StackT stack)
{
  Element * to_free;
  while(stack!=NULL)
  {
    to_free=stack;
    stack=stack->prev;
    free(to_free);
  }
  printf("Stack removed and memory freed.\n");
}

  
#include "stack.h"

int menu(void);

int main(void)
{
  StackT stack=NULL;
  int operation;
  int empty_flag;
  int popped;
  
  while((operation=menu())!=5)
  {
    switch (operation)
    {
      case 1: push(&stack); break;
      case 2: popped=pop(&stack,&empty_flag);
	if(empty_flag==0)
	{
	  printf("Popped value: %d\n", popped);
	}
        break;
      case 3: top(stack); break;
      case 4: print_stack(stack); break;
      default: printf("This shouldn't happen.\n");break;
    }
  }
  remove_stack(stack);
  return 0;
}
  
  
int menu(void)
{
  int choice=-1;
  
  do{
  printf("***** STACK INTERFACE *****\n\n");
  printf("1) Push on stack.\n");
  printf("2) Pop from the stack.\n");
  printf("3) Lookup top of the stack.\n");
  printf("4) Print stack.\n");
  printf("5) Quit.\n");
  printf("***************************\n");
  if(scanf("%d",&choice)!=1)
    scanf("%*s");
  } while(choice<1 || choice > 5);
  
  return choice;
}
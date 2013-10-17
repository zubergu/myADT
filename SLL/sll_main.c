#include "sll.h"

int menu(void); /* function to print menu and return user option */




int main(void)
{
  int choice=0;
  Head * list=NULL; /* list is pointer to Head structure */
  
  
  while((choice=menu())!=11)
  {
    switch(choice)
    {
      case 1: printf("Creating new list %s.\n", create_list(&list)==TRUE? "succeeded":"failed"); break;
      case 2: printf("Adding new node at beginning %s.\n", add_at_begin(list)==TRUE? "succeeded":"failed"); break;
      case 3: printf("Adding new node at end %s.\n", add_at_end(list)==TRUE? "succeeded":"failed"); break;
      case 4: printf("Adding new node in order %s.\n", add_at_order(list)==TRUE? "succeeded":"failed"); break;
      case 5: printf("Removing node from list %s.\n", remove_node(list)==TRUE? "succeeded":"failed"); break;
      case 6: printf("Reversing list %s.\n", reverse_list(list)==TRUE? "succeeded":"failed"); break;
      case 7: printf("Sorting list %s.\n", sort_list(list)==TRUE? "succeeded":"failed"); break;
      case 8: printf("Printing all nodes in list %s.\n", print_list(list)==TRUE? "succeeded":"failed");break;
      case 9: printf("Removing list %s.\n", remove_list(&list)==TRUE? "succeeded":"failed");break;
      case 10:printf("Function checking number of nodes %s.\n", count_nodes(list)==TRUE? "succeeded":"failed"); break;
      default: printf("This should never happen.\n"); break;
    }
  }
  printf("Freeing memory %s.\n", remove_list(&list)==TRUE? "succeeded":"failed");
  return 0;
}






int menu(void)
{
  int response=1;
  do{
  
  if(response<1 || response>11)
    printf("\n*****Wrong selection. Select option 1-9*****\n\n\n");
  printf("\n*** SLL INTERFACE MENU ***\n\n");
  printf("Choose option:\n");
  printf("1) Create new empty list (removes previously created one.\n");
  printf("2) Add node at beginning of list.\n");
  printf("3) Add node at end of list.\n");
  printf("4) Add node in right place like list was sorted ascending.\n");
  printf("5) Remove node from the list.\n");
  printf("6) Reverse list.\n");
  printf("7) Sort list.\n");
  printf("8) Print all nodes in the list.\n");
  printf("9) Remove list.\n");
  printf("10) Count nodes in the list.\n");
  printf("11) Quit.\n");
  if(scanf("%d", &response)==0)
    scanf("%*s");
  
  } while(response <1 || response>11);
  
  return response;
}
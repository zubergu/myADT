#include "sll.h"

int menu(void); /* function to print menu and return user option */




int main(void)
{
  int choice=0;
  Head * list=NULL; /* list is pointer to Head structure */
  
  
  
  while((choice=menu())!=9)
  {
    switch(choice)
    {
      case 1: printf("Creating new list %s.\n", create_list(&list)==TRUE? "succeeded":"failed");break;
      case 2: printf("Adding new node at beginning %s.\n", add_at_begin(list)==TRUE? "succeeded":"failed");break;
      case 3: printf("Adding new node at end %s.\n", add_at_end(list)==TRUE? "succeeded":"failed");break;
      case 4: break;
      case 5: break;
      case 6: break;
      case 7: printf("Printing all nodes in list %s.\n", print_list(list)==TRUE? "succeeded":"failed");break;
      case 8: break;
      default: printf("This should never happen.\n"); break;
    }
  }
  printf("And here user chose to quit\n");
  
  return 0;
}






int menu(void)
{
  int response=1;
  do{
  
  if(response<1 || response>9)
    printf("\n*****Wrong selection. Select option 1-9*****\n\n\n");
  printf("\n*** SLL INTERFACE MENU ***\n\n");
  printf("Choose option:\n");
  printf("1) Create new empty list (removes previously created one.\n");
  printf("2) Add node at beginning of list.\n");
  printf("3) Add node at end of list.\n");
  printf("4) Add node in right place like list was sorted ascending.\n");
  printf("5) Reverse list.\n");
  printf("6) Sort list.\n");
  printf("7) Print all nodes in the list.\n");
  printf("8) Remove list.\n");
  printf("9) Quit.\n");
  if(scanf("%d", &response)==0)
    scanf("%*s");
  
  } while(response <1 || response>9);
  
  return response;
}
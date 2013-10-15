#include "sll.h"


/*
 * 
 * Get user input for node value.
 * 
 */

int get_node_value(void)
{
  int node_val=0;
  
  printf("Input value for new node.\n");
  while(scanf("%d", &node_val)!=1)
  {
    printf("Node value has to be integer type.Try again.\n");
    scanf("%*s");
  }
  return node_val;
}

/* 
 *
 * create and initialize new list. Remove previous list if exists
 *
 *
 */
Bool create_list(Head **list_ptr)
{
  
  if(*list_ptr!=NULL)
  {
    /*remove previous list */
  }
  if((*list_ptr=malloc(sizeof(Head)))==NULL)
  {
    return FALSE;
  }
  
  (**list_ptr).value=0;
  (**list_ptr).next=NULL;
  return TRUE;
}


/*
 * 
 * Add node at beginning of the list_ptr
 * 
 */
Bool add_at_begin(Head *list)
{
  Node * new;
  
  if(list==NULL)
  {
    printf("List wasn't created yet.\n");
    return FALSE;
  }
  if((new=malloc(sizeof(Node)))==NULL)
    return FALSE;
  
  new->value=get_node_value(); /* calls function that takes user input for value */
  new->next=list->next;
  list->next=new;
  list->value+=1;
  return TRUE;
}


/*
 * 
 * Insert now node at end of current list_ptr
 * 
 */
Bool add_at_end(Head *list)
{
  Node * new;
  Node * end;
  
  if(list==NULL)
  {
    printf("List wasn't created yet.\n");
    return FALSE;
  }
  
  if((new=malloc(sizeof(Node)))==NULL)
  {
    return FALSE;
  }
  
  end=list;
  while(end->next!=NULL)
  {
    end=end->next;
  }
  
  new->value=get_node_value();
  new->next=NULL;
  end->next=new;
  
  return TRUE;
}
  

  
  
/*
 * 
 * Print list
 * 
 */
Bool print_list(const Head * list)
{
  const Node * current;
  int counter=0;
  
  if(list==NULL)
  {
    printf("Create list first.\n");
    return FALSE;
  }
  
  current=list->next;
  
  while(current!=NULL)
  {
    counter++;
    printf("Value of node # %d = %d\n", counter, current->value);
    current=current->next;
  }
  
  if(counter==0)
    printf("There are no nodes in your list yet.\n");
  
  return TRUE;
}







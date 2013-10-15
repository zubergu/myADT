#include "sll.h"


/*
 * 
 * Get user input for node value.
 * 
 */

int get_node_value(void)
{
  int node_val=0;
  
  printf("Input value of node:\n");
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
  
  list->value+=1; /* increase nodes counter in head of list */
  
  return TRUE;
}
  
/*
 * 
 * Inserts node in before first node >= value of new node
 * 
 */
Bool add_at_order(Head * list)
{
  Node * new;
  Node * curr;
  Node * previous;
  
  if(list==NULL)
  {
    printf("Create list first.\n");
    return FALSE;
  }
  
  if((new=malloc(sizeof(Node)))==NULL)
  {
    return FALSE;
  }
  
  new->value=get_node_value();
  
  previous=list;
  curr=list->next;
  
  while(curr!=NULL && curr->value<new->value)
  {
    previous=curr;
    curr=curr->next;
  }
  new->next=curr;
  previous->next=new;
  
  list->value+=1;
  
  return TRUE;
}
 
/*
 * 
 * Remove node from the list
 * 
 */
Bool remove_node(Head *list)
{
  int value;
  Node * previous;
  Node * curr;
  
  if(list==NULL)
  {
    printf("Create list first.\n");
    return FALSE;
  }
  
  value=get_node_value();
  
  previous=list;
  curr=list->next;
  
  while(curr!=NULL && curr->value!=value)
  {
    previous=curr;
    curr=curr->next;
  }
  
  if(curr==NULL)
  {
    printf("Couldn't find node with given value.\n");
    return FALSE;
  }
  
  previous->next=curr->next;
  free(curr);
  
  list->value-=1;
  
  printf("Node removed from list.\n");
  
  return TRUE;
}
  

  
/* 
 * 
 * Reverse order of nodes in the list.
 * 
 */
Bool reverse_list(Head * list)
{
  Node * prev_node=NULL;
  Node * curr_node;
  Node * next_node;
  if(list==NULL)
  {
    printf("Create list first.\n");
    return FALSE;
  }
  
  curr_node=list->next;
  while(curr_node!=NULL)
  {
    next_node=curr_node->next;
    curr_node->next=prev_node;
    prev_node=curr_node;
    curr_node=next_node;
  }
  list->next=prev_node;
  
  return TRUE;
}
  

/*
 * 
 * Sorts list in ascending order
 * 
 */

/* sort_add() adds node in ascending order and is used only by sort_list() */
Bool sort_add(Head * list, int value)
{
  Node * new;
  Node * curr;
  Node * previous;
  
  if((new=malloc(sizeof(Node)))==NULL)
  {
    return FALSE;
  }
  
  new->value=value;
  
  previous=list;
  curr=list->next;
  
  while(curr!=NULL && curr->value<new->value)
  {
    previous=curr;
    curr=curr->next;
  }
  new->next=curr;
  previous->next=new;
  
  list->value+=1;
  
  return TRUE;
}
/**************************************************************/
Bool sort_list(Head * list)
{
  if(list==NULL)
  {
    printf("Create list first.\n");
    return FALSE;
  }
  Head temp_head={0, NULL};
  Node * curr=list->next;
  Node * to_free;
  

  
  while(curr!=NULL)
  {
    to_free=curr;
    sort_add(&temp_head, curr->value);
    
    curr=curr->next;
    free(to_free);
  }
  if(list->value!=temp_head.value) /* if number of nodes in the beginning != number of nodes at the end */
  {
    *list=temp_head;
    return FALSE;
  }
  *list=temp_head;
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


/*
 * 
 * How many nodes are in the list_ptr
 * 
 */
Bool count_nodes(const Head * list)
{
  if(list==NULL)
  {
    printf("List wasn't created yet.\n");
    return FALSE;
  }
  printf("Number of nodes in the list: %d\n", list->value);
  return TRUE;
}






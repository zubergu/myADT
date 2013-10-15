#ifndef _SLL_H_
#define _SLL_H_

#include <stdio.h>
#include <stdlib.h>

/******************
 * 
 * STRUCTURES AND TYPEDEFS
 * 
 * ****************/

typedef enum {FALSE, TRUE} Bool; /* type that will be returned from functions.
				    TRUE-function succeeded, FALSE-failed*/

typedef struct Node {
  int value;
  struct Node * next;
} Node;

typedef Node Head; /* Head is the same as node.
                   value will hold number of nodes in list
                   and next will be pointer to first node in list */
                   

/******************
 * 
 * FUNCTIONS DECLARATIONS
 * 
 * ****************/

int get_node_value(void);

Bool create_list(Head **list_ptr);

Bool add_at_begin(Head *list);

Bool add_at_end(Head *list);

Bool add_at_order();

Bool remove_node();

Bool reverse_list();

Bool sort_list();

Bool print_list(const Head *list);

Bool remove_list();

#endif

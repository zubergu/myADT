#ifndef _STACK_H_
#define _STACK_H_

#include <stdio.h>
#include <stdlib.h>

/***********
 * 
 * DATA STRUCTURES AND TYPEDEFS
 * 
 * *********/

typedef struct element{
  int value;
  struct element *prev;
} Element;

typedef Element * StackT; /* StackT is a pointer to Element type */




/*******************
 * 
 * FUNCTIONS DECLARATIONS
 * 
 * *****************/
int get_value(void);

void push(StackT * stack_ptr);

int pop(StackT * stack_ptr, int * empty_flag);

void top(StackT stack);

void print_stack(StackT stack);

void remove_stack(StackT stack);

#endif
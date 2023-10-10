/*Copyright 2019-2023 Kai D. Gonzalez*/

#include "string.h"
#include "tlimits.h" // MAX_TODO_LIST_SIZE

#ifndef __TDL_H
#define __TDL_H

// basic constructs for a todo list
typedef struct Todo
{
  string *name; // the name of the todo (also works as a codename for the todo)
  string *desc; // the body of the todo
} Todo;

// contains a list of todos
typedef struct TodoList
{
  Todo todos[MAX_TODO_LIST_SIZE]; // the list of todos
  int size; // the size of the list (for iteration purposes)
  int pos;  // the current position
} TodoList;

// add a new todo to the list
void add_todo (TodoList *list, string *name, string *desc);

// remove a todo from the list
void remove_todo (TodoList *list, string *name);

// returns the index of a todo by name
int get_todo_index (TodoList *list, string *name);

// allocates a todo list
void todo_list_init (TodoList *list);

// checks if a todo list has no members, if there are members return the amount of members
int todo_list_empty (TodoList *list);
#endif

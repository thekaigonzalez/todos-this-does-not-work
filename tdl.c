/*Copyright 2019-2023 Kai D. Gonzalez*/

#include "tdl.h"
#include "tlimits.h"

#include <string.h>

void
copy (string *s1, string *s2)
{
  s2->_p = malloc (strlen (s1->_p) + 1);
  strcpy (s2->_p, s1->_p);
  s2->_s = s1->_s;
}

void
add_todo (TodoList *list, string *name, string *desc)
{
  string1 (list->todos[list->pos].name);
  string1 (list->todos[list->pos].desc);
  copy (list->todos[list->pos].name,
        name); // copy name to list->todos[list->pos].name;
  copy (list->todos[list->pos].desc, desc);
  list->pos = list->pos + 1;
  //   printf ("%i\n", list->pos);
}

int
get_todo_index (TodoList *list, string *name)
{
  for (int i = 0; i < list->size - 1; i++)
    {
      if (i >= list->pos) // if the index is greater than or equal to the
                          // current position
        {
          break; // to prevent a segfault
        }
      if (strcmp (get_string (list->todos[i].name), get_string (name))
          == 0) // if the name matches the name in the array
        {
          return i; // return the index
        }
    }
  return -1; // if there is no match
}

void
todo_list_init (TodoList *list)
{
  list->size = MAX_TODO_LIST_SIZE; /* set the size of the list */
  list->pos = 0;                   /* set the current position */
}

int
todo_list_empty (TodoList *list)
{
  if (list->pos > 0) // if the current position is 0
    {
      return list->pos;
    }
  return 0;
}

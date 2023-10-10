#include "bug.h"
#include "string.h"

#include <stdio.h>

void
print_todo_list (TodoList *list)
{
    for (int i = 0 ; i < list->size-1 ; i++)
    {
        if (i >= list->pos) // if the index is greater than or equal to the
                          // current position
        {
          break; // to prevent a segfault
        }
        printf ("\n\tname\t%s\n", get_string(list->todos[i].name));
        printf ("\tdesc\t%s\n", get_string(list->todos[i].desc));
        printf ("\n");
    }
}

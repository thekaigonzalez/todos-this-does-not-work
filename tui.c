#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "bug.h"
#include "string.h"
#include "tdl.h"
#include "tlimits.h"

#define stris(x, y) (strcmp (x, y) == 0)

void
input_prompt (string *s)
{
  string1 (s);
  char sz = getchar ();
  while (sz != '\n')
    {
      string_append (s, sz);
      sz = getchar ();
    }
}


void
save_todo_list (TodoList *list)
{
  string final;
  string1 (&final);

  for (int i = 0; i < list->size - 1; i++)
    {
        printf("%i\n", i);
      if (i >= list->pos) // if the index is greater than or equal to the
                          // current position
        {
          break; // to prevent a segfault
        }
      
      printf("n %s\n", get_string (list->todos[i].name));
      sputs (&final, get_string (list->todos[i].name));
      string_append (&final, ':'); // all entries are separated by ':'

      sputs (&final, get_string (list->todos[i].desc));

      string_append (&final, ':');

      string_append (&final, '\n');
      continue;
    }

  printf ("%s\n", get_string (&final));

  string1 (&final);
}

int
main (void)
{
  TodoList t;
  todo_list_init (&t);

  printf ("welcome to todo!\n");
  system ("clear");
menu:
  printf ("type 'open' to open a todo list\n");
  printf ("type 'add' to add a todo to the current list\n");
  printf (
      "type 'remove' to remove a todo from the current list (by its name)\n");
  printf ("type 'save' to save the current list\n");
  printf ("type 'print' to print the current list\n");
  printf ("type 'exit' to exit the program\n");
  string input1;

  while (1)
    {
      input_prompt (&input1);

      if (stris ("exit", get_string (&input1)))
        {
          break;
        }
      else if (stris ("print", get_string (&input1)))
        {
          if (todo_list_empty (&t) == 0)
            {
              printf ("there are no todos! add some by using the 'add' "
                      "command.\n");
              sleep (2);
              system ("clear");

              goto menu;
            }
          else
            {
              system ("clear");
              print_todo_list (&t);
              printf ("--------------------------\n");
              goto menu;
            }
        }
      else if (stris ("save", get_string (&input1)))
        {
          if (todo_list_empty (&t) == 0)
            {
              printf ("there are no todos! add some by using the 'add' "
                      "command.\n");
              sleep (2);
              system ("clear");
              goto menu;
            }
          else
            {
              printf ("saving the current list!\n");
              save_todo_list (&t);
              sleep (3);
              system ("clear");
              goto menu;
            }
        }
      else if (stris ("add", get_string (&input1)))
        {
          printf ("what is the name of this todo? ");
          string name;
          input_prompt (&name);

          printf ("what is the description of this todo? ");

          string desc;
          input_prompt (&desc);
          
          printf("n %s\n", get_string (&name));
          printf("d %s\n", get_string (&desc));
          printf ("alright, adding `%s' to the current list! :)\n",
                  get_string (&name));

          add_todo (&t, &name, &desc);
          sleep (3);
          system ("clear");
          goto menu;
        }
      else
        {
          if (strlen (input1._p) > 0)
            {
              printf ("that is not a valid command!\n");
              sleep (2);
              system ("clear");
              goto menu;
            }
          else
            {
              system ("clear");
              goto menu;
            }
        }
    }
  return 0;
}

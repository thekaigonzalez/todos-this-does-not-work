#include "tdl.h"
#include "tlimits.h"
#include "bug.h" // print_todo_list

#include <stdio.h>

int main() {
    TodoList t;

    todo_list_init(&t);

    print_todo_list(&t);

    return 0;
}

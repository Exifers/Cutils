#include <stdio.h>
#include <stdlib.h>

#include "llist/llist.h"
#include "dict/dict.h"
#include "main.h"

void print_int(int a)
{
  printf("%d", a);
}

void test_list(void)
{
  struct llist *l = llist_init();

  llist_print(l, print_int);

  llist_append(l, 2);
  llist_append(l, 3);
  llist_append(l, 4);
  llist_append(l, 5);
  llist_append(l, 6);
  llist_append(l, 7);

  llist_print(l, print_int);

  llist_pop(l);
  llist_pop(l);
  llist_pop(l);

  llist_get_size(l);

  llist_print(l, print_int);

  llist_append(l, 2);
  llist_append(l, 3);
  llist_append(l, 4);
  llist_append(l, 5);

  llist_get_size(l);

  llist_print(l, print_int);

  llist_get_item(l, 0);
  llist_get_item(l, 1);
  llist_get_item(l, 2);
  llist_get_item(l, 3);
  llist_get_item(l, 4);
  llist_get_item(l, 5);
  llist_get_item(l, 6);

  llist_get_size(l);

  llist_print(l, print_int);

  llist_free(l);
}


void test_dict(void)
{

}


int main(void)
{
  test_list();
  test_dict();

  return 0;
}

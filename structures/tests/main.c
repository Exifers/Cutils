#include <stdio.h>
#include <stdlib.h>

#include "llist/llist.h"
#include "dict/dict.h"
#include "main.h"

void print_func(void *l, int offset)
{
  llist_print(l, offset, 2, print_func);
}

void free_func(void *l)
{
  llist_free(l, free_func);
}

void test_list(void)
{
  struct llist *l = llist_init();
  llist_append(l, llist_init());
  llist_append(l, llist_init());

  struct llist *g = llist_init();
  llist_append(g, llist_init());
  llist_append(g, llist_init());
  llist_append(g, llist_init());

  struct llist *h = llist_init();
  llist_append(h, g);
  llist_append(h, l);

  llist_print(h, 0, 2, print_func);
  printf("\n");

  llist_free(h, free_func);
}


void test_dict(void)
{
  return;
}
/*
  struct dict *d = dict_init();

  dict_pop(d);
  
  dict_get_item(d, "a");

  dict_get_size(d);

  dict_print(d, print_int);

  dict_append(d, 2, NUMBER, "a");
  dict_append(d, 3, NUMBER, "b");
  dict_append(d, 4, NUMBER, "c");
  dict_append(d, 5, NUMBER, "d");
  dict_append(d, 6, NUMBER, "e");
  dict_append(d, 7, NUMBER, "f");
  dict_append(d, 8, NUMBER, "g");
  dict_append(d, 9, NUMBER, "hu");
  dict_append(d, 10, NUMBER, "i");

  dict_print(d, print_int);

  dict_pop(d);
  dict_pop(d);
  dict_pop(d);

  dict_get_size(d);

  dict_print(d, print_int);

  dict_free(d);
}
*/

int main(void)
{
  test_list();
  test_dict();

  return 0;
}

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

  llist_append(l, 2, NUMBER);
  llist_append(l, 3, NUMBER);
  llist_append(l, 4, NUMBER);
  llist_append(l, 5, NUMBER);
  llist_append(l, 6, NUMBER);
  llist_append(l, 43, NUMBER);

  llist_print(l, print_int);

  llist_pop(l);
  llist_pop(l);
  llist_pop(l);

  llist_get_size(l);

  llist_print(l, print_int);

  llist_append(l, 123, NUMBER);
  llist_append(l, 43, NUMBER);
  llist_append(l, 7, NUMBER);
  llist_append(l, 8, NUMBER);

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


int main(void)
{
  test_list();
  test_dict();

  return 0;
}

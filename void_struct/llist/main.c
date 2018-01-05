#include <stdio.h>
#include <stdlib.h>

#include "llist.h"

enum data_type
{
  INT,
  STRING,
  LIST,
  ALIEN
};

void print_fun(void *data, int type, int offset, int inc)
{
  switch(type)
  {
    case INT:
      printf("%d", *((int *) data));
      break;
    case STRING:
      printf("%s", (char *) data);
      break;
    case LIST:
      llist_print(data, offset, inc, print_fun);
      break;
    case ALIEN:
      printf("some alien !!!");
    default:
      break;
  }
}

void free_data(void *data, int type)
{
  switch(type)
  {
    case INT:
      free(data);
      break;
    case STRING:
      break;
    case LIST:
      llist_free(data, free_data);
      break;
    default:
      break;
  }
}

int main(void)
{
  struct llist *l = llist_init();

  llist_append(l, "bonjour", STRING);
  llist_append(l, "aurevoir", STRING);
  llist_append(l, "salut", STRING);
  llist_append(l, "hi", STRING);
  llist_append(l, "re", STRING);

  int *a = malloc(sizeof(int));
  int *b = malloc(sizeof(int));
  int *c = malloc(sizeof(int));
  int *d = malloc(sizeof(int));

  *a = 12;
  *b = 25;
  *c = 6;
  *d = -1;

  llist_append(l, a, INT);
  llist_append(l, b, INT);
  llist_append(l, c, INT);
  llist_append(l, d, INT);

  struct llist *g = llist_init();

  llist_append(g, "bonjour", STRING);
  llist_append(g, "aurevoir", STRING);
  llist_append(g, "salut", STRING);
  llist_append(g, "hi", STRING);
  llist_append(g, "re", STRING);

  int *f = malloc(sizeof(int));
  int *z = malloc(sizeof(int));
  int *h = malloc(sizeof(int));
  int *i = malloc(sizeof(int));

  *f = 12;
  *z = 25;
  *h = 6;
  *i = -1;

  llist_append(g, f, INT);
  llist_append(g, z, INT);
  llist_append(g, h, INT);
  llist_append(g, i, INT);

  llist_append(l, g, LIST);
  llist_append(l, "end", STRING);
  llist_append(l, "a", ALIEN);

  llist_print(l, 0, 6, print_fun);
  printf("\n");

  llist_free(l, free_data);

  return 0;
}

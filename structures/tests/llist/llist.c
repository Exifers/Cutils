#include <stdio.h>
#include <stdlib.h>
#include <err.h>

#include "llist.h"

struct llist *llist_init(void)
{
  struct llist *res = malloc(sizeof(struct llist));
  if (!res)
    perror(NULL);

  res->size = 0;
  res->head = NULL;

  return res;
}

void llist_append(struct llist *l, DATA_TYPE data
                  #if ADD_TYPE_ENUM == 1
                  , TYPE_ENUM type
                  #endif
                  )
{
  if (!l)
    errx(1, "linked list is NULL");

  struct llist_elt *new = malloc(sizeof(struct llist_elt));
  if (!new)
    perror(NULL);
  new->data = data;
  new->next = NULL;
  #if ADD_TYPE_ENUM == 1
  new->type = type;
  #endif

  struct llist_elt *cur = l->head;
  if (!cur)
  {
    l->head = new;
    l->size++;
    return;
  }
  while (cur->next)
    cur = cur->next;
  cur->next = new;
  l->size++;
}

DATA_TYPE llist_pop(struct llist *l)
{
  if (!l)
    errx(1, "linked list is NULL");

  struct llist_elt *cur = l->head;

  if (!cur)
    return NULL_DATA;

  if (!cur->next)
  {
    DATA_TYPE ret = cur->data;
    #if FREE_DATA != 0
    free(cur->data);
    #endif
    free(cur);
    l->head = NULL;
    l->size--;
    return ret;
  }

  while(cur->next->next)
    cur = cur->next;
  DATA_TYPE ret = cur->next->data;
  #if FREE_DATA != 0
  free(cur->next->data);
  #endif
  free(cur->next);
  cur->next = NULL;
  l->size--;

  return ret;
}

DATA_TYPE llist_get_item(struct llist *l, size_t index)
{
  if (!l)
    errx(1, "linked list is NULL");

  if (index >= l->size)
    errx(1, "list index out of range");

  struct llist_elt *cur = l->head;
  for (size_t i = 0; i < index; i++)
    cur = cur->next;

  return cur->data;
}

size_t llist_get_size(struct llist *l)
{
  if (!l)
    errx(1, "linked list is NULL");

  return l->size;
}

void llist_free(struct llist *l)
{
  if (!l)
    errx(1, "linked list is NULL");

  size_t size = l->size;
  for (size_t i = 0; i < size; i++)
    llist_pop(l);
  free(l);
}

void llist_print(struct llist *l, void (*print_fun)(DATA_TYPE data))
{
  if (!l)
    errx(1, "linked list is NULL");

  if (l->size == 0)
  {
    printf("empty linked list\n");
    return;
  }

  struct llist_elt *cur = l->head;
  for (size_t i = 0; i < l->size; i++)
  {
    print_fun(cur->data);
    printf("\n");
    cur = cur->next;
  }
}

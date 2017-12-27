#include <err.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dict.h"

struct dict *dict_init(void)
{
  struct dict *res = malloc(sizeof(struct dict));
  if (!res)
    perror(NULL);

  res->size = 0;
  res->head = NULL;

  return res;
}

void dict_append(struct dict *d, DATA_TYPE data, char *key)
{
  if (!d)
    errx(1, "dictionary is NULL");
  
  struct dict_elt *new = malloc(sizeof(struct dict_elt));
  if (!new)
    perror(NULL);
  new->data = data;
  new->key = key;
  new->next = NULL;

  struct dict_elt *cur = d->head;
  if (!cur)
  {
    d->head = new;
    d->size++;
    return;
  }
  while (cur->next)
    cur = cur->next;
  cur->next = new;
  d->size++;
}

DATA_TYPE dict_pop(struct dict *d)
{
  if (!d)
    errx(1, "dictionary is NULL");

  struct dict_elt *cur = d->head;

  if (!cur)
    return NULL_DATA;

  if (!cur->next)
  {
    DATA_TYPE ret = cur->data;
    free(cur);
    d->head = NULL;
    d->size--;
    return ret;
  }

  while(cur->next->next)
    cur = cur->next;
  DATA_TYPE ret = cur->next->data;
  free(cur->next);
  cur->next = NULL;
  d->size--;

  return ret;
}

DATA_TYPE dict_get_item(struct dict *d, char *key)
{
  if (!d)
    errx(1, "dictionary is NULL");

  struct dict_elt *cur = d->head;
  for (size_t i = 0; i < d->size; i++)
  {
    if (strcmp(key, cur->key) == 0)
      return cur->data;
    cur = cur->next;
  }

  return NULL_DATA;
}

size_t dict_get_size(struct dict *d)
{
  if (!d)
    errx(1, "dictionary is NULL");
  
  return d->size;
}

void dict_free(struct dict *d)
{
  if (!d)
    errx(1, "dictionary is NULL");

  size_t size = d->size;
  for (size_t i = 0; i < size; i++)
    dict_pop(l);
  free(l);
}

void dict_print(struct dict *d, void (*print_fun)(DATA_TYPE data))
{
  if (!d)
    errx(1, "dictionary is NULL");
  
  if (l->size == 0)
  {
    printf("empty dictionary\n");
    return;
  }

  struct dict_elt *cur = d->head;
  for (size_t i = 0; i < d->size; i++)
  {
    printf("%s : ", cyr->key);
    print_fun(cur->data);
    printf("\n");
    cur = cur->next;
  }
}

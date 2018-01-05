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

void dict_append(struct dict *d, DATA_TYPE data,
                 #if ADD_TYPE_ENUM == 1
                 TYPE_ENUM type,
                 #endif
                 char *key)
{
  if (!d)
    errx(1, "dictionary is NULL");

  struct dict_elt *new = malloc(sizeof(struct dict_elt));
  if (!new)
    perror(NULL);
  new->data = data;
  new->key = key;
  new->next = NULL;
  #if ADD_TYPE_ENUM == 1
  new->type = type;
  #endif

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

void dict_pop(struct dict *d
#if FREE_DATA == 1
, void (*free_data)(DATA_TYPE data
#if ADD_TYPE_ENUM == 1
, TYPE_ENUM type
#endif
)
#endif
)
{
  if (!d)
    errx(1, "dictionary is NULL");

  struct dict_elt *cur = d->head;

  if (!cur)
    return;

  if (!cur->next)
  {
    #if FREE_DATA == 1
    #if ADD_TYPE_ENUM == 1
    free_data(cur->data, cur->type);
    #else
    free_data(cur->data);
    #endif
    #endif
    #if FREE_KEY == 1
    free(cur->key);
    #endif
    free(cur);
    d->head = NULL;
    d->size--;
    return;
  }

  while(cur->next->next)
    cur = cur->next;

  #if FREE_DATA == 1
  #if ADD_TYPE_ENUM == 1
  free_data(cur->next->data, cur->type);
  #else
  free_data(cur->next->data);
  #endif
  #endif
  #if FREE_KEY == 1
  free(cur->next->key);
  #endif
  free(cur->next);
  cur->next = NULL;
  d->size--;
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

void dict_free(struct dict *d
#if FREE_DATA == 1
, void (*free_data)(DATA_TYPE data
#if ADD_TYPE_ENUM == 1
, TYPE_ENUM type
#endif
)
#endif
)
{
  if (!d)
    errx(1, "dictionary is NULL");

  size_t size = d->size;
  for (size_t i = 0; i < size; i++)
    dict_pop(d
    #if FREE_DATA == 1
    , free_data
    #endif
    );
  free(d);
}

static void print_offset(int offset)
{
  for (int i = 0; i < offset; i++)
    printf(" ");
}

void dict_print(struct dict *d, int offset, int inc,
     void (*print_fun)(DATA_TYPE data, enum data_type type, int offset))
{
  if (!d)
    errx(1, "dictionary is NULL");

  if (d->size == 0)
  {
    printf("empty dictionary\n");
    return;
  }

  struct dict_elt *cur = d->head;
  printf("{\n");
  for (size_t i = 0; i < d->size; i++)
  {
    print_offset(offset + inc);
    printf("\"%s\" : ", cur->key);
    print_fun(cur->data, cur->type, offset + inc);
    if (i != d->size - 1)
      printf(",");
    printf("\n");
    cur = cur->next;
  }
  print_offset(offset);
  printf("}");
}

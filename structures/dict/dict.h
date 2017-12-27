#ifndef DICT_H
# define DICT_H

/* Data type stored in the ditionary */
#define DATA_TYPE int

/* Data returned by dict_pop and dict_get_item when no data is found */
#define NULL_DATA 0

#include <stddef.h>

struct dict_elt
{
  char *key;
  DATA_TYPE data;
  struct dict_elt *next;
};

struct dict
{
  size_t size;
  struct dict_elt *head;
};

struct dict *dict_init(void);
void dict_append(struct dict *l, DATA_TYPE data);
DATA_TYPE dict_pop(struct dict *l);
DATA_TYPE dict_get_item(struct dict *l, char *key);
size_t dict_get_size(struct dict *l);
void dict_free(struct dict *l);
void dict_print(struct dict *l, void (*print_fun)(DATA_TYPE data));

#endif /* !DICT_H */

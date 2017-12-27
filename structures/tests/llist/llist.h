#ifndef LLIST_H
# define LLIST_H

/* Data type stored in the linked list */
#define DATA_TYPE int

/* Data returned by llist_pop and llist_get_item when no data is found */
#define NULL_DATA 0

/* Free data while freeing the list if set to 1 */
#define FREE_DATA 0

#include <stddef.h>

struct llist_elt
{
  DATA_TYPE data;
  struct llist_elt *next;
};

struct llist
{
  size_t size;
  struct llist_elt *head;
};

struct llist *llist_init(void);
void llist_append(struct llist *l, DATA_TYPE data);
DATA_TYPE llist_pop(struct llist *l);
DATA_TYPE llist_get_item(struct llist *l, size_t index);
size_t llist_get_size(struct llist *l);
void llist_free(struct llist *l);
void llist_print(struct llist *l, void (*print_fun)(DATA_TYPE data));

#endif /* !LLIST_H */

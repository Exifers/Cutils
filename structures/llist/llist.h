#ifndef LLIST_H
# define LLIST_H

/* Data type stored in the linked list */
#define LLIST_DATA_TYPE void *

/* Data returned by llist_pop and llist_get_item when no data is found */
#define LLIST_NULL_DATA NULL

/* Free data while freeing the list if set to 1 */
#define LLIST_FREE_DATA 1

#include "../enum.h"
/* If LLIST_DATA_TYPE is 'void *', it might be handy to store an enum in list
** elements to know into which type of data the data field points, to do this
** set LLIST_ADD_TYPE_ENUM to 1, 0 otherwise. The name of the enum is
** specified in LLIST_TYPE_ENUM.
**
** --------------------------------------------------------------------
** | You have to include your own header to declare the enum as well |
** --------------------------------------------------------------------
*/
#define LLIST_ADD_TYPE_ENUM 0
#define LLIST_TYPE_ENUM enum data_type

#include <stddef.h>

struct llist_elt
{
  LLIST_DATA_TYPE data;
  #if LLIST_ADD_TYPE_ENUM == 1
  LLIST_TYPE_ENUM type;
  #endif
  struct llist_elt *next;
};

struct llist
{
  size_t size;
  struct llist_elt *head;
};

struct llist *llist_init(void);

void llist_append(struct llist *l, LLIST_DATA_TYPE data
                  #if LLIST_ADD_TYPE_ENUM == 1
                  , LLIST_TYPE_ENUM type
                  #endif
                  );

void llist_pop(struct llist *l
               #if LLIST_FREE_DATA == 1
               , void (*free_data)(LLIST_DATA_TYPE data
               #if LLIST_ADD_TYPE_ENUM == 1
               , LLIST_TYPE_ENUM type
               #endif
               )
               #endif
               );

LLIST_DATA_TYPE llist_get_item(struct llist *l, size_t index);
size_t llist_get_size(struct llist *l);

void llist_free(struct llist *l
                #if LLIST_FREE_DATA == 1
                , void (*free_data)(LLIST_DATA_TYPE data
                #if LLIST_ADD_TYPE_ENUM == 1
                , LLIST_TYPE_ENUM type
                #endif
                )
                #endif
                );

void llist_print(struct llist *l, int offset, int inc,
                 void (*print_fun)(LLIST_DATA_TYPE data,
                 #if LLIST_ADD_TYPE_ENUM == 1
                 enum data_type type,
                 #endif
                 int offset));

#endif /* !LLIST_H */

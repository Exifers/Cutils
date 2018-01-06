# Json-parser
Quick home-made json parser into C structures. This is some very basic program,
threre's no warranty.

# Usage
## Prerequisites
- GNU/Linux
- glibc
- gcc
- make
## Compile
Type *make* to produce binary *main*.
## Run
*./main \<filename.json\>*
Outputs the formatted json, or raise an error if input is incorrect.
## Include in an existing project
You can remove src/main.c and src/main.h. Everything else in the src/ folder
is needed.

# API
{  } objects are named dict (for dictionaries).  
[  ] arrays are named llist (for linked lists).

## parse file and free structure
```c
#include "src/parser/parser.h"

/** Parses the input string of length len into a C structure whose type is given
** by the type variable after calling this function. */
void *parse_json(char *string, size_t len, enum data_type *type);
```

The data\_type enum is the following :
```c
enum data_type
{
  DICT, // dictionnary
  LIST, // linked list
  STRING, // string
  NUMBER, // number (only integers supported yet)
  TRUE,
  FALSE,
  NUL, // "null"
  EMPTY // empty file
};
```

Your json file may not contain much things if the returned type is not DICT or
LIST, but this is handled by this program anyway.

```c
#include "src/parser/parser.h"
#include "src/free/free.h"

/** Frees everything returned from parse_json. data must be the pointer returned
**  by parse_json, and type the enum set by parse_json. */
void free_data(void *data, enum data_type type);
```

## browse the structure
```c
#include "src/dict/dict.h"

/** Returns a pointer to the key*s value, NULL if key is not found. */
void *dict_get_item(struct dict *d, char *key);
```

```c
#include "src/dict/dict.h"

/** Returns the size of the dictionary. */
size_t dict_get_size(struct dict *d);
```

```c
#include "src/llist/llist.h"

/** 
Returns a pointer to element at index, raises an error if index exceeds list's
size. */
void *llist_get_item(struct llist *l, size_t index);
```

```c
#include "src/llist/llist.h"

/** Returns the size of the list. */
size_t llist_get_size(struct llist *l);
```
Note that all values are pointers, so with numbers the get\_item functions will return a pointer to integer. For *null*, *true*, and *false* constants the returned value is *NULL*. See Bugs/Todo section below.

## print the structure
```c
#include "src/display/display.h"
#include "src/parser/parser.h"

/** Prints the structure on standard output. */
void print_data(void *data, enum data_type type);
```

# Bugs / Todo
- Only integers are supported for numbers.
- Add a data_type pointer with get_item functions.

# Licence
Public domain

# Authors
Exifers, Dec 2017

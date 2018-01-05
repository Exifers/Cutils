#include <stdio.h>
#include <stdlib.h>

#include "dict.h"

enum data_type
{
  STRING,
  NUMBER,
  DICT
};

void print_fun(void *data, int type, int offset, int inc)
{
  switch(type)
  {
    case STRING:
      printf("%s", (char *) data);
      break;
    case NUMBER:
      printf("%d", *((int *) data));
      break;
    case DICT:
      dict_print(data, offset, inc, print_fun);
      break;
    default:
      break;
  }
}

void free_data(void *data, int type)
{
  switch(type)
  {
    case STRING:
      break;
    case NUMBER:
      free(data);
      break;
    case DICT:
      dict_free(data, free_data);
      break;
    default:
      break;
  }
}

int main(void)
{
  struct dict *d = dict_init();

  char *key1 = malloc(sizeof(char) * 4);
  key1[0] = 'h';
  key1[1] = 'o';
  key1[2] = 'u';
  key1[3] = '\0';
  dict_append(d, "hi", STRING, key1);

  char *key2 = malloc(sizeof(char) * 4);
  key2[0] = 'a';
  key2[1] = 'l';
  key2[2] = 'i';
  key2[3] = '\0';

  int *n = malloc(sizeof(int));
  *n = 10;

  dict_append(d, n, NUMBER, key2);

  struct dict *e = dict_init();
 
  char *key3 = malloc(sizeof(char) * 4);
  key3[0] = 'a';
  key3[1] = 'b';
  key3[2] = 'c';
  key3[3] = '\0';
  
  dict_append(e, "some", STRING, key3);

  char *key4 = malloc(sizeof(char) * 4);
  key4[0] = 's';
  key4[1] = 'd';
  key4[2] = 'i';
  key4[3] = '\0';

  dict_append(e, d, DICT, key4);


  dict_print(e, 0, 2, print_fun);
  printf("\n");

  dict_free(e, free_data);
  return 0;
}

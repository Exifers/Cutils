#include <stdio.h>
#include <stdlib.h>
#include <err.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>

#include "parser/parser.h"
#include "display/display.h"
#include "free/free.h"

int analyse_args(int argc, char **argv)
{
  if (argc < 2)
    errx(1, "Usage ./main <filename.json>");
  
  int f = open(argv[1], O_RDONLY);
  if (f == -1)
    perror(NULL);

  return f;  
}

char *map_file(int f, size_t *len)
{
  struct stat buf;
  fstat(f, &buf);
  *len = buf.st_size;

  char *addr = mmap(NULL, *len, PROT_READ, MAP_PRIVATE, f, 0);
  if (addr == MAP_FAILED)
    perror(NULL);
  
  return addr;
}

int main(int argc, char **argv)
{
  int f = analyse_args(argc, argv);
 
  size_t len = 0;
  char *addr = map_file(f, &len);

  enum data_type type;
  void *res = parse_json(addr, len, &type);

  print_data(res, type);

  free_data(res, type);
  
  munmap(addr, len);
  close(f);
  return 0;

}

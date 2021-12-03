#define FMMAP_IMPLEMENTATION
#define VSTR_IMPLEMENTATION
#include "utils.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char *
get_file_content(size_t *restrict content_size, const char *restrict path)
{
  fmmap_file *file;
  size_t size = 0;
  char *content, *temp;
  int err = 0;

  file = fmmap_open_file(path, "r");
  if (file == NULL)
    ERR_EXIT("Can't open the file `%s`\n", path);

  err = fmmap_mmap_file(&temp, file);
  if (err != 0)
    {
      fmmap_close_file(file);
      ERR_EXIT("Error while mapping the file into memory\n", "");
    }

  *content_size = file->size;
  content = (char *)malloc((*content_size + 1) * sizeof(char));
  strncpy(content, temp, *content_size);

  err = fmmap_close_file(file);
  if (err != 0)
    ERR_EXIT("Error while closing the file\n", "");

  return content;
}

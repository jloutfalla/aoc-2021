#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int
get_num(vstr *str)
{
  char *ptr = NULL;
  long ret = strtol(str->data, &ptr, 10);
  if (ptr == str->data)
    ret = INT_MAX;
  vstr_separate_delim(str, "\n");
  return ret;
}

void
part1(vstr content)
{
  int last_value, current_value, cmp, i;
  vstr line;
    
  i = -1;
  cmp = 0;

  last_value = get_num(&content);
  while ((current_value = get_num(&content)) != INT_MAX)
    {
      if (current_value > last_value)
        ++cmp;
      
      last_value = current_value;
    }

  printf("Part 1: %d\n", cmp); 
}

void
part2(vstr content)
{
  int a, b, c, d, cmp;  vstr line; 
  char *ptr = NULL;

  cmp = 0;
  a = get_num(&content);
  b = get_num(&content);
  c = get_num(&content);
  while ((d = get_num(&content)) != INT_MAX)//(line = vstr_separate_delim(&content, "\n")).size > 0)
    {
      if (a + b + c < b + c + d)
        cmp++;

      a = b;
      b = c;
      c = d;
    }

  printf("Part 2: %d\n", cmp);
}

int
main()
{
  int last_value, current_value, cmp, i;
  size_t content_size = 0;
  const char *str = get_file_content(&content_size, "1/input");
  vstr content = vstr_from_size_cstr(str, content_size);

  part1(content);
  part2(content);  
  
  free((void *)str);
  return 0;
}

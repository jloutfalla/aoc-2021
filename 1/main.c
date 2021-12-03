#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void
part1(vstr content)
{
  int last_value, current_value, cmp;
    
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
  int a, b, c, d, cmp; 

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

AOC_MAIN("1/input")

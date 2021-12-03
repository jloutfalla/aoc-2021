#include "utils.h"
#include <stdio.h>
#include <string.h>

static const char *directions[] = { "forward", "up", "down" };

void
part1(vstr content)
{
  int x, y;
  vstr line, dir;

  x = y = 0;
  while ((line = vstr_separate_delim(&content, "\n")).size > 0)
    {
      dir = vstr_separate_delim(&line, " ");
      if (strncmp(directions[0], dir.data, strlen(directions[0])) == 0)
        x += get_num(&line);
      else if (strncmp(directions[1], dir.data, strlen(directions[1])) == 0)
        y -= get_num(&line);
      else if (strncmp(directions[2], dir.data, strlen(directions[2])) == 0)
        y += get_num(&line);
    }

  printf("\
Part 1:\n\
\tx = %d\n\
\ty = %d\n\
\tFinal: %d\n", x, y, x * y);
}

void
part2(vstr content)
{
  int x, y, aim, tmp;
  vstr line, dir;

  x = y = aim = 0;
  while ((line = vstr_separate_delim(&content, "\n")).size > 0)
    {
      dir = vstr_separate_delim(&line, " ");
      if (strncmp(directions[0], dir.data, strlen(directions[0])) == 0)
        {
          tmp = get_num(&line);
          x += tmp;
          y += aim * tmp; 
        }
      else if (strncmp(directions[1], dir.data, strlen(directions[1])) == 0)
        {
          aim -= get_num(&line);
        }
      else if (strncmp(directions[2], dir.data, strlen(directions[2])) == 0)
        {
          aim += get_num(&line);
        }
    }

  printf("\
Part 2:\n\
\tx = %d\n\
\ty = %d\n\
\taim %d\n\
\tFinal: %d\n", x, y, aim, x * y);
}

AOC_MAIN("2/input")


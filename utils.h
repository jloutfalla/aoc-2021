#ifndef UTILS_H
#define UTILS_H

#include "fmmap/fmmap.h"
#include "vstr/vstr.h"

#define ERR_EXIT(msg, ...)                       \
  {                                              \
    fprintf(stderr, (msg), __VA_ARGS__);         \
    exit(EXIT_FAILURE);                          \
  }

#define AOC_MAIN(input)                                                 \
  int                                                                   \
  main()                                                                \
  {                                                                     \
    size_t content_size = 0;                                            \
    const char *str = get_file_content(&content_size, (input));         \
    vstr content = vstr_from_size_cstr(str, content_size);              \
                                                                        \
    part1(content);                                                     \
    part2(content);                                                     \
                                                                        \
    free((void *)str);                                                  \
    return 0;                                                           \
  }

const char *get_file_content(size_t *restrict content_size,
                             const char *restrict path);
int get_num(vstr *str);
#endif /* UTILS_H */

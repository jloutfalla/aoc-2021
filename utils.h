#ifndef UTILS_H
#define UTILS_H

#include "fmmap/fmmap.h"
#include "vstr/vstr.h"

#define ERR_EXIT(msg, ...)                       \
  {                                              \
    fprintf(stderr, (msg), __VA_ARGS__);         \
    exit(EXIT_FAILURE);                          \
  }

const char *get_file_content(size_t *restrict content_size,
                             const char *restrict path);

#endif /* UTILS_H */

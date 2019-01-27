#ifndef ALLOC_IN_HEAP_H
# define ALLOC_IN_HEAP_H

# include <unistd.h>
# include <sys/mman.h>
# include "../lib/ft_printf/inc/ft_printf.h"

typedef enum            e_zones_heap
{
  TINY,
  SMALL,
  LARGE
}                     t_heap_zones;

typedef struct          s_lst_block
{
  size_t                lenght;
  struct s_lst_block    *prev;
  struct s_lst_block    *next;
}                       t_lst_block;

typedef struct          s_heap
{
  t_lst_block           *free;
  t_lst_block           *booked;
}                       t_heap;

void    *malloc(size_t size);
void    *ft_malloc(size_t size);

#endif

#ifndef ALLOC_IN_HEAP_H
# define ALLOC_IN_HEAP_H

# include <unistd.h>
# include <sys/mman.h>
# include "../lib/ft_printf/inc/ft_printf.h"
# include "../lib/libft/inc/libft.h"

# define NB_BLOCKS 100
# define SIZE_TINY_BLK 257
# define SIZE_SMALL_BLK 2025
# define ZONES_TYPE 3

# define LIST_OK 0
# define LIST_EMPTY 1
# define LIST_NO_MEM 2
# define LIST_END 3
# define LIST_BEG 4

typedef enum            e_zones_heap
{
  TINY_BLK,
  SMALL_BLK,
  LARGE_BLK
}                     t_heap_zones;

typedef struct          s_element_block
{
  size_t                 size;
  struct s_element_block *prev;
  struct s_element_block *next;
  size_t                 free;
}                       t_element_block;

typedef struct          s_lst_block
{
  t_element_block         *start;
  t_element_block         *end;
  t_element_block         *ptr;
  t_element_block         *padding;
}                       t_lst_block;

t_lst_block g_heap[ZONES_TYPE];

void    *malloc(size_t size);
void		*realloc(void *ptr, size_t size);
void		free(void *ptr);
void    *ft_malloc(size_t size);


/* **
 * LIST
 * **/

int lst_init_block(t_lst_block *lst, size_t size);
int lst_put_post(t_lst_block *lst, size_t size, size_t zone_size);
void lst_fragment(t_lst_block *lst, size_t size, size_t zone_size);
int lst_move_ptr_left(t_lst_block *lst);
int lst_move_ptr_right(t_lst_block *lst);
int lst_is_empty(t_lst_block *plst);
#endif

#include "alloc_in_heap.h"

void			*realloc(void *ptr, size_t size)
{
    void *new_data;
	t_element_block *old_data;

    if (!ptr)
	{
		return (malloc(size));
	}
	old_data = (t_element_block *)(ptr) - 1;
	free(ptr);
	if (size <= old_data->size)
	{
		old_data->free = FALSE;
		return (ptr);
	}
	new_data = malloc(size);
	ft_memmove(new_data, ptr, old_data->size);
	return new_data;
}
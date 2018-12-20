#include "alloc_in_heap.h"

int     main(void)
{
  if (!malloc(10))
  { 
    return 1;
  }

   if (!malloc(10))
  { 
    return 1;
  }
  
  return (0);
}

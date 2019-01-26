#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int     main(void)
{
	write(1,"My mallock\n", 11);
	if (!malloc(10))
	{ 
		return 1;
	}
	write(1,"My mallock\n", 11);
	if (!malloc(100))
	{ 
		return 1;
	}
  
  return (0);
}

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "get_next_line.h"

int        main(void)
{
    char *res = 0;
    int fd = open("text.txt", O_RDONLY);
    int cont;
    while((cont = get_next_line(fd, &res)) > 0)
	{  
	   	printf("%i %s\n",cont, res);
   		free(res);
	}
	printf("%i %s\n",cont, res);
	free(res);
}

# get_next_line
GetNextLine.42

Reads a line on a file descriptor.

Return cases:

-1 : An error occurs : verify that you have entered good arguments (valid FD, openable file ...)
0 : All has been read.
1 : A line has been read

Compile and run the project :

Compile whole project : gcc -Wall -Wextra -Werror get_next_line.c get_next_line.h main.c
Run the project : ./a.out "your_file"

exemple for main:

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int  main(int argc, char **argv)
{
  char  *line = NULL;
  int   ret;
  int   fd = open(argv[1], O_RDONLY);

  while((ret = get_next_line(fd, &line) == 1))
  {
    printf("Line : %s\n", line);
    printf("Return value : %d\n\n", ret);
  }
  if (ret == -1)
    printf("an error has occurred");
  return (0);
}

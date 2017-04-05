#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# define BUF_SIZE 10
# include <string.h>
# include "libft/libft.h"

int		get_next_line(int fd, char **line);

#endif

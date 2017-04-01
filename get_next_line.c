#include "get_next_line.h"
#include <stdio.h>

int		get_next_line(const int fd, char **line)
{
	static	char *str;
	char	*buf;

	if (fd < 0)
		return (0);
	while(read(fd, buf, BUF_SIZE))
	{
		if (ft_strchr(buf, '\n'))
	}
}

int 	main(int ac, char **ag)
{
	int		buf_size = 1;
	char 	*buf = (char *)malloc(sizeof(char) * buf_size + 1);
	int fd = open(ag[1], O_RDONLY);
	ac = read(fd, buf, buf_size);
	buf[buf_size] = '\0';
	while(ac != 0)
	{
		printf("AC: %d\nBuf: %s\n", ac, buf);
		buf_size*=2;
		buf = (char *)malloc(sizeof(char) * buf_size + 1);
		buf[buf_size] = '\0';
		ac = read(fd, buf, buf_size);
	}
	return (0);
}

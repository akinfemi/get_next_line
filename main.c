#include "get_next_line.h"
#include <stdio.h>
int		get_next_line(const int fd, char **line);
int		main(int ac, char **ag)
{
	int		fd = open(ag[ac - 1], O_RDONLY);
	char	*res;
	int		ret;

	ret = 1;
	res = (char*)malloc(sizeof(char) * 1000);
	while (ret != 0)
	{
		ret = get_next_line(fd, &res);
		printf("Ret: %d\nRes: %s\n", ret, res);
		res = NULL;
	}
//		ret = get_next_line(42, &res);
//		printf("Ret: %d\nRes: %s\n", ret, res);

	return (0);
}

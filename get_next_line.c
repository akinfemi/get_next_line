#include "get_next_line.h"

void		init(char **str)
{
	*str = (char *)ft_memalloc(sizeof(char) * 1001);
}

char		*read_next(const int fd, int buf_size)
{
	int		rd;
	char	*temp;

	temp = (char *)ft_memalloc(sizeof(char) * BUF_SIZE + 1);
	rd = read(fd, temp, buf_size);
	if (rd > 0)
		return (temp);
	else
		return (0);
}

void		fill_line(char **line, char **str)
{
	size_t		len;
	char		*temp;

	temp = ft_strchr(*str, '\n');
	len = ft_strlen(*str) - ft_strlen(temp);
	*line = (char *)ft_memalloc(sizeof(char) * len + 1);
	*line = ft_strncpy(*line, *str, len);
	*str = temp+1;
}

int			get_next_line(const int fd, char **line)
{
	static char	*str = NULL;
	char	*nl;
	char	*temp;
   
	if (!str)
	{
		init(&str);
		temp = read_next(fd, BUF_SIZE);
		if (!temp)
			return (0);
		str = ft_strcpy(str, temp);
	}
	nl = ft_strchr(str, '\n');
	if (nl && *nl == '\n')
	{
		fill_line(line, &str);
		return (1);
	}
	if (nl == NULL)
	{
		temp = read_next(fd, BUF_SIZE);
		if (!temp)
			return (0);
		str = ft_strcat(str, temp);
		return (get_next_line(fd, line));
	}
	return (0);	
}

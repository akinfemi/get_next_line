/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakin-al <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 15:22:41 by aakin-al          #+#    #+#             */
/*   Updated: 2017/04/12 20:31:43 by aakin-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_gnl		*create_node(char *content, int fd)
{
	t_gnl	*node;

	node = (t_gnl *)malloc(sizeof(t_gnl));
	node->content = (char *)ft_memalloc(sizeof(char) * 100000);
	node->content = ft_strcpy(node->content, content);
	node->fd = fd;
	return (node);
}

void		lstadd(t_gnl **list, t_gnl *node)
{
	if (!node)
		return ;
	node->next = *list;
	*list = node;
}

t_gnl		*set_node(int fd, t_gnl **list)
{
	t_gnl	*node;

	node = *list;
	while (node)
	{
		if (node->fd == fd)
			return (node);
		node = node->next;
	}
	node = create_node("\0", fd);
	lstadd(list, node);
	return (node);
}

int			fill_line(char **line, char **str)
{
	size_t		len;
	char		*temp;

	temp = ft_strchr(*str, '\n');
	if (temp && *temp == '\n')
	{
		len = ft_strlen(*str) - ft_strlen(temp);
		*line = (char *)ft_memalloc(sizeof(char) * len + 1);
		*line = ft_strncpy(*line, *str, len);
		*str += len + 1;
	}
	else
	{
		*line = ft_strdup(*str);
		*str += ft_strlen(*str);
	}
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	static t_gnl	*list = NULL;
	t_gnl			*temp;
	char			*nl;
	char			str[BUFF_SIZE + 1];
	int				rd;

	if (fd < 0 || BUFF_SIZE <= 0 || read(fd, str, 0) < 0 || !line)
		return (-1);
	temp = set_node(fd, &list);
	while ((rd = read(fd, str, BUFF_SIZE)))
	{
		str[rd] = '\0';
		temp->content = ft_strcat(temp->content, str);
		ft_bzero(str, ft_strlen(str));
		if ((nl = ft_strchr(temp->content, '\n')))
		{
			fill_line(line, &(temp->content));
			return (1);
		}
	}
	if (ft_strlen(temp->content) > 0)
	{
		fill_line(line, &(temp->content));
		return (1);
	}
	free(temp);
	return (0);
}

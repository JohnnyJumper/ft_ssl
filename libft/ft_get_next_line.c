/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 22:23:49 by jtahirov          #+#    #+#             */
/*   Updated: 2017/12/04 22:43:17 by jtahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*find(t_list **store, int fd)
{
	t_list	*temp;

	temp = *store;
	while (temp)
	{
		if (temp->content_size == (size_t)fd)
			return (temp);
		temp = temp->next;
	}
	temp = (t_list*)ft_memalloc(sizeof(t_list));
	temp->content = ft_strnew(0);
	temp->content_size = fd;
	temp->next = NULL;
	ft_lstadd(store, temp);
	return (*store);
}

char			*linestore(char *content, char **line)
{
	int		i;
	char	*temp;

	i = 0;
	while (content[i] && content[i] != '\n')
		i++;
	free(*line);
	*line = ft_strnew(i);
	ft_memccpy(*line, content, '\n', (size_t)i);
	temp = content;
	content = ((size_t)i < ft_strlen(content))
		? ft_strdup(&content[i + 1])
		: ft_strnew(0);
	free(temp);
	return (content);
}

int				ft_get_next_line(int fd, char **line)
{
	static t_list	*store;
	t_list			*temp;
	char			*val;
	int				i;

	if (fd < 0 || !line || read(fd, *line, 0) < 0
			|| !(*line = ft_strnew(BUFF_SIZE)))
		return (-1);
	temp = find(&store, fd);
	while (!ft_strchr(temp->content, '\n') && (i = read(fd, *line, BUFF_SIZE)))
	{
		line[0][i] = 0;
		val = temp->content;
		temp->content = ft_strjoin(val, *line);
		free(val);
		if (ft_strchr(*line, '\n'))
			break ;
	}
	if (i == 0 && ft_strlen(temp->content) == 0)
		return (0);
	temp->content = linestore(temp->content, line);
	return (1);
}

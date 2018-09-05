/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klin <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 13:28:27 by klin              #+#    #+#             */
/*   Updated: 2018/01/11 14:32:14 by klin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** gnl->content_size   ==>  fd
*/

static t_list	*ft_newgnl(int fd)
{
	t_list			*gnl;

	if (!(gnl = (t_list *)malloc(sizeof(*gnl))))
		return (NULL);
	gnl->content_size = fd;
	gnl->content = ft_strnew(0);
	gnl->next = NULL;
	return (gnl);
}

static t_list	*ft_find_fd(t_list *lstgnl, int fd)
{
	t_list			*tmp;

	tmp = lstgnl;
	while (tmp)
	{
		if (tmp->content_size == (size_t)fd)
			break ;
		if (tmp->next == NULL)
			tmp->next = ft_newgnl(fd);
		tmp = tmp->next;
	}
	return (tmp);
}

static int		ft_find_n(t_list **gnl, char **line)
{
	char			*n;
	char			*tmp;

	if ((n = ft_strchr((*gnl)->content, '\n')))
	{
		*n = '\0';
		*line = ft_strdup((*gnl)->content);
		tmp = (*gnl)->content;
		(*gnl)->content = ft_strdup(n + 1);
		ft_strdel(&tmp);
		return (1);
	}
	return (0);
}

static int		ft_read_fd(t_list **gnl, char **line, int *ret)
{
	char			buff[BUFF_SIZE + 1];
	char			*tmp_join;
	char			*tmp_del;

	while (((*ret) = read((*gnl)->content_size, buff, BUFF_SIZE)) > 0)
	{
		buff[(*ret)] = '\0';
		tmp_join = ft_strjoin(((*gnl)->content), buff);
		if ((tmp_del = (*gnl)->content) != NULL)
			ft_strdel(&tmp_del);
		(*gnl)->content = tmp_join;
		if (ft_find_n(gnl, line))
			return (1);
	}
	return (0);
}

int				get_next_line(int const fd, char **line)
{
	static t_list	*lstgnl;
	t_list			*gnl;
	int				ret;

	if (!line || BUFF_SIZE < 1 || read(fd, NULL, 0) < 0)
		return (-1);
	if (!lstgnl)
		if (!(lstgnl = ft_newgnl(fd)))
			return (-1);
	gnl = ft_find_fd(lstgnl, fd);
	if (ft_read_fd(&gnl, line, &ret) == 1)
		return (1);
	if (ret < 0)
		return (-1);
	if (ft_strlen(gnl->content) == 0)
		return (0);
	if (ft_find_n(&gnl, line) == 1)
		return (1);
	else
	{
		*line = ft_strdup(gnl->content);
		ft_strclr(gnl->content);
	}
	return (1);
}

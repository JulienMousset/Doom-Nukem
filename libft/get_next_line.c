/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmousset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 11:40:16 by jmousset          #+#    #+#             */
/*   Updated: 2019/08/26 10:48:44 by jmousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_read_line(int fd, char *str)
{
	int		ret;
	char	buf[BUFF_SIZE + 1];
	char	*tmp;

	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		tmp = str;
		str = ft_strjoin(str, buf);
		ft_memdel((void **)&tmp);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (str);
}

void	ft_save_line(char **str, char **line)
{
	size_t	i;
	char	*tmp;

	i = 0;
	tmp = NULL;
	while ((*str)[i] != '\n' && (*str)[i] != '\0')
		i++;
	if ((*str)[i] == '\n')
	{
		*line = ft_strsub(*str, 0, i);
		tmp = ft_strdup(&(*str)[i + 1]);
		free(*str);
		*str = tmp;
	}
	else if ((*str)[i] == '\0')
	{
		*line = ft_strdup(*str);
		ft_memdel((void **)str);
	}
}

int		get_next_line(const int fd, char **line)
{
	static char	*res[MAX_FD];

	if (fd < 0 || line == NULL || read(fd, 0, 0) == -1 || fd > MAX_FD)
		return (-1);
	if (!res[fd])
		res[fd] = ft_strnew(0);
	if (!(res[fd] = ft_read_line(fd, res[fd])))
		return (-1);
	ft_save_line(&res[fd], line);
	if (!res[fd] && **line == '\0')
	{
		free(*line);
		*line = NULL;
		return (0);
	}
	return (1);
}

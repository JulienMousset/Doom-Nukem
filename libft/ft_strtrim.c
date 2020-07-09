/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmousset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 13:55:21 by jmousset          #+#    #+#             */
/*   Updated: 2019/04/26 14:37:01 by jmousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_start(char const *s)
{
	int		i;

	i = 0;
	while ((s[i]) && (s[i] == ' ' || s[i] == '\t' || s[i] == '\n'))
		i++;
	return (i);
}

static int	ft_end(char const *s)
{
	int		i;
	int		j;

	i = ft_strlen(s) - 1;
	j = 0;
	while ((s[i]) && (s[i] == ' ' || s[i] == '\t' || s[i] == '\n'))
	{
		i--;
		j++;
	}
	return (j);
}

char		*ft_strtrim(char const *s)
{
	size_t	size;
	char	*res;

	if (s == NULL)
		return (NULL);
	if (s[ft_start(s)] == '\0')
	{
		res = (char*)malloc(sizeof(char));
		res[0] = '\0';
		return (res);
	}
	size = ft_strlen(s) - (ft_start(s) + ft_end(s));
	if (!(res = (char *)malloc(sizeof(char) * (size + 1))) || s == NULL)
		return (NULL);
	res = ft_strsub(s, ft_start(s), size);
	res[size] = '\0';
	return (res);
}

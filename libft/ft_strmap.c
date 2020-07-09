/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmousset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 13:49:30 by jmousset          #+#    #+#             */
/*   Updated: 2019/04/23 14:24:15 by jmousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	i;
	char	*res;

	i = 0;
	if (s != NULL && f != NULL)
	{
		if (!(res = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1))))
			return (NULL);
		while (i < ft_strlen(s))
		{
			res[i] = f(s[i]);
			i++;
		}
		res[i] = '\0';
		return (res);
	}
	else
		return (NULL);
}

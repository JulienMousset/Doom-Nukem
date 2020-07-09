/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmousset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 13:50:24 by jmousset          #+#    #+#             */
/*   Updated: 2019/04/23 15:09:56 by jmousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
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
			res[i] = f(i, s[i]);
			i++;
		}
		res[i] = '\0';
		return (res);
	}
	else
		return (NULL);
}

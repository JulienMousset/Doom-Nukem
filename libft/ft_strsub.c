/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmousset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 13:53:26 by jmousset          #+#    #+#             */
/*   Updated: 2019/04/26 14:33:57 by jmousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*res;

	i = 0;
	if (s != NULL)
	{
		if (!(res = (char *)malloc(len + 1)))
			return (NULL);
		while (i < len)
		{
			res[i] = s[start];
			i++;
			start++;
		}
		res[i] = '\0';
		return (res);
	}
	else
		return (NULL);
}

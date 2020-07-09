/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmousset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 12:16:50 by jmousset          #+#    #+#             */
/*   Updated: 2019/04/22 10:32:49 by jmousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t				i;
	unsigned char		*res;
	const unsigned char	*send;

	i = 0;
	res = dst;
	send = src;
	while (i < n)
	{
		res[i] = send[i];
		dst++;
		if (send[i] == (unsigned char)c)
			return (dst);
		i++;
	}
	return (NULL);
}

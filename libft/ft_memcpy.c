/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmousset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 12:15:10 by jmousset          #+#    #+#             */
/*   Updated: 2019/04/22 10:38:28 by jmousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
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
		i++;
	}
	return (dst);
}

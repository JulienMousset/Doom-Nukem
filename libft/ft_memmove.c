/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmousset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 12:17:56 by jmousset          #+#    #+#             */
/*   Updated: 2019/04/29 15:00:37 by jmousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	i = 0;
	if ((char *)src < (char *)dst)
		while (len--)
			*((char *)dst + len) = *((char*)src + len);
	else
		while (i < len)
		{
			*((char *)dst + i) = *((char *)src + i);
			i++;
		}
	return (dst);
}

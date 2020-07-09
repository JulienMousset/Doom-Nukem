/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmousset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 16:17:20 by jmousset          #+#    #+#             */
/*   Updated: 2019/04/29 16:44:46 by jmousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	length;

	if (!dest && !src)
		return (0);
	i = 0;
	length = 0;
	while (src[i] && i < (size - 1))
	{
		dest[i] = src[i];
		i++;
		length++;
	}
	while (src[length])
		length++;
	dest[i] = '\0';
	return (length);
}

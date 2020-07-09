/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmousset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 13:56:39 by jmousset          #+#    #+#             */
/*   Updated: 2019/04/26 18:34:29 by jmousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_intlen(int n)
{
	int				len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		len++;
	while (n)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

char			*ft_itoa(int n)
{
	unsigned int	len;
	char			*res;
	unsigned int	ncpy;

	len = ft_intlen(n);
	if (!(res = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	if (n == 0)
		res[0] = '0';
	res[len] = '\0';
	if (n < 0)
	{
		res[0] = '-';
		ncpy = -n;
	}
	else
		ncpy = n;
	while (ncpy)
	{
		len--;
		res[len] = ncpy % 10 + '0';
		ncpy = ncpy / 10;
	}
	return (res);
}

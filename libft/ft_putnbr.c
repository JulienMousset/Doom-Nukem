/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmousset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 17:27:12 by jmousset          #+#    #+#             */
/*   Updated: 2019/04/08 17:37:39 by jmousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	unsigned int	ncpy;

	if (n < 0)
	{
		ft_putchar('-');
		ncpy = n * -1;
	}
	else
		ncpy = n;
	if (ncpy >= 10)
		ft_putnbr(ncpy / 10);
	ft_putchar(ncpy % 10 + 48);
}

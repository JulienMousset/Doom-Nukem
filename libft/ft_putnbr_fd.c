/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmousset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 13:59:24 by jmousset          #+#    #+#             */
/*   Updated: 2019/04/10 16:28:33 by jmousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	ncpy;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		ncpy = n * -1;
	}
	else
		ncpy = n;
	if (ncpy >= 10)
		ft_putnbr_fd(ncpy / 10, fd);
	ft_putchar_fd(ncpy % 10 + 48, fd);
}

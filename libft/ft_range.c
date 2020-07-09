/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmousset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 16:08:19 by jmousset          #+#    #+#             */
/*   Updated: 2019/04/29 16:11:22 by jmousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		*ft_range(int min, int max)
{
	int		*tab;
	int		i;

	i = 0;
	if (min >= max)
		return (NULL);
	if (!(tab = malloc(sizeof(int) * (max - min))))
		return (NULL);
	while (i < max - min)
	{
		tab[i] = min + i;
		i++;
	}
	return (tab);
}

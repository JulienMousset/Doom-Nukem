/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmousset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 15:32:33 by jmousset          #+#    #+#             */
/*   Updated: 2020/05/30 16:20:47 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

int		main(int ac, char **av)
{
	if (ac == 3 && !ft_strcmp(av[1], "--editor"))
		doom_editor(av[2]);
	else if (ac != 2 && ac != 1)
		end(ERR_USAGE);
	else
		(ac == 2 ? doom_nukem(av[1], 1) : doom_nukem(PATH_LEVEL_1, 0));
}

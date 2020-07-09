/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ticks_manag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 14:40:53 by pasosa-s          #+#    #+#             */
/*   Updated: 2020/03/05 18:31:26 by pasosa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

void	ticks_init(Uint32 *ticks)
{
	if (*ticks == 0)
		*ticks = SDL_GetTicks();
}

int		ticks_passed(Uint32 *ticks, double sec)
{
	return (SDL_TICKS_PASSED(SDL_GetTicks(), *ticks + INTERVAL * sec));
}

void	ticks_reset(Uint32 *ticks)
{
	*ticks = SDL_GetTicks();
}

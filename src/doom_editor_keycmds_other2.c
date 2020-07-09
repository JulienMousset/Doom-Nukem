/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doom_editor_keycmds_other2.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 19:58:35 by julien            #+#    #+#             */
/*   Updated: 2020/06/03 19:59:01 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

int		e_mapcheck_isblock(int block_id)
{
	return (block_id < '1' || block_id > '9');
}

void	display_info(t_env *e, int texindex)
{
	e->ed.info_texindex = texindex;
	e->ed.info_opacity = 255;
}

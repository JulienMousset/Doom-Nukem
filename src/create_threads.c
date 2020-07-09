/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 20:07:48 by pasosa-s          #+#    #+#             */
/*   Updated: 2020/06/03 20:48:52 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

void	free_threads(t_thread *t)
{
	int		i;

	i = -1;
	while (++i < THREADS)
		t[i].env = NULL;
	ft_memdel((void **)&(t));
}

void	set_thread_values(t_thread *t, t_env *env, int i)
{
	t->x_start = env->w * i / THREADS;
	t->x_end = env->w * (i + 1) / THREADS;
	t->saved = 0;
	t->skip = 0;
	t->glass_hit = 0;
}

void	create_threads(t_env *env, int id)
{
	t_thread	*t;
	int			i;

	i = -1;
	if (!(t = (t_thread *)malloc(sizeof(t_thread) * THREADS)))
		exit_program(env, ERR_MALLOC);
	while (++i < THREADS)
	{
		t[i].env = env;
		t[i].n = i;
		if (id == 1)
		{
			set_thread_values(&t[i], env, i);
			pthread_create(&t[i].t, NULL, ray_casting, &t[i]);
		}
		else if (id == 2)
			pthread_create(&t[i].t, NULL, horizontal_loop, &t[i]);
	}
	i = -1;
	while (++i < THREADS)
		pthread_join(t[i].t, NULL);
	free_threads(t);
}

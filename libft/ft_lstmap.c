/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmousset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 14:07:08 by jmousset          #+#    #+#             */
/*   Updated: 2019/04/29 15:25:16 by jmousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *tmp;
	t_list *res;

	if (lst)
	{
		tmp = f(lst);
		res = tmp;
		lst = lst->next;
		while (lst)
		{
			tmp->next = f(lst);
			lst = lst->next;
			tmp = tmp->next;
		}
		return (res);
	}
	return (NULL);
}

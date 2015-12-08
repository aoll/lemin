/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_choose.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aollivie <aollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 08:25:44 by aollivie          #+#    #+#             */
/*   Updated: 2015/12/02 13:54:40 by aollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lemin.h"

int		ft_sement(t_way *way, char *s)
{
	while (way)
	{
		if (ft_strcmp(way->name, s) == 1)
			return (1);
		way = way->next;
	}
	return (0);
}

int		ft_croi(t_way *way, t_way *w)
{
	way = way->next;
	while (way->next)
	{
		if (ft_sement(w, way->name) == 1)
			return (1);
		way = way->next;
	}
	return (0);
}

t_way		*ft_getshort(t_way *w)
{
	t_way *n;

	n = malloc(sizeof(t_way));
	n = w;
	while (w)
	{
		if (w->size < n->size)
			n = w;
		w = w->list;
	}
	n->list = NULL;
	return (n);
}

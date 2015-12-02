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

#include "lemin.h"

static int		ft_nb(t_tree *t)
{
	int nb;

	nb = 0;
	while (t->list[nb])
	{
		nb++;
	}
	return (nb);
}

static int		ft_size(t_way *w)
{
	int nb;

	nb = 0;
	while (w)
	{
		nb++;
		w = w->next;
	}
	return (nb);
}

void	ft_sizeWay(t_way **way)
{
	t_way *w;
	int nb;

	nb = -1;
	w = *way;
	while (w)
	{
		w->index = ++nb;
		w->size = ft_size(w);
		w = w->list;
	}
}

static int		ft_sement(t_way *way, char *s)
{
	while (way)
	{
		printf("CMP1: %s, CMP2: %s\n", way->name, s); 
		if (ft_strcmp(way->name, s) == 1)
			return (1);
		way = way->next;
	}
	return (0);
}

static int		ft_croi(t_way *way, t_way *w)
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
/*
static int		ft_inter(t_way *way, t_way *w)
{
	while (way)
	{
		if (ft_croi(way, w) == 1)
			return (1);
		way = way->list;
	}
	return (0);
}
*/
static t_way	*ft_getShort(t_way *w)
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

static void		ft_init(t_way *way, int nb)
{
	t_way *w;

	printf("TEST CROISEMENT: %d\n", ft_croi(way, way->list));
	w = ft_getShort(way);
	
	printWay(w);
}

void	ft_choose(t_way *way, t_tree *tree)
{
	t_way **w;

	printf("NB WAY: %d\n", ft_nb(ft_getTreeEnd(tree)));
	ft_sizeWay(&way);
	ft_init(way, ft_nb(ft_getTreeEnd(tree)));
	//*w = way;
//	printWay(way);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_choose.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aollivie <aollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 08:25:44 by aollivie          #+#    #+#             */
/*   Updated: 2016/01/27 17:32:19 by aollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lemin.h"

static int		ft_nb(t_tree *t)
{
	int nb;

	nb = 0;
	while (t->list[nb])
		nb++;
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

static	void		ft_sizeway(t_way **way)
{
	t_way	*w;
	int	nb;

	nb = -1;
	w = *way;
	while (w)
	{
		w->index = ++nb;
		w->size = ft_size(w);
		w = w->list;
	}
	return ;
}

static t_way		*ft_init(t_way *way, int nb)
{
		t_way *w;

		w = ft_getshort(way);
		if (!w)
			ft_putstr("ERROR\n"); // peut etre a checker a un autre endroit
		return (w);
		//printWay(w);
}

t_way			*ft_choose(t_way *way, t_tree *tree)
{
	t_way *w;
	
	ft_sizeway(&way);
	return (ft_init(way, ft_nb(ft_getTreeEnd(tree))));	
}

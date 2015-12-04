#include "lemin.h"

static t_way		*ft_cp(t_che *che)
{
	t_way *n;

	n = ft_newway(che->name);
	che = che->fa;
	while (che)
	{
		ft_addway(&n, ft_newway(che->name));
		che = che->fa;
	}
	return (n);
}

static void		ft_init(t_way **way, t_che *che)
{
	t_way *t;

	t = *way;
	if (t == NULL)
	{
		*way = ft_cp(che);
	}
	else
		ft_addlist(way, ft_cp(che));
}

static void		print(t_way **way, t_che *che, char *s)
{
	while (che)
	{
		if (che->fin == 1)
		{
			ft_init(way, che);
		}
		che = che->next;
	}
}

static void		ft_while(t_way **way, t_che *che)
{
	print(way, che->list, che->name);
	while (che->list)
	{
		ft_while(way, che->list);
		che->list = che->list->next;
	}
}

void			ft_way(t_way **way, t_che *che, t_tree *tree)
{
	ft_while(way, che);
}

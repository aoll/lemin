#include "lemin.h"

t_road		*ft_roadNew(int *size, char *src)
{
	t_road		*new;
	char		**tab;

	tab = ft_strsplit(src, '-');
	new = malloc(sizeof(t_road));
	new->next = NULL;
	new->prev = NULL;
	new->use = false;
	new->in = ft_strdup(tab[0]);
	new->out = ft_strdup(tab[1]);
	new->size = malloc(sizeof(int));
	new->size = size;
	return (new);
}

void		ft_roadAdd(t_road **road, t_road *new)
{
	t_road		*tmp;

	tmp = *road;
	while (tmp->next)
		tmp = tmp->next;
	*new->size = *new->size + 1;
	tmp->next = new;
	new->prev = tmp;
}

void		ft_road(t_road **road, char *src)
{
	int			*size;
	t_road			*new;
	t_road			*tmp;

	tmp = *road;
	if (*road == NULL)
	{
		size = malloc(sizeof(int));
		*size = 1;
		new = ft_roadNew(size, src);
		*road = new;
		return ;
	}
	else
		ft_roadAdd(road, ft_roadNew(tmp->size, src));
}

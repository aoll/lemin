#include "../lemin.h"

void	ft_treeRoadPrint(t_tree *tmp)
{
  int nb;

  while (tmp)
    {
      nb = 0;
      printf("<name ===> %s>\n",tmp->name);
      while (tmp->list[nb])
	{
	  printf("<route: %s>\n",tmp->list[nb]);
	  nb++;
	}
      tmp = tmp->next;
    }
}

int		ft_nb_way(t_road *road, char *name)
{
	int nb;

	nb = 0;
	while (road)
	{
		if (ft_strcmp(name, road->in) == 1 || ft_strcmp(name, road->out) == 1)
			nb++;
		road = road->next;
	}
	return (nb);
}

void		ft_treeroadinit(t_tree **tree, t_road *road)
{
	t_tree	*tmp;
	int	nb;
	int	i;

	i = 0;
	tmp = *tree;
	nb = ft_nb_way(road, tmp->name);
	if (!(tmp->list = malloc(sizeof(char *) * nb + 1)))
		return ;
	tmp->list[nb] = NULL;
	nb = 0;
	while (road)
	{
		if (ft_strcmp(road->in, tmp->name) == 1)
		{
			tmp->list[nb] = ft_strdup(road->out);
			nb++;
		}
		else if (ft_strcmp(road->out, tmp->name) == 1)
		{
			tmp->list[nb] = ft_strdup(road->in);
			nb++;
		}
		road = road->next;
	}
}

void		ft_treeroad(t_tree **tree, t_road *road)
{
	t_tree *tmp;
	t_tree *tmp2;

	tmp = *tree;
	while (tmp)
	{
		ft_treeroadinit(&tmp, road);
		tmp = tmp->next;
	}
}

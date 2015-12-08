#include "../lemin.h"

void		ft_cpWay(t_che **che, t_tree *tree)
{
	t_che	*tmp;
	t_che	*new;
	int	nb;
	t_tree	*tampon;

	nb = 0;
	tmp = *che;
	tmp->check = 1;
	tampon = malloc(sizeof(t_tree));
	while (tree->list[nb])
	  {     
		tampon = ft_getTree(tree, tree->list[nb]);
		if (tampon->end != true && ft_checkFa(tmp, tree->list[nb]) != 1)
		{
			new = ft_newChe(tmp->poids + 1);
			new->name = ft_strdup(tree->list[nb]);
			new->fa = *che;
			ft_addChe(&tmp->list, new);
		}
		nb++;
	}
}

void		ft_cpChe(t_che **che, t_tree *tree)
{
	t_che *tmp;

	tmp = *che;
	tmp->name = ft_strdup(tree->name);
}

t_che		*ft_newChe(int poids)
{
	t_che *che;
 
	if(!(che = malloc(sizeof(t_che))))
		return (NULL);
	che->poids = poids;
	che->name = ft_strnew(0);
	che->next = NULL;
	che->prev = NULL;
	che->list = NULL;
	che->fa = NULL;
	che->check = 0;
	che->fin = 0;
	return (che);
}

void		ft_firstChe(t_che **che, t_tree *tree)
{
	t_che *new;

	new = ft_newChe(0);
	ft_cpChe(&new, ft_getTreeEnd(tree));
	ft_cpWay(&new, ft_getTreeEnd(tree));
	*che = new;
}

void		ft_nextChe(t_che **che, t_tree *tree)
{
	t_che	*tmp;
	t_tree	*tampon;
	t_tree	*buff;

	tmp = *che;
	if (tmp->list)
		tmp = tmp->list;
	else
		return ;
	tampon = malloc(sizeof(t_tree));
	buff = malloc(sizeof(t_tree));
	buff = ft_getTreeEnd(tree);
	if (ft_strcmp(tmp->name, buff->name) == 1)
		return ;
	buff = ft_getTreeStart(tree);
	if (ft_strcmp(tmp->name, buff->name) == 1)
		return ;
	while (tmp)
	{
		tampon = ft_getTree(tree, tmp->name);
		if (ft_strcmp(tmp->name, buff->name) != 1)
			ft_cpWay(&tmp,tampon);
		tmp = tmp->next;
	}
}

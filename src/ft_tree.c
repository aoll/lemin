#include "../lemin.h"

t_tree		*ft_treeNew(int *size, t_list *src)
{
	t_tree	*new;
	char	**tab;

	tab = ft_strsplit(src->name, ' ');
	new = malloc(sizeof(t_tree));
	new->next = NULL;
	new->tab = NULL;
	new->name = ft_strdup(tab[0]);
	new->x = ft_atoi(tab[1]);
	new->y = ft_atoi(tab[2]);
	new->size = malloc(sizeof(int));
	new->size = size;
	return (new);
}

void		ft_treeAdd(t_tree **tree, t_tree *new)
{
	t_tree	*tmp;

	tmp = *tree;
	while (tmp->next)
		tmp = tmp->next;
	*new->size = *new->size + 1;
	tmp->next = new;
	new->prev = tmp;
}

void		ft_tree(t_tree **tree, t_list *src)
{
	t_tree	*new;
	t_tree	*tmp;
	int	*n;

	tmp = *tree;
	if (tmp == NULL)
	{
		n = malloc(sizeof(int));
		*n = 0;
		new = ft_treeNew(n, src);
		*n = *n + 1;
		*tree = new;
		return ;
	}
	else
		ft_treeAdd(tree, ft_treeNew(tmp->size, src));
}

#include "../lemin.h"

t_tree		*ft_getTree(t_tree *tree, char *nameTarget)
{
	while (tree->prev)
		tree = tree->prev;
	while (tree)
	{
		if (ft_strcmp(tree->name, nameTarget) == 1)
			return (tree);
		tree = tree->next;
	}
	return (NULL);
}

t_tree		*ft_getTreeEnd(t_tree *tree)
{
	while (tree->prev)
		tree = tree->prev;
	while (tree)
	{
		if (tree->end == true)
			return (tree);
		tree = tree->next;
	}
	return (NULL);
}

t_tree		*ft_getTreeStart(t_tree *tree)
{
	while (tree->prev)
		tree = tree->prev;
	while (tree)
	{
		if (tree->start == true)
			return (tree);
		tree = tree->next;
	}
	return (NULL);
}

void		ft_addChe(t_che **che, t_che *new)
{
	t_che *tmp;

	if (*che == NULL)
	{
		*che = new;
		return ;
	}
	tmp = *che;
	while (tmp->next)
		tmp = tmp->next;
	new->prev = tmp;
	tmp->next = new;
}

int		ft_checkFa(t_che *che, char *s)
{
	while (che)
	{
		if (ft_strcmp(che->name, s) == 1)
			return (1);
		che = che->fa;
	}
	return (0);
}

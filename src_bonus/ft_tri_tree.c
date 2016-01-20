#include "../lemin.h"

t_tree	*ft_new_tri(void)
{
	t_tree *n;

	if (!(n = malloc(sizeof(t_tree))))
		return (NULL);
	n->name = ft_strnew(0);
	n->next = NULL;
	n->prev = NULL;
	n->ant = 0;
	n->test = 0;
	n->start = false;
	n->end = false;
	return (n);
}

void	ft_tri_add(t_tree **tree, t_tree *n)
{
	t_tree *t;

	t = *tree;
	while (t->next)
	{
		t = t->next;
	}
	t->next = n;
	n->prev = t;
	return;
}

void	ft_init_new(t_tree **tree, char *s)
{
	t_tree *t;

	t = ft_new_tri();
	if (*tree == NULL)
	{
		t->name = ft_strdup(s);
		*tree = t;
	}
	else
	{
		t = ft_new_tri();
		t->name = ft_strdup(s);
		ft_tri_add(tree, t);
	}
	return;
}

void	ft_init_tri(t_tree **tree, char *s)
{
	char **tab;
	int x;

	x = 0;
	tab = ft_strsplit(s, '-');
	while (tab[x])
	{
		if (ft_strcmp(tab[x], "L1") == 1)
		{
			ft_init_new(tree, tab[x + 1]);
		}
		x++;
	}
	return;
}

void	ft_tri(t_tree **t, char *s)
{
	char **tab;
	int x;

	x = 0;
	tab = ft_strsplit(s, ' ');
	while (tab[x])
	{
		ft_init_tri(t, tab[x]);
		x++;
	}
	return;
}

t_tree	*ft_tri_tree(t_list *l)
{
	t_tree *t;

	t = NULL;
	while (l)
	{
		ft_tri(&t, l->name);
		l = l->next;
	}
	return (t);
}

#include "../lemin.h"

void		ft_cheIni(t_che **che, t_tree *tree)
{
	t_che	*t;
	t_tree	*tmp;

	t = *che;
	tmp = malloc(sizeof(t_tree));
	ft_nextChe(&t, tree);
	if (t->list == NULL)
		return ;
	t = t->list;
	while (t)
	{
		tmp = ft_getTree(tree, t->name);
		if (tmp->start == false)
			ft_cheIni(&t, tree);
		else
		{
			t->check = 1;
			t->fin = 1;
		}
		t = t->next;
	}
}

static void	ft_noCheck(t_che **che1, t_tree *tree, t_tree *name)
{
	t_che *che;

	che = *che1;
	while (che)
	{
		if (ft_strcmp(name->name, che->name) == 1)
		{
			che->check = 1;
			che->fin = 1;
		}
		if (che->check != 1)
			ft_cheIni(&che, tree);
		che = che->next;
	}
}

static void	ft_while(t_che **che1, t_tree *tree)
{
	t_che *che;

	che = *che1;
	if (che->list == NULL)
		return ;
	che = che->list;
	ft_noCheck(&che->list, tree, ft_getTreeStart(tree));
	while (che)
	{
		ft_while(&che, tree);
		che = che->next;
	}
}

void		ft_che(t_che **che, t_tree *tree)
{
	t_che *t;
  
	ft_firstChe(che, tree);
	ft_cheIni(che, tree);
	t = *che;
}

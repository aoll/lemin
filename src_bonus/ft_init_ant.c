#include "../lemin.h"

void	ft_add_ant(t_ant **ant, t_ant *n)
{
	t_ant *a;

	a = *ant;
	while (a->next)
	{
		a = a->next;
	}
	a->next = n;
	return;
}


t_ant	*ft_new_ant(char *s)
{
	t_ant *t;

	if (!(t = malloc(sizeof(t_ant))))
		return (NULL);
	t->next = NULL;
	t->name = ft_strdup(s);
	return (t);
}

void	ft_init_bis()
{
	
	return;
}

void	ft_init_ant(t_ant **ant, t_list *list)
{
	t_ant *a;

	a = *ant;
	if (a == NULL)
	return;
}

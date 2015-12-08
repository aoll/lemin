#include "../lemin.h"

static void		pw(t_way *w)
{
  printf("NEW WAY\n"); //
  while (w)
    {
		printf("NAME: %s, INDEX: %d, SIZE: %d\n", w->name, w->index, w->size);
      w = w->next;
    }
}

void			printWay(t_way *w)
{
  while (w)
    {
      pw(w);
      w = w->list;
    }
}

void			ft_addlist(t_way **w, t_way *n)
{
	t_way *t;

	t = *w;
	if (t->list == NULL)
	{
		t->list = n;
		return ;
	}
	t = t->list;
	while (t->list)
	{
		t = t->list;
	}
	t->list = n;
}

void			ft_addway(t_way **w, t_way *n)
{
	t_way *t;

	t = *w;
	while (t->next)
	{
		t = t->next;
	}
	t->next = n;
	n->prev = t;
}

t_way			*ft_newway(char *s)
{
	t_way *new;

	new = malloc(sizeof(t_way));
	new->index = 0;
	new->size = 1;
	new->check = 0;
	new->name = ft_strdup(s);
	new->next = NULL;
	new->prev = NULL;
	new->list = NULL;
	new->f = NULL;
	return (new);
}

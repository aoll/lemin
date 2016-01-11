#include "../lemin.h"

void	ft_last(t_way **w)
{
	t_way *tmp;

        tmp = *w;
	while (tmp->next)
	{
		tmp = tmp->next;
	}
	*w = tmp;
	return;
}

int	ft_ck_ant(t_way *w)
{
	w = w->prev;
	while (w->prev)
	{
		if (w->ant > 0)
			return (1);
		w = w->prev;
	}
	return (0);
}

void	ft_print_name_and_room(t_way *w, int ant)
{
	ft_putstr("L");
	ft_putnbr(ant);
	ft_putstr("-");
	ft_putstr(w->name);
	//ft_putchar(' ');
	return;
}

void	ft_ant_prev(t_way **way, int ant)
{
	t_way *w;
	int cr;

	cr = 0;
	w = *way;
	if (w->prev == NULL)
		return;
	while (w->prev)
	{
		if (w->prev->ant > 0)
		{
			if (cr > 0)
				ft_putchar(' ');
			ft_print_name_and_room(w, w->prev->ant);
			w->ant = w->prev->ant;
			w->prev->ant = 0;
			cr++;
		}
		w = w->prev;
	}
	w->ant = ant;
	return;
}

void	ft_print_ant(t_way *way, int nb_ant)
{
	int cr;

	cr = 1;
	ft_last(&way);
	while (cr <= nb_ant)
	{
		ft_ant_prev(&way, cr++);
		ft_putchar('\n');
	}
	while (ft_ck_ant(way) == 1)
	{
		ft_ant_prev(&way, 0);
		ft_putchar('\n');
	}
	return;
}

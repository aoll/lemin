
#include "../lemin.h"

int	ft_ck_term(int term_y, int term_x)
{
	if (term_y < 20 || term_x < 50)
	{
		return (1);
	}
	return (0);
}

int	ft_tree_cmp(char *s, t_tree *t)
{
	while (t)
	{
		if (ft_strcmp(s, t->name) == 1)
			if (t->ant == 1)
				return (1);
		t = t->next;
	}
	return (0);
}

void	ft_print_room(t_tree *t, t_tree *tree, int ck)
{
	
	while (tree)
	{
		if (ft_tree_cmp(tree->name, t) == 1 && ck)
		{
  	       		mvprintw(tree->y, tree->x, "A");
		}
		else
			mvprintw(tree->y, tree->x, "#");
		tree = tree->next;
		//sleep(1);
	}
	sleep(1);
	refresh();
	return;
}

void	ft_select_room(t_tree **tt, t_tree *tree, char *s)
{
	t_tree *t;
	char **tab;

	tab = ft_strsplit(s, '-');
	t = *tt;
	while (t)
	{
		if (ft_strcmp(t->name, tab[1]) == 1)
		{
			t->ant = 1;
			if (t->prev)
				t->prev->ant = 0;
			break;
		}
		t = t->next;
	}
	t = *tt;
       	ft_print_room(t, tree, 1);
	while (t->next)
	{
		t = t->next;
	}
	t->ant = 0;
	return;
}

void	ft_ant_room(t_tree **t, t_tree *tree, t_list *l)
{
	char **tab;
	int x;

	x = 0;
	tab = ft_strsplit(l->name, ' ');
	while (tab[x])
	{
		ft_select_room(t, tree, tab[x]);
		x++;
	}
	return;
}


void	ft_ncurse_init(t_tree *tree, t_list *list, int ant)
{
	int term_y;
	int term_x;
	t_tree *t;

	t = ft_tri_tree(list);
	initscr();        //init terminal
	curs_set(0);      //enlever cursor
       	cbreak();
	nodelay(stdscr, true);     //getch non-bloquant
	keypad(stdscr, true);//KEY_LEFT
	getmaxyx(stdscr, term_y, term_x);  //get termsize
	if (ft_ck_term(term_y, term_x) == 1)
	{
		ft_putstr("ERROR: WINDOW TOO SMALL\n");
		return;
	}
	ft_print_room(t, tree, 0);
	while (list)
	{
		ft_ant_room(&t, tree, list);
		list = list->next;
	}
	ft_print_room(t, tree, 0);
	sleep(1);
	endwin();
	return;
}

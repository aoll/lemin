/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aollivie <aollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/31 20:39:18 by aollivie          #+#    #+#             */
/*   Updated: 2015/12/02 15:15:38 by aollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../lemin.h"

static int     ft_nb_ant(t_list *list)
{
        while (list)
                {
                        if (list->name[0] == '#')
                                list = list->next;
                        else
                                return (ft_atoi(list->name));
                }
        return (0);
}

int	ft_ck_x_y(t_tree **tree)
{
	t_tree *t;

	t = *tree;
	while (t)
	{
		if (t->x > 140 || t->y > 30)
			return (1);
		
		t->y = t->y + 5;
		t->ant = 0;
		t = t->next;
	}
	return (0);
}

int	main(int ac, char **av)
{	
	t_list *list;
	t_list *list_b;
	int fd;
	int rd;
	char *line;
	t_tree *tree;
	int nb_ant;

	tree = NULL;
	list = NULL;
	list_b = NULL;
	ac = 0;
	fd = 0;
	//printf("%s\n", "START BONUS");
	
	while ((rd = get_next_line(fd, &line)) > 0)
		{
			if (ft_strcmp(line, "ERROR") == 1)
				return (0);
			if (line[0] == 'L')
				++ac;
			if (ac == 0)
				ft_list(&list, line);
			else
				ft_list(&list_b, line);
			//printf("%s\n", line);
		}
	ft_treeinit(&tree, list);
	nb_ant = ft_nb_ant(list);
	
	if (ft_ck_x_y(&tree))
	{
		ft_putstr("ERROR: WINDOW TOO SMALL");
		return (0);
	}
	/*
	while (tree)
	{
		printf("name == %s, x == %d, y == %d\n ", tree->name, tree->x, tree->y);
		tree = tree->next;
		}
*/
	ft_ncurse_init(tree, list_b, 8);
		/*	
	while (list_b)
		{
			printf("%s\n", list_b->name);
			list_b = list_b->next;
		}
		printf("%s\n", "----------------------");
		while (tree)
		{
			printf("%s\n", tree->name);
			tree = tree->next;
		}
		*/
	return (0);
}

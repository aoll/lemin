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
//#include "libft/libft.h"

int	ft_nb_ant(t_list *list)
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

int	ft_start_end(t_list *list)
{
	int	start;
	int	end;

	start = 0;
	end = 0;
	while (list)
	{
		if (ft_strcmp(list->name, "##start") == 1)
			start++;
		if (ft_strcmp(list->name, "##end") == 1)
			end++;
		list = list->next;
	}
	if (start != 1 || end != 1)
		return (1);
	return (0);
}

void	ft_list_print(t_list *list)
{
	if (list == NULL)
		return;
	ft_putstr(list->name);
	ft_putchar('\n');
	ft_list_print(list->next);
	return;
}

int	main(int ac, char **av)
{
  t_list *list;
  t_tree *tree;
  int fd;
  int rd;
  char *line;
  t_road *road;
  t_way *way;
  t_che *che;
  t_way *pt;
  int nb_ant;

  way = NULL;
  che = NULL;
  road = NULL;
  list = NULL;
  tree = NULL;

  ac = ac;
  //  fd = open(av[1], O_RDONLY);
  fd = 0;
  while ((rd = get_next_line(fd, &line)) > 0)
  {
	
     if (ft_vl_line(line) == 1)
	  ft_list(&list, line);
    else
      break ;   
  }
  if (ft_start_end(list) == 1)
  {
	  //error
	  ft_putstr("ERROR\n");
	  return (0);
  }

  nb_ant = ft_nb_ant(list);

  ft_treeinit(&tree, list);
  
    ft_roadInit(&road, list);
    
  //printf("<name: %s, size: %d>\n", tree->name, *tree->size);
  ft_list_print(list);
  //  ft_roadPrint(road);
    // ft_treePrint(tree);
  
  
  ft_treeroad(&tree, road);
//  ft_treeRoadPrint(tree);
  
ft_che(&che, tree);

  ft_way(&way, che, tree);
  
  //printWay(way);

  pt = ft_choose(way, tree);
  
  ft_print_ant(pt, nb_ant);
  //printWay(pt);
  return (0);
}

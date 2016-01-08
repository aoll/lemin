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
  
  ft_treeinit(&tree, list);
  
    ft_roadInit(&road, list);
    
  //printf("<name: %s, size: %d>\n", tree->name, *tree->size);
  //ft_listPrint(list);
  //  ft_roadPrint(road);
    // ft_treePrint(tree);
  
  
  ft_treeroad(&tree, road);
//  ft_treeRoadPrint(tree);
  
ft_che(&che, tree);

  ft_way(&way, che, tree);
  
  //printWay(way);

  ft_choose(way, tree);
  
  return (0);
}

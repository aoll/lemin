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


#include "lemin.h"
#include "libft/libft.h"

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
  fd = open(av[1], O_RDONLY);
  while ((rd = get_next_line(fd, &line)) > 0)
  {
	  ft_list(&list, line);
  }
  
  ft_treeInit(&tree, list);
  
  ft_roadInit(&road, list);
  
  //printf("<name: %s, size: %d>\n", tree->name, *tree->size);
  //ft_listPrint(list);
  //  ft_roadPrint(road);
  //ft_treePrint(tree);
  
  ft_treeRoad(&tree, road);
//  ft_treeRoadPrint(tree);
  ft_che(&che, tree);

  ft_way(&way, che, tree);
  //printWay(way);
  ft_choose(way, tree);
  return (0);
}

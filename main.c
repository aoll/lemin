/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aollivie <aollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/31 20:39:18 by aollivie          #+#    #+#             */
/*   Updated: 2015/03/31 21:06:52 by aollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "lemin.h"
#include "/home/alex/C/lemin/libft/libft.h"

int	main(int ac, char **av)
{
  t_list *list;
  t_tree *tree;
  int fd;
  int rd;
  char *line;
  t_road *road;
  t_way *way;

  road = NULL;
  list = NULL;
  tree = NULL;
  //printf("%p", &e);
  //e->a = 5;
  ac = ac;
  fd = open(av[1], O_RDONLY);
  while ((rd = get_next_line(fd, &line)) > 0)
    ft_list(&list, line);
  
  ft_treeInit(&tree, list);
  
  ft_roadInit(&road, list);

  //ft_wayInit(&way, road, tree);
  //printf("<name: %s, size: %d>\n", tree->name, *tree->size);
  //ft_listPrint(list);
  //ft_roadPrint(road);
  //ft_treePrint(tree);
  
  ft_treeRoad(&tree, road);
  ft_treeRoadPrint(tree);
  //printf("<road\n");
  
  //ft_wayPrint(way);
  //for(;;)
  //ft_ncurseInit(tree);
  return (0);
}

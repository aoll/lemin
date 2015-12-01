/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aollivie <aollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/31 20:39:18 by aollivie          #+#    #+#             */
/*   Updated: 2015/11/24 17:09:55 by aollivie         ###   ########.fr       */
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

  t_index *index;


  road = NULL;
  list = NULL;
  tree = NULL;
  index = NULL;
  //printf("%p", &e);
  //e->a = 5;
  ac = ac;
  fd = open(av[1], O_RDONLY);
  while ((rd = get_next_line(fd, &line)) > 0)
    ft_list(&list, line);
  
  ft_treeInit(&tree, list);
  
  ft_roadInit(&road, list);

  
  //printf("<name: %s, size: %d>\n", tree->name, *tree->size);
  //ft_listPrint(list);
  //  ft_roadPrint(road);
  //ft_treePrint(tree);
  
  ft_treeRoad(&tree, road);
  ft_treeRoadPrint(tree);
  ft_che(tree);
  //  ft_wayInit(&way, road, tree);
  /*     
 ft_indexInit(&index, tree);
  while (index )
  {
      if (index->way) {
      printf("New way:\n");
      ft_printWay(index->way); }
      index = index->next;
  }
  */
  //printf("wazaaaaaaaaaaaaaa: %s",index->way->name);
  return (0);
}

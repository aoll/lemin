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

int	ft_nb_c(char *s, char c)
{
  int i;
  int n;

  n = 0;
  i = 0;
  while(s[i])
    {
      if (s[i] == c)
	n++;
      i++;
    }
  return (n);
}

void	ft_setEtatBis(t_tree **tree, char *str, int start)
{
  t_tree *tmp;
  char **tab;

  tab = ft_strsplit(str, ' ');
  tmp = *tree;
  while (tmp)
    {
      if (ft_strcmp(tmp->name, tab[0]) == 1)
	{
	  if (start == 1)
	      tmp->start = true;
	  if (start == 2)
	    tmp->end = true;
	  return ;
	}
      tmp = tmp->next;
    }
  return ;
}

void	ft_treeSetEtat(t_tree **tree, t_list *list, char *target, int start)
{
  t_tree *tmp;

  
  tmp = *tree;
  while (list)
    {
      if (ft_strcmp(list->name, target) == 1)
	{
	  list = list->next;
	  while (list && list->name[0] != '#' && ft_nb_c(list->name,' ') == 2)
	    {
	      if (start == 0)
		printf("test if\n");
	      else if (start == 1)
		{
		  ft_setEtatBis(tree, list->name, start);
		  return ;
		}
	      else if (start == 2)
		{
		  ft_setEtatBis(tree, list->name, start);
		  return ;
	 	}
	      list = list->next;
	    }
	  *tree = tmp;
	  return;
	}
      list = list->next;
    }
  
}

void	ft_treeRoom(t_tree **tree, t_list *list)
{
  t_tree *tmp;

  tmp = *tree;
  while (list)
    {
      if (ft_nb_c(list->name,' ') == 2)
	ft_tree(&tmp, list);
      list = list->next;
    }
  *tree = tmp;
  return;
}

void	ft_treeInit(t_tree **tree, t_list *list)
{
  ft_treeRoom(tree, list);
  
  ft_treeSetEtat(tree, list, "##end", 2);
  ft_treeSetEtat(tree, list, "##start", 1);
}

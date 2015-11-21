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

int	char_c(char *s, char c)
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

void	ft_roadInit(t_road **road, t_list *list)
{
  while (list)
    {
      if (char_c(list->name, '-') == 1)
       	//printf("%s\n", list->name);
	ft_road(road, list->name);
      list = list->next;
    }
}

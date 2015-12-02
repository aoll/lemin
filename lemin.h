/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aollivie <aollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/31 20:20:23 by aollivie          #+#    #+#             */
/*   Updated: 2015/11/25 16:06:48 by aollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
#define LEMIN_H

#include <string.h>
#include <unistd.h>
#include <stdlib.h>
# include <math.h>
# include <string.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdio.h>
# include <stdbool.h>
# include <ncurses.h>
# include "libft/libft.h"


typedef struct s_che t_che;
struct s_che
{
  int fin;
  int check;
  char *name;
  int poids;
  int pos;
  int *size;
  t_che *next;
  t_che *list;
  t_che *prev;
  t_che *fa;

};

typedef struct s_road t_road;
struct s_road
{
  // char *name;
  bool use;
  char *in;
  char *out;
  int *size;
  t_road *next;
  t_road *prev;
  t_road *nextOther;
  t_road *prevOther;
};

typedef struct s_way t_way;
struct s_way
{
  char *name;
  int	index;
  int	size;
  t_way *next;
  t_way *prev;
  t_way *list;
};

typedef struct s_index t_index;
struct s_index
{
  int	index;
  int	size;
  t_index *next;
  t_index *prev;
  t_way *way;
 
};

typedef struct s_tree t_tree;
struct s_tree
{
  int test;
  char *name;
  int x;
  int y;
  bool start;
  bool end;
  int *size;
  t_tree *next;
  t_tree **tab;
  char **list;
  t_tree *prev;
};

void	ft_way(t_che *che, t_tree *tree);

void	ft_printChe(t_che *che);

void    ft_cpChe(t_che **che, t_tree *tree);

t_che   *ft_newChe(int poids);

void	ft_che(t_che **che, t_tree *tree);

//void	ft_printWay(t_way * way);

//void	ft_wayInit(t_way **way, t_tree *tree);

void	ft_indexInit(t_index **index, t_tree *tree);

void	ft_road(t_road **road, char *src);
void	ft_roadInit(t_road **road, t_list *src);

void    ft_treeRoad(t_tree **tree, t_road *road);
void	ft_tree(t_tree **tree, t_list *src);
void	ft_treeInit(t_tree **tree, t_list *src);
void	ft_ncurseInit(t_tree *tree);

/*

void    ft_wayAdd(t_way **way, t_way *new);
void    ft_wayAddOther(t_way **way, t_way *new);
t_way   *ft_wayNew(t_road *road, char *name, char *start, char *ref);
void    ft_way(t_way **way, t_road *road, char *src, char *start);
*/
#endif

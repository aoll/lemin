/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aollivie <aollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/31 20:20:23 by aollivie          #+#    #+#             */
/*   Updated: 2015/12/02 13:57:08 by aollivie         ###   ########.fr       */
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
	int	check;
	int	ant;
  t_way *next;
  t_way *prev;
  t_way *list;
	t_way *f;
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
	int ant;
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

typedef struct s_ant t_ant;
struct s_ant
{
	char *name;
	t_ant *next;
};

t_way	*ft_choose(t_way *way, t_tree *tree);

void	ft_print_ant(t_way *w, int nb_ant);

t_tree          *ft_getTree(t_tree *tree, char *nameTarget);
t_tree          *ft_getTreeEnd(t_tree *tree);
t_tree          *ft_getTreeStart(t_tree *tree);
void            ft_addChe(t_che **che, t_che *new);
int             ft_checkFa(t_che *che, char *s);
void            ft_nextChe(t_che **che, t_tree *tree);
void            ft_firstChe(t_che **che, t_tree *tree);
t_che           *ft_newChe(int poids);
void            ft_cpChe(t_che **che, t_tree *tree);
void            ft_cpWay(t_che **che, t_tree *tree);

int             ft_sement(t_way *way, char *s);
t_way           *ft_getshort(t_way *w);
int             ft_croi(t_way *way, t_way *w);

t_tree	*ft_getTreeEnd(t_tree *tree);

void    ft_addlist(t_way **w, t_way *n);
void                    ft_addway(t_way **w, t_way *n);
t_way                   *ft_newway(char *s);
void	ft_way(t_way **way, t_che *che, t_tree *tree);
void	printWay(t_way *w);



void	ft_printChe(t_che *che);
void    ft_cpChe(t_che **che, t_tree *tree);
t_che   *ft_newChe(int poids);
void	ft_che(t_che **che, t_tree *tree);


void	ft_indexInit(t_index **index, t_tree *tree);

void	ft_road(t_road **road, char *src);
void	ft_roadInit(t_road **road, t_list *src);

void    ft_treeroad(t_tree **tree, t_road *road);
void	ft_tree(t_tree **tree, t_list *src);
void	ft_treeinit(t_tree **tree, t_list *src);

int	ft_ck_room(char *s);
int	ft_ck_valide_room(char *s);
int	ft_ck_valide_pipe(char *s);
int     ft_check_space(char *s);
int     ft_ck_com(char *s);
int     ft_ck_action(char *s);
int     ft_ck_valide_action(char *s);
int     ft_ck_digit(char *s);

int	ft_ck_error(char *s);
int	ft_vl_first_line(char *s);
int	ft_vl_line(char*s);


void	ft_ncurse_init(t_tree *tree, t_list *list, int ant);
//void	ft_init_ant(t_list *list);

t_tree	*ft_tri_tree(t_list *l);

#endif

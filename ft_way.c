#include "lemin.h"

static void pw(t_way *w)
{
  printf("NEW WAY\n");
  while (w)
    {
      printf("NAME: %s\n", w->name);
      w = w->next;
    }
}

static void printWay(t_way *w)
{
  while (w)
    {
      pw(w);
      //      printf("NAME: %s\n", w->name);
      w = w->list;
    }
}

void	ft_addList(t_way **w, t_way *n)
{
  t_way *t;

  t = *w;
  if (t->list == NULL)
    {
      t->list = n;
      return;
    }
  t = t->list;
  while (t->list)
    {
      t = t->list;
    }
  t->list = n;
}

void	ft_addWay(t_way **w, t_way *n)
{
  t_way *t;

  t = *w;
  while (t->next)
    {
      t = t->next;
    }
  t->next = n;
  n->prev = t;
}

t_way	*ft_newWay(char *s)
{
  t_way *new;

  new = malloc(sizeof(t_way));
  new->index = 0;
  new->size = 1;
  new->name = ft_strdup(s);
  new->next = NULL;
  new->prev = NULL;
  new->list = NULL;
  return (new);
}

static t_way	*ft_cp(t_che *che)
{
  t_way *n;

  n = ft_newWay(che->name);
  //printf("NEW WAY: 0\n");
  che = che->fa;
  while (che)
    {
      //printf("NAME: %s\n", che->name);
      ft_addWay(&n, ft_newWay(che->name));
      che = che->fa;
    }
  return (n);
}

static void	ft_init(t_way **way, t_che *che)
{
  t_way *t;

  t = *way;
  if (t == NULL)
    {
     printf("FIRST!!!\n");
    *way = ft_cp(che);
    } 
  else
    ft_addList(way, ft_cp(che));
} 

static void print(t_way **way, t_che *che, char *s)
{
  
  while (che)
    {
      if (che->fin == 1)
	{
	  ft_init(way, che);
	  printf("YOUPI!!!!!\n");
	}
      che = che->next;
    }
}

static void      ft_while(t_way **way, t_che *che)
{
  print(way, che->list, che->name);
  while (che->list)
    {
      ft_while(way, che->list);
      che->list = che->list->next;
    }
}

void	ft_way(t_che *che, t_tree *tree)
{
  t_way *way;

  way = NULL;
  ft_while(&way, che);

  printWay(way);
}

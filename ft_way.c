#include "lemin.h"
/*
void	ft_print(t_way *tmp)
{
  while(tmp)
    {
      printf("==> ");
      printf("<in: %s, out: %s,  size: %d>\n",tmp->in,tmp->out, *tmp->size);
      tmp = tmp->next;
    }
}
*/

static char    *ft_endName(t_tree *tree)
{
  while (tree)
    {
      if (tree->end == true)
        return (tree->name);
      tree = tree->next;
    }
  return (NULL);
}

static char    *ft_startName(t_tree *tree)
{
  while (tree)
    {
      if (tree->start == true)
        return (tree->name);
      tree = tree->next;
    }
  return (NULL);
}

static int	ft_nb_way(t_road *road, char *name)
{
  int nb;

  nb = 0;
  while (road)
    {
      if (ft_strcmp(name, road->in) == 1 || ft_strcmp(name, road->out) == 1)
	nb++;
      road = road->next;
    }
  return (nb);
}

t_tree	*ft_getTree(t_tree *tree, char *name)
{
  while(tree)
    {
      if (ft_strcmp(tree->name, name) == 1)
	return (tree);
      tree= tree->next;
    }
  return (NULL);
}

void	ft_wayInit(t_way **way, t_road *road, t_tree *tree)
{
  t_way *new;
  t_tree *tmpTree;
  
  
  new = maloc(sizeof(t_way));
  new->name = ft_strdup(ft_endName(tree));
  new->index = 0;
  tmpTree = ft_getTree(tree, new->name);
  new->prev = NULL;
  

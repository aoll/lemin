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

char    *ft_endName(t_tree *tree)
{
  while (tree)
    {
      if (tree->end == true)
        return (tree->name);
      tree = tree->next;
    }
  return (NULL);
}

char    *ft_startName(t_tree *tree)
{
  while (tree)
    {
      if (tree->start == true)
        return (tree->name);
      tree = tree->next;
    }
  return (NULL);
}

int	ft_nb_way(t_road *road, char *name)
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

t_way	*ft_wayNew(t_road *road, char *name, char *start, char *ref)
{
  t_way *new;
  t_road *tmp;
  char **tab;
  int nb;
  int inu;

  inu = 0;
  printf("name ==> %s\n", name);
  printf("ref ==> %s\n", ref);

  new = malloc(sizeof(t_way));

  new->prev = NULL;
  new->name = ft_strdup(name);
  nb = ft_nb_way(road, name);
  printf("nb de routes ==> %d\n", nb);
  //return (NULL);
  new->next = malloc(sizeof(t_way) * nb); 
  new->size = malloc(sizeof(int));
  *new->size = 1;

  //nb++;
  tmp = road;

  while (road) 
    {
     
      if (ft_strcmp(road->in, name) == 1 && ft_strcmp(road->out, ref) != 1)
	{

	  new->in = ft_strdup(road->in);
	  new->out = ft_strdup(road->out);
	  printf("wayTEST: ");
	  printf("<in: %s, out: %s,  size: %d>\n",new->in,new->out, *new->size);
	  //*new->size = *new->size + 1;
	  if (ft_strcmp(new->out, start) != 1)
	    new->next[inu++] = ft_wayNew(tmp, new->out, start, name);
	  
	  break;
	  
	}
     
      if (ft_strcmp(road->out, name) == 1 && ft_strcmp(road->in, ref) != 1)
	{
	  
	  new->in = ft_strdup(road->out);
	  new->out = ft_strdup(road->in);
	  printf("wayTEST: ");
	  printf("<in: %s, out: %s,  size: %d>\n",new->in,new->out, *new->size);
	  
	  if (ft_strcmp(new->out, start) != 1)
	    new->next[inu++] = ft_wayNew(tmp, new->out, start, name);
	  break;
	}
      
      road = road->next;
    }
  return (new);
}

void	ft_wayInit(t_way **way, t_road *road, t_tree *tree)
{
  int nb;

  //printf("name = %s\n", ft_startName(tree));
  // printf("nb way = %d\n", ft_nb_way(road, ft_endName(tree)));
  
  //nb = ft_nb_way(road, ft_endName(tree));
  //while (nb)
  // {
  *way = ft_wayNew(road, ft_endName(tree), ft_startName(tree), "noMi76ntuli98tedinIatilsaTI45On");
      //  nb--;
      // }
}

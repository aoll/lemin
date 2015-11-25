#include "lemin.h"

void	ft_treeRoadPrint(t_tree *tmp)
{
  int nb;

  
  while(tmp)
    {
      nb = 0;
      printf("<name ===> %s>\n",tmp->name);
      while (tmp->list[nb])
	{
	  printf("<route: %s>\n",tmp->list[nb]);
	  nb++;
	}
      tmp = tmp->next;
    }
}


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

t_tree	*ft_giveBack(t_tree *tree, char *name)
{
  t_tree *tmp;

  tmp = tree;
  while (tmp)
    {
      if (ft_strcmp(tmp->name, name) == 1)
	return (tmp);
      tmp = tmp->next;
    }
  return (NULL);
}

void	ft_treeRoadInit(t_tree **tree, t_road *road)
{
  
  t_tree *tmp;
  
  int nb;
  int i;

  i = 0;
  tmp = *tree;
  tmp->test = 1;
  //return ;

  nb = ft_nb_way(road, tmp->name);

  if (!(tmp->list = malloc(sizeof(char *) * nb + 1)))
    printf("NULLLLLLLLLLLLLLLLLLL\n"); /// printf
  tmp->list[nb] = NULL;

  nb = 0;
  while (road) 
    {
      
      if (ft_strcmp(road->in, tmp->name) == 1)
	{


	  tmp->list[nb] = ft_strdup(road->out);

	  nb++;

	}
        
      else if (ft_strcmp(road->out, tmp->name) == 1)
	{

	  tmp->list[nb] = ft_strdup(road->in);

	  nb++;

	}
      

      road = road->next;
    }
 
}

void	ft_treeRoad(t_tree **tree, t_road *road)
{
  t_tree *tmp;
  t_tree *tmp2;

  tmp = *tree;
  while (tmp)
  {
     ft_treeRoadInit(&tmp, road);
      //tmp2 = tmp->tab[0];
      //printf("tree: %s\n", tmp->list[1]); 
      //printf("test: %d\n", tmp->test); 
      // break;
    tmp = tmp->next;
  }
}

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
  printf("name %s, nb de routes: %d\n", tmp->name, nb);
  //return (NULL);
  //  if (!(tmp->tab = malloc(sizeof(t_tree *) * nb + 1)))
  // printf("NULLLLLLLLLLLLLLLLLLL\n");
  //tmp->tab[nb] = NULL;
  if (!(tmp->list = malloc(sizeof(char *) * nb + 1)))
    printf("NULLLLLLLLLLLLLLLLLLL\n");
  tmp->list[nb] = NULL;
//tmp->list = malloc(sizeof(char *) * nb);

  nb = 0;
  //nb++;
  //tmp = road;
  while (road) 
    {
      
      if (ft_strcmp(road->in, tmp->name) == 1)
	{

	  //  tmp->tab[nb] = ft_giveBack(tmp, road->out);
	  //	  printf("roadout strdup K: %s\n", road->out);
	  tmp->list[nb] = ft_strdup(road->out);
	  printf("out:: %s\n", tmp->list[nb]);
	  //tmp3 = tmp->tab[nb];
	  //printf("road_inOK: %s\n", tmp3->name);
	  nb++;
	   printf("i in = %d\n", i++);
	}
        
      else if (ft_strcmp(road->out, tmp->name) == 1)
	{
	  // tmp->tab[nb] = ft_giveBack(tmp, road->in);
	  tmp->list[nb] = ft_strdup(road->in);
	  printf("in:: %s\n", tmp->list[nb]);
	  //printf("road_out: %s\n", road->in);
	  nb++;
	  printf("i = %d\n", i++);
	}
      
      //printf("NULLLLLLLLLLLLLLLLLLL\n");
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

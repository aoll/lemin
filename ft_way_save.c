#include "lemin.h"

void	ft_print(t_way *tmp)
{
  while(tmp)
    {
      printf("==> ");
      printf("<in: %s, out: %s,  size: %d>\n",tmp->in,tmp->out, *tmp->size);
      tmp = tmp->next;
    }
}


void	ft_wayPrint(t_way *tmp)
{
  while(tmp)
    {
      printf("way:\n");
      ft_print(tmp);
      tmp = tmp->nextOther;
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

//int	ft_check_cut(


t_way	*ft_wayNew(int *size, t_road *road, char *src, char *start)
{
  t_way *new;
  static int nb = 0;
  t_road *tmp;
  char **tab;

  printf("%s\n", src);
  tab = ft_strsplit(src, '-');
  new = malloc(sizeof(t_way));
  new->next = NULL;
  new->prev = NULL;
  new->name = ft_strdup(src);
  new->size = malloc(sizeof(int));
  new->size = size;
//new->size = &nb;

  //nb++;
  tmp = road;
  /*  printf("src : %s\n", src);
   printf("start : %s\n", start);
   printf("cmp a a : %d\n", ft_strcmp("a", "a"));
  if (ft_strcmp(src, start) == 1)
    {
      printf("cmp : %d\n", strcmp(src, start));
      return (NULL);
    }
  */
  while (road) 
    {
     
      if (ft_strcmp(road->in, src) == 1 && road->use == false)
	{
	  road->use = true;
	  new->in = ft_strdup(road->in);
	  new->out = ft_strdup(road->out);
	  printf("wayTEST: ");
	  printf("<in: %s, out: %s,  size: %d>\n",new->in,new->out, *new->size);
	  //*new->size = *new->size + 1;
	  if (ft_strcmp(new->out, start) != 1)
	    //	     return (new);
	   
	    ft_wayAdd(&new, ft_wayNew(new->size, tmp, new->out, start));
	  //ft_way(&new, road, road->out);
	  break;
	  //  new->nextOther = ft_wayNew(&nb, tmp, new->out, start);
	}
     
      if (ft_strcmp(road->out, src) == 1 && road->use == false)
	{
	  road->use = true;
	  new->in = ft_strdup(road->out);
	  new->out = ft_strdup(road->in);
	  printf("wayTEST: ");
	  printf("<in: %s, out: %s,  size: %d>\n",new->in,new->out, *new->size);
	  // *new->size = *new->size + 1;
	  if (ft_strcmp(new->out, start) != 1)
	    //return (new);
	    ft_wayAdd(&new, ft_wayNew(new->size, tmp, new->out, start));
	  //ft_way(&new, road, road->out); 
	  break;
	  //  new->nextOther = ft_wayNew(&nb, tmp, new->out, start);
	}
      
      road = road->next;
    }
  return (new);
}

void	ft_wayAdd(t_way **way, t_way *new)
{
  t_way *tmp;
  
  tmp = *way;
  
  //while(tmp->next)
  //tmp = tmp->next;
  *new->size = *new->size + 1;
  tmp->next = new;
  new->prev = tmp;
  
}

void	ft_wayAddOther(t_way **way, t_way *new)
{
  t_way *tmp;
  
  tmp = *way;
  
  while(tmp->nextOther)
    tmp = tmp->nextOther;
  //*new->size = *new->size + 1;
  tmp->nextOther = new;
  new->prevOther = tmp;
  
}

void	ft_way(t_way **way, t_road *road, char *src, char *start)
{
 
 
  t_way *new;
  t_way *tmp;
  
  int *size;
  int *sizeOther;
  

  // n = NULL;
  tmp = *way;
  if (*way == NULL)
    {
      printf("New way\n"); 
      size = malloc(sizeof(int));
      *size = 1;
      //printf("%p\n", n);
      //printf("%d\n", *n);
      new = ft_wayNew(size, road, src, start);
      *way = new;
      //free(n);
      //n = NULL;
      return;
      
    }
  else
    {
      sizeOther = malloc(sizeof(int));
      ft_wayAddOther(way, ft_wayNew(sizeOther, road, src, start));
    }
}

int	ft_nb_way(t_road *road, char *src)
{
  int nb;

  nb = 0;
  while (road)
    {
      if (ft_strcmp(src, road->in) == 1 || ft_strcmp(src, road->out) == 1)
	nb++;
      road = road->next;
    }
  return (nb);
}

void	ft_wayInit(t_way **way, t_road *road, t_tree *tree)
{
  int nb;

  printf("name = %s\n", ft_startName(tree));
  printf("nb way = %d\n", ft_nb_way(road, ft_endName(tree)));
  
  nb = ft_nb_way(road, ft_endName(tree));
  while (nb)
    {
      ft_way(way, road, ft_endName(tree), ft_startName(tree));
      nb--;
    }
}

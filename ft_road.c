#include "lemin.h"

void	ft_roadPrint(t_road *tmp)
{
  t_road *a;

  
  while(tmp)
    {
      printf("road:\n");
      printf("<in: %s, out: %s,  size: %d>\n",tmp->in,tmp->out, *tmp->size);
      tmp = tmp->next;
    }
}

t_road	*ft_roadNew(int *size, char *src)
{
  t_road *new;
  char **tab;

  tab = ft_strsplit(src, '-');
  new = malloc(sizeof(t_road));
  new->next = NULL;
  new->prev = NULL;
  new->use = false;
  new->in = ft_strdup(tab[0]);
  new->out = ft_strdup(tab[1]);
  new->size = malloc(sizeof(int));
  new->size = size;
  
  return (new);
}

void	ft_roadAdd(t_road **road, t_road *new)
{
  t_road *tmp;
  
  tmp = *road;
  
  while(tmp->next)
    tmp = tmp->next;
  *new->size = *new->size + 1;
  tmp->next = new;
  new->prev = tmp;
  
}

void	ft_road(t_road **road, char *src)
{
 
 
  t_road *new;
  t_road *tmp;
  
  int *size;
  

  // n = NULL;
  tmp = *road;
  if (*road == NULL)
    {
      printf("New road\n"); 
      size = malloc(sizeof(int));
      *size = 1;
      //printf("%p\n", n);
      //printf("%d\n", *n);
      new = ft_roadNew(size, src);
      *road = new;
      //free(n);
      //n = NULL;
      return;
      
    }
  else
    {
      ft_roadAdd(road, ft_roadNew(tmp->size, src));
      
    }
}

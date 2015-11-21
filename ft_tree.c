#include "lemin.h"

void	ft_treePrint(t_tree *tmp)
{
   while(tmp)
     {
       //printf!!
       printf("<name: %s, x: %d, y: %d, start: %d, end: %d>\n", tmp->name, tmp->x, tmp->y, tmp->start, tmp->end);
       tmp = tmp->next;
     }
}

t_tree	*ft_treeNew(int *size, t_list *src)
{
  t_tree *new;
  char **tab;

  tab = ft_strsplit(src->name, ' ');
  new = malloc(sizeof(t_tree));
  new->next = NULL;
  new->tab = NULL;
  new->name = ft_strdup(tab[0]);
  new->x = ft_atoi(tab[1]);
  new->y = ft_atoi(tab[2]);
  new->size = malloc(sizeof(int));
  new->size = size;
 

  return (new);
}


void	ft_treeAdd(t_tree **tree, t_tree *new)
{
  t_tree *tmp;
  
  tmp = *tree;
  
  while(tmp->next)
    tmp = tmp->next;
  *new->size = *new->size + 1;
  tmp->next = new;
  
  
}


void	ft_tree(t_tree **tree, t_list *src)
{
  //    printf("New TREE\n");
  t_tree *new;
  t_tree *tmp;
  
  int *n;

  // n = NULL;
  tmp = *tree;
  if (tmp == NULL)
    {
      //  printf("New tree\n"); 
      n = malloc(sizeof(int));
      *n = 0;
      //printf("%p\n", n);
      //printf("%d\n", *n);
      new = ft_treeNew(n, src);
      *n = *n + 1;
      *tree = new;
      //free(n);
      //n = NULL;
      return;
      
    }
  else
    {
      //printf("Add element\n");
      ft_treeAdd(tree, ft_treeNew(tmp->size, src));
      
    }
}

#include "libft.h"

void	ft_listPrint(t_list *tmp)
{
   while(tmp)
     {
       ft_putstr(tmp->name);
       ft_putchar('\n');
       tmp = tmp->next;
     }
}

t_list	*ft_listNew(int *size, char *src)
{
  t_list *new;

  new = malloc(sizeof(t_list));
  new->next = NULL;
  new->name = ft_strdup(src);
  new->size = malloc(sizeof(int));
  new->size = size;
  
  return (new);
}


void	ft_listAdd(t_list **list, t_list *new)
{
   t_list *tmp;
 
  tmp = *list;
   while(tmp->next)
    tmp = tmp->next;
  *new->size = *new->size + 1;
  tmp->next = new;
 }


void	ft_list(t_list **list, char *src)
{
  t_list *new;
  t_list *tmp;
  int *n;

  tmp = *list;
  if (tmp == NULL)
    {
      //printf("New list\n");
      
      n = malloc(sizeof(int));
  
      *n = 0;
      // printf("%p\n", n);      
      // printf("%d\n", *n);
      
      new = ft_listNew(n, src);
      
      *n = *n + 1;
      *list = new;
      //free(n);
      //n = NULL;
      return;
      
    }
  else
    {
      //printf("Add element\n");
      ft_listAdd(list, ft_listNew(tmp->size, src));
      
    }
}

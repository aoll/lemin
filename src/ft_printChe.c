#include "../lemin.h"

static void father(t_che *che)
{
  if (che)
    printf("FATHER!!\n");
  while(che)
    {
      printf("NAME: %s, POIDS: %d, CHECK: %d, FIN: %d\n",che->name, che->poids, che->check, che->fin);
      che = che->fa;
    }
}
static void print(t_che *che, char *s)
{
  while (che)
    {
      //   ft_while(che->list);
      printf("ROUTE: %s, NAME: %s, POIDS: %d, CHECK: %d, FIN: %d\n",s ,che->name, che->poids, che->check, che->fin);
    // father(che->fa);
     che = che->next;
    }
}	

static void	 ft_while(t_che *che, int nb)
{
  //  
 
  print(che->list, che->name);

  while (che->list)
    {
      ft_while(che->list, nb + 1);
      //printf("NAME: %s, POIDS: %d, CHECK: %d\n",che->list->name, che->list->poids, che->list->check);
      che->list = che->list->next;
    }
 
}

void	ft_printChe(t_che *che)
{
  printf("CHEMIN: %d, Name: %s, POIDS: %d, CHECK: %d\n", 0,che->name, che->poids, che->check);
  ft_while(che, 0);
}

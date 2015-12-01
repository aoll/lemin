#include "lemin.h"

t_tree	*ft_getTree(t_tree *tree, char *nameTarget)
{
  while (tree->prev)
    tree = tree->prev;
  while(tree)
    {
      if (ft_strcmp(tree->name, nameTarget) == 1)
	return (tree);
      tree = tree->next;
    }
  return (NULL);
}

t_tree	*ft_getTreeEnd(t_tree *tree)
{
  while (tree->prev)
    tree = tree->prev;
  while(tree)
    {
      if (tree->end == true)
	return (tree);
      tree = tree->next;
    }
  return (NULL);
}

t_tree	*ft_getTreeStart(t_tree *tree)
{
  while (tree->prev)
    tree = tree->prev;
  while(tree)
    {
      if (tree->start == true)
	return (tree);
      tree = tree->next;
    }
  return (NULL);
}

void	ft_addChe(t_che **che, t_che *new)
{
  t_che *tmp;

  if (*che == NULL)
    {
      *che = new;
      return;
    }
  tmp = *che;
  while(tmp->next)
    {
      tmp = tmp->next;
    }
  new->prev = tmp;
  tmp->next = new;
}
int	ft_checkFa(t_che *che, char *s)
{
  while (che)
    {
      if (ft_strcmp(che->name, s) == 1)
	return (1);
      //      printf("CHE->NAME: %s, S: %s\n", che->name, s);
      che = che->fa;
    }
  return (0);
}


void	ft_cpWay(t_che **che, t_tree *tree)
{
  t_che *tmp;
  t_che *new;
  int nb;
  t_tree *tampon;

  nb = 0;
  tmp = *che;
  tmp->check = 1;
  tampon = malloc(sizeof(t_tree));
  while (tree->list[nb])
    {     
      tampon = ft_getTree(tree, tree->list[nb]);
      if (tampon->end != true && ft_checkFa(tmp, tree->list[nb]) != 1)
	{
	  new = ft_newChe(tmp->poids + 1);
	  new->name = ft_strdup(tree->list[nb]);
	  new->fa = *che;
	  ft_addChe(&tmp->list, new);
	}
      nb++;
    }
}

void	ft_cpChe(t_che **che, t_tree *tree)
{
  t_che *tmp;

  tmp = *che;
  tmp->name = ft_strdup(tree->name);
}

t_che	*ft_newChe(int poids)
{
  t_che *che;
 
  if(!(che = malloc(sizeof(t_che))))
    return (NULL);
  che->poids = poids;
  che->name = ft_strnew(0);
  che->next = NULL;
  che->prev = NULL;
  che->list = NULL;
  che->fa = NULL;
  che->check = 0;
  return (che);
}

void	ft_firstChe(t_che **che, t_tree *tree)
{
  t_che *new;

  new = ft_newChe(0);
  ft_cpChe(&new, ft_getTreeEnd(tree));
  ft_cpWay(&new, ft_getTreeEnd(tree));
  *che = new;
}



void	ft_nextChe(t_che **che, t_tree *tree)
{
  t_che *tmp2;
  t_che *tmp;
  t_che *list;
  t_tree *tampon;
  t_tree *buff;

  tmp2 = *che;
  tampon = malloc(sizeof(t_tree));
  tmp = tmp2->list;
   
 buff = ft_getTreeEnd(tree);
  if (ft_strcmp(tmp->name, buff->name) == 1)
    return;
 
buff = ft_getTreeStart(tree);
  // A VERIFIER PAS SUR DUTOUT QUE LA CONDITION SOIS PRIS EN COMPTE ...
  if (ft_strcmp(tmp->name, buff->name) == 1)
    return;

  while (tmp)
    {
      tampon = ft_getTree(tree, tmp->name);
      if (ft_strcmp(tmp->name, buff->name) != 1)
	{
	  //  if (ft_checkFa(tmp2, tmp->name) != 1)
	      ft_cpWay(&tmp,tampon);
	}
      list = tmp->list;
      //      while (list)
      //	{
	  /*
	   if (ft_strcmp(list->name, buff->name) != 1)
	     ft_cpWay(&list, ft_getTree(tree, list->name));
	  */
	  /*  if (ft_strcmp(list->name, buff->name) != 1)
	      ft_nextChe(&list, tree);
	  */
      //    list = list->next;
      //	}
      tmp = tmp->next;
    }
}
void	ft_cheIni(t_che **che, t_tree *tree)
{
  t_che *t;

  t = *che;
  t = t->list;
  while (t)
    {
      ft_nextChe(&t, tree);
      t = t->next;
    }
}

void	ft_che(t_tree *tree)
{
  t_che *che;

  ft_firstChe(&che, tree);
  ft_nextChe(&che, tree);
  ft_cheIni(&che, tree);
  //ft_nextChe(&che->list, tree);
  

   ft_printChe(che);
}

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
  printf("ENTER FT_NEXTCHE\n");
  t_che *tmp2;
  t_che *tmp;
  t_che *list;
  t_tree *tampon;
  t_tree *buff;


  tmp2 = *che;
  if (tmp2->list)
    tmp = tmp2->list;
  else
    return;

  tampon = malloc(sizeof(t_tree));

   
  buff = malloc(sizeof(t_tree));
  buff = ft_getTreeEnd(tree);

printf("OUT Z FT_NEXTCHE\n");
 
 printf("NULLLLLLL tmp->name: %s, buff->name:\n", buff->name);//, buff->name);
if (ft_strcmp(tmp->name, buff->name) == 1)
  {
    printf("OUT 0 FT_NEXTCHE\n");
    return;
  }
   printf("OUT null FT_NEXTCHE:\n");  
  buff = ft_getTreeStart(tree);
  if (ft_strcmp(tmp->name, buff->name) == 1)
    return;
printf("OUT 1 FT_NEXTCHE\n");
  while (tmp)
    {
      tampon = ft_getTree(tree, tmp->name);
      if (ft_strcmp(tmp->name, buff->name) != 1)
	{
	      ft_cpWay(&tmp,tampon);
	}
      tmp = tmp->next;
    }
  printf("OUT FT_NEXTCHE\n");
}
void	ft_cheIni(t_che **che, t_tree *tree)
{
  t_che *t;
  t_tree *tmp;

  printf("ENTER FT_CHEINI\n");
  t = *che;
  printf("T CHE NAME: %s\n", t->name);
  tmp = malloc(sizeof(t_tree));
  ft_nextChe(&t, tree);
  if (t->list == NULL)
    return;
  
  t = t->list;
  
  while (t)
    {
      printf("T LIST NAME: %s\n", t->name);
      tmp = ft_getTree(tree, t->name);
      if (tmp->start == false)
	{
	  //ft_nextChe(&t, tree);
	  ft_cheIni(&t, tree);
	}
      else
	t->check = 1;
      t = t->next;
    }
   printf("OUT FT_CHEINI\n");
}

static void ft_noCheck(t_che **che1, t_tree *tree, t_tree *name)
{
  t_che *che;

  che = *che1;
  while (che)
    {
      
      if (ft_strcmp(name->name, che->name) == 1)
	{
	  //printf("NOCHECK, NAME: %s, POIDS: %d, CHECK: %d\n" ,che->name, che->poids, che->check);
	   che->check = 1;
	}
            if (che->check != 1)
	{
	  //	  printf("WTF??????");
	  ft_cheIni(&che, tree);
	}

      che = che->next;
    }
}

static void      ft_while(t_che **che1, t_tree *tree)
{
  t_che *che;

  che = *che1;
  if (che->list == NULL)
    return;
  che = che->list;
  ft_noCheck(&che->list, tree, ft_getTreeStart(tree));

  while (che)
    {
      // printf("WTF??????\n");
      ft_while(&che, tree);

      che = che->next;
    }
}


void	ft_che(t_tree *tree)
{
  t_che *che;

  ft_firstChe(&che, tree);
  //ft_nextChe(&che, tree);
  ft_cheIni(&che, tree);
  //ft_cheIni(&che, tree);
  
  //  ft_cheIni(&che->list, tree);
  /*
  ft_cheIni(&che->list->list, tree);
  ft_cheIni(&che->list->next, tree);
  ft_cheIni(&che->list->next->list, tree);
  */
//ft_while(&che, tree);

   ft_printChe(che);
}

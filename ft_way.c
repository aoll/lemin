#include "lemin.h"

void	ft_printWay(t_way *tmp)
{
  while(tmp)
    {
      printf("==> ");
      printf("<==== name : %s>\n",tmp->name);
      tmp = tmp->next;
    }
}


static char    *ft_endName(t_tree *tree)
{
  while (tree)
    {
      if (tree->end == true)
        return (tree->name);
      tree = tree->next;
    }
  return (NULL);
}

static char    *ft_startName(t_tree *tree)
{
  while (tree)
    {
      if (tree->start == true)
        return (tree->name);
      tree = tree->next;
    }
  return (NULL);
}

t_tree	*ft_getTree(t_tree *tree, char *name)
{
  while(tree)
    {
      if (ft_strcmp(tree->name, name) == 1)
	return (tree);
      tree= tree->next;
    }
  return (NULL);
}

int	ft_checkPrev(t_way *way, char *name)
{

  while (way != NULL)
    {
      printf("checkprev ==== %s\n", way->name);
      if (ft_strcmp(way->name, name) == 1)
	return (1);
      way = way->prev;
    }
printf("okkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkk\n");   
  return (0);
}

t_index		*ft_index(int index)
{
  t_index *new;

  new = malloc(sizeof(t_index));
  new->index = index + 1;
  new->next = NULL;
  new->prev = NULL;
  new->way = malloc(sizeof(t_way));
  return (new);
}

void	ft_addIndex(t_index **index, t_index *new)
{
  t_index *tmp;

  tmp = *index;

  while (tmp->next)
    {
      tmp = tmp->next;
    }
  tmp->next = new;
  new->prev = tmp;
}

t_way	*ft_cpWay(t_way *src)
{
  t_way *new;

  new = malloc(sizeof(t_way));
  new->name = ft_strdup(src->name);
  new->next = NULL;
  new->prev = NULL;
  return (new);
}

t_way	*ft_backWay(t_way *old)
{
  t_way *new;

  new = ft_cpWay(old);
  old = old->prev;
  while (old)
    {
      new->prev = ft_cpWay(old);
      new->prev->next = new;
      old = old->prev;
    }
  return (new->prev);
}

t_way	*ft_way(t_way **way, char *prevName, char *name, t_tree *tree, t_index **index, int first)
{
  t_way *new;
  int nb;
  t_tree *tmp;
  int rep;
  t_index *indexTmp;

  indexTmp = *index;
  nb = 0;
  rep = 0;
  tmp = tree;
  new = malloc(sizeof(t_way));
  new->name = ft_strdup(name);
  if (prevName)
    {
      new->prev = *way;
    }
  else
    new->prev = NULL;

  tmp = ft_getTree(tree, name); 
  
  if (tmp->start == true)
    return (new);
  while (tmp->list[nb])
    {
      printf("tree name STANDART: %s, tree->list[%d], %s\n",tmp->name, nb, tmp->list[nb]);
      if (ft_checkPrev(new, tmp->list[nb]) != 1 && rep == 0)
	{
		printf("tree name NB0 ?: %s, tree->list[%d], %s\n",tmp->name, nb, tmp->list[nb]);
		new->next = ft_way(&new, new->name, tmp->list[nb], tree, index, 2);
	  rep++;
	}
	  else if (ft_checkPrev(new, tmp->list[nb]) != 1 && rep > 0)
	{
		printf("tree name NB++ : %s, tree->list[%d], %s\n",tmp->name, nb, tmp->list[nb]);
		printf("WTF??\n");
		 printf("list NB !! %s\n", tmp->list[nb]); 
	  indexTmp = ft_index(indexTmp->index);
	  indexTmp->way = ft_backWay(new);		// || new->prev ??
	  ft_addIndex(index, indexTmp);
	 
	}
	  nb++;
    }
  return (new);
}
  
  

void	ft_indexInit(t_index **index, t_tree *tree)
{
  t_index *tmp;

  *index = ft_index(0);
  tmp = *index;
  tmp->way = ft_way(&tmp->way, NULL, ft_endName(tree), tree, &tmp, 1);
}

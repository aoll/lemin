#include "lemin.h"

void	ft_printWay(t_way *tmp)
{
  t_way *tmp2;

  tmp2 = tmp;

  while(tmp2)
    {

      printf("<name : %s>\n",tmp2->name);
      tmp2 = tmp2->next;
    }
  /*
  while(tmp->next)
    {
      tmp = tmp->next;
    }
  printf("<TMP->PREV>\n");
  while(tmp)
    {
      printf("<name : %s>\n",tmp->name);
      tmp = tmp->prev;
    }
  */
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

static t_tree	*ft_getTree(t_tree *tree, char *name)
{
  while(tree)
    {
      if (ft_strcmp(tree->name, name) == 1)
	return (tree);
      tree= tree->next;
    }
  return (NULL);
}

static int	ft_checkPrev(t_way *way, char *name)
{

  while (way != NULL)
    {
      
      if (ft_strcmp(way->name, name) == 1)
	return (1);
      way = way->prev;
    }

  return (0);
}

t_index		*ft_index(int index)
{
  t_index *new;


  //  printf("index create: %d\n", index);
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

static t_way	*ft_cpWay(t_way *src)
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

  printf("backWay: %s\n", old->name);
  new = ft_cpWay(old);
  if (old->prev) 
    {
      old = old->prev;
      while (old->prev)
	{
	  	 
	  new->prev = ft_cpWay(old);
	  new->prev->next = new;
	  old = old->prev;
	}
    }
  if (new->prev)
    return (new->prev);
  else
    return (new);
}

void	ft_prevInit(t_index **tmp, t_way *new)
{
	t_index *tmp2;
	
	printf("PREVINIT: %s\n", new->name);
	tmp2 = *tmp;
	while (tmp2->way->next)
	{
		tmp2->way = tmp2->way->next;
	}
	tmp2->way->next = new;;

}


void	ft_prev(t_index **tmp2,t_way *new)
{
    
	t_index *tmp;

	tmp = *tmp2;
  while (new->prev)
    {
//      printf("PREV: %s\n", new->name);
	  ft_prevInit(tmp2, ft_cpWay(new));
      new = new->prev;
    }
  
}

void	printprev(t_way *way)
{
//  printf("PRINTPREV\n");
  while (way)
    {
		//    printf("new= %s\n", way->name);
      way = way->prev;
    }
}

t_way	*ft_way(t_way **way, char *prevName, char *name, t_tree *tree, t_index **index, int first)
{
  t_way *new;
  t_way *wayTmp;
  int nb;
  t_tree *tmp;
  int rep;
  t_index *indexTmp;
  t_index *indexTmp2;
   t_index *indexTmp3;

  
  indexTmp = *index;
  nb = 0;
  rep = 0;
  tmp = tree;
  new = malloc(sizeof(t_way));
  wayTmp = malloc(sizeof(t_way));
  new->name = ft_strdup(name);
  if (prevName)
    {
      new->prev = *way;
    }
  else
    new->prev = NULL;
  int test;

  test = 0;
  tmp = ft_getTree(tree, name);
  /*
  while (tmp->list[test])
    {
      printf("%s\n", tmp->list[test++]);
    }
  //return (NULL);
  */
  if (first == 5)
    return (new);
  
  if (tmp->start == true){ 
    // printf("START: %s\n ", tmp->name);
    return (new);}

  while (tmp->list[nb])
    {
      
      if (ft_checkPrev(new, tmp->list[nb]) != 1 && rep == 0)
	{
	  
	  new->next = ft_way(&new, new->name, tmp->list[nb], tree, index, 2);
	  rep++;
	}
	  else if (ft_checkPrev(new, tmp->list[nb]) != 1 && rep > 0)
	{
	  
	  
	   indexTmp2 = ft_index(indexTmp->index);
	   indexTmp3 = ft_index(indexTmp->index);
	   
	   indexTmp2->way = ft_way(&indexTmp2->way, NULL, ft_endName(tree), tree, index, 5);
	   indexTmp3->way = ft_way(&indexTmp3->way, NULL, ft_endName(tree), tree, index, 5);
	   
	   //	    ft_prev(&indexTmp2, new);
	   
	   ft_prevInit(&indexTmp2, ft_way(&indexTmp2->way, new->name, tmp->list[nb], tree, index, 2));
	   
	   indexTmp3->way->next = indexTmp2->way;
	   
	   if (ft_strcmp(indexTmp3->way->name, indexTmp2->way->name) == 1)
	     ft_addIndex(index, indexTmp2);
	   else
	     ft_addIndex(index, indexTmp3);
	  
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

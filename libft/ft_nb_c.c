#include "libft.h"

int	ft_nb_c(char *s, char c)
{
	int nb;
	int i;

	nb = 0;
	i = 0;
	if (!s)
	  return (0);
	while (s[i])
	  {
	    if (s[i] == c)
	      nb++;
	    i++;
	  }
	return (nb);
}


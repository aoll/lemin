#include "../lemin.h"

int	ft_ck_error(char *s)
{
	if (ft_check_space(s) == 1)
		return (1);
	if (ft_ck_com(s) == 1)
	{
		if (ft_ck_action(s) == 1)
		{
			if (ft_ck_valide_action(s) != 1)
				return (1);
		}
	}
	else
	{
		if (ft_ck_room(s) == 1)
		{
			if (ft_ck_valide_room(s) != 1)
				return (1);
		}
		else
		{
			if (ft_ck_valide_pipe(s) != 1)
				return (1);
		}
	}
	return (0);
}

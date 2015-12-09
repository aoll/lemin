#include "../lemin.h"

int	ft_vl_first_line(char *s)
{
	int i;

	i = 0;
	if (ft_check_space(s) == 1)
		return (0);
	while (s[i])
	{
		if (ft_isdigit(s[i]) != 1)
			return (0);
		i++;
	}
	return (1);
}

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

int	ft_vl_line(char *s)
{
	static int nb = 0;

	if (nb == 0)
	{
		if (ft_vl_first_line(s) != 1)
			return (0);
		nb++;
	}
	else if (ft_ck_error(s) == 1)
		return (0);
	return (1);
}

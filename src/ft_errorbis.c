/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errorbis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aollivie <aollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 13:57:19 by aollivie          #+#    #+#             */
/*   Updated: 2015/12/02 13:59:36 by aollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lemin.h"

int	ft_ck_room(char *s)
{
	if (ft_nb_c(s, ' ') == 2)
		return (1);
	return (0);
}

int	ft_ck_valide_room(char *s)
{
	char	**tab;
	int		nb;
	int		i;

	nb = 1;
	if (s[0] == 'L')
		return (0);
	tab = ft_strsplit(s, ' ');
	while (tab[nb])
	{
		i = 0;
		while (tab[nb][i])
		{
			if (ft_isdigit(tab[nb][i]) != 1)
				return (0);
			i++;
		}
		nb++;
	}
	return (1);
}

int	ft_ck_valide_pipe(char *s)
{
	char	**tab;
	int		nb;
	int		i;

	if (ft_nb_c(s, '-') != 1)
		return (0);
	tab = ft_strsplit(s, '-');
	if (tab[0][0] == 'L' || tab[1][0] == 'L')
		return (0);
	return (1);
}

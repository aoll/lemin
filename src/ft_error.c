/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aollivie <aollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 13:57:19 by aollivie          #+#    #+#             */
/*   Updated: 2015/12/02 13:59:36 by aollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lemin.h"

int	ft_check_space(char *s)
{
	if (!s)
		return (1);
	if (!s[0])
		return (1);
	if (ft_isspace(s[0]))
		return (1);
	return (0);
}

int	ft_ck_com(char *s)
{
	if (!s)
		return (0);
	if (s[0] == '#')
		return (1);
	return (0);
}

int	ft_ck_action(char *s)
{
	if (!s)
		return (0);
	if (strlen(s) < 2)
		return (0);
	if (s[0] == '#' && s[1] == '#')
		return (1);
	return (0);
}

int	ft_ck_valide_action(char *s)
{
	if (ft_strcmp(s, "##start") == 1 || ft_strcmp(s, "##end") == 1)
		return (1);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aollivie <aollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 16:20:49 by aollivie          #+#    #+#             */
/*   Updated: 2015/02/28 18:12:02 by aollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int		ft_strcmp(const char *s1, const char *s2)
{
	int				i;
	unsigned char	*str1;
	unsigned char	*str2;
	
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	/*
	if (!str1 && !str2)
		return (1);
	if (s1[0] == '\0' || s2[0] == '\0')
		return (0);
	
	if (!str1 || !str2)
		return (0);
	*/
	i = 0;
	while (str1[i] && str2[i])
	{
		if (str1[i] == str2[i])
			i++;
		else
		  return (-1);
	}
	/*
	if (!str2[i] && str1[i])
		return (0);
	if (!str1[i] && str2[i])
		return (-1);
	*/
	if (str1[i] == str2[i])
	  return (1);
	else
	  return (-1);
}

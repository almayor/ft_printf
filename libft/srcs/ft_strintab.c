/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strintab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 23:26:15 by unite             #+#    #+#             */
/*   Updated: 2020/01/05 15:00:24 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_strintab(const char *str, char *const tab[])
{
	while (*tab)
	{
		if (ft_strequ(str, *tab))
			return (1);
		tab++;
	}
	return (0);
}

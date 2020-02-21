/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcount.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 20:05:56 by unite             #+#    #+#             */
/*   Updated: 2019/10/04 20:08:06 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strcount(const char *str, int (*f)(char))
{
	size_t	count;

	if (!str || !f)
		return (0);
	count = 0;
	while (*str)
	{
		if (f(*str))
			count++;
		str++;
	}
	return (count);
}

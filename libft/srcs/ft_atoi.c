/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 23:56:29 by unite             #+#    #+#             */
/*   Updated: 2019/09/23 00:28:30 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	long long	res;
	int			negative;

	while (ft_isspace(*str))
		str++;
	negative = 0;
	if (*str == '-' || *str == '+')
	{
		negative = *str == '-' ? 1 : 0;
		str++;
	}
	res = 0;
	while (ft_isdigit(*str))
	{
		res = res * 10 - (*str - '0');
		str++;
		if (!negative && res < -MAXLONGLONG)
			return (-1);
		if (negative && res < MINLONGLONG)
			return (0);
	}
	return (negative ? res : -1 * res);
}

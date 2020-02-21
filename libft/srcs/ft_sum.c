/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sum.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <unite@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 22:34:36 by unite             #+#    #+#             */
/*   Updated: 2019/09/28 22:34:50 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_sum(int const *tab, size_t len)
{
	int sum;

	if (!tab || !len)
		return (-1);
	sum = 0;
	while (len-- > 0)
	{
		if (sum + *tab > MAXINT)
			return (-1);
		else
			sum += *tab;
		tab++;
	}
	return (sum);
}

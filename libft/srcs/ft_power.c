/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 16:09:37 by unite             #+#    #+#             */
/*   Updated: 2019/09/20 23:31:45 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_power(int num, unsigned int exponent)
{
	long long result;

	result = 1;
	while (exponent-- > 0)
		result *= num;
	if (result > MAXINT)
		return (0);
	else
		return ((int)result);
}

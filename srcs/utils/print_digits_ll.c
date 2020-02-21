/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_digits_ll.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 22:44:49 by unite             #+#    #+#             */
/*   Updated: 2020/02/21 01:45:52 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

int	print_digits_ll(long long num, char *radix)
{
	long long	base_len;
	long long	factor;

	base_len = ft_strlen(radix);
	factor = 1;
	while (num / factor >= base_len && num >= 0)
		factor *= base_len;
	while (num / factor <= -base_len && num < 0)
		factor *= base_len;
	while (factor >= 1)
	{
		if (num >= 0)
			buffered_nprint(radix[num / factor], 1, 0, 0);
		else
			buffered_nprint(radix[-(num / factor)], 1, 0, 0);
		num %= factor;
		factor /= base_len;
	}
	return (0);
}

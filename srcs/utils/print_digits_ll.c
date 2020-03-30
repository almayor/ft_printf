/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_digits_ll.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 22:44:49 by unite             #+#    #+#             */
/*   Updated: 2020/03/17 07:22:35 by unite            ###   ########.fr       */
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
			buffered_putchar(radix[num / factor]);
		else
			buffered_putchar(radix[-(num / factor)]);
		num %= factor;
		factor /= base_len;
	}
	return (0);
}

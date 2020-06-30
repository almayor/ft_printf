/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffered_putlf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 21:44:57 by unite             #+#    #+#             */
/*   Updated: 2020/06/30 13:38:56 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

static long long	power_ll(long long base, size_t exponent)
{
	long long	result;

	result = 1;
	while (exponent-- > 0)
		result *= base;
	return (result);
}

int					buffered_putlf(long double num, char *radix,
									size_t precision, int print_dot)
{
	long long	factor;
	long long	int_part;
	long long	frc_part;
	size_t		frc_ndigits;

	factor = power_ll(ft_strlen(radix), precision);
	if (num < 0)
		num = num - 0.5 / factor;
	else
		num = num + 0.5 / factor;
	int_part = (long long)num;
	frc_part = (num - int_part) * factor;
	buffered_putll(int_part, radix);
	if (precision)
	{
		frc_ndigits = get_ndigits_ll(frc_part, ft_strlen(radix));
		buffered_putchar('.');
		buffered_putnchar('0', precision - frc_ndigits);
		buffered_putll(frc_part, radix);
	}
	else if (print_dot)
		buffered_putchar('.');
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_digits_lf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 21:44:57 by unite             #+#    #+#             */
/*   Updated: 2020/02/20 22:02:18 by unite            ###   ########.fr       */
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

int					print_digits_lf(long double num, char *radix,
									size_t precision, int print_dot)
{
	long long	factor;
	long long	int_part;
	long long	frc_part;
	size_t		frc_ndigits;

	factor = power_ll(10, precision);
	if (num < 0)
		num = num - 0.5 / factor;
	else
		num = num + 0.5 / factor;
	int_part = (long long)num;
	frc_part = (num - int_part) * factor;
	print_digits_ll(int_part, radix);
	if (frc_part != 0)
	{
		frc_ndigits = get_ndigits_ll(frc_part, ft_strlen(radix));
		buffered_nprint('.', 1, 0, 0);
		buffered_nprint('0', precision - frc_ndigits, 0, 0);
		print_digits_ll(frc_part, radix);
	}
	else if (print_dot)
		buffered_nprint('.', 1, 0, 0);
	return (0);
}

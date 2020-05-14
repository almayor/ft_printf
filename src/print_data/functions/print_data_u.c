/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_data_u.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 20:30:59 by unite             #+#    #+#             */
/*   Updated: 2020/03/31 17:34:41 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

static int	print_digits(t_specifier *specif, unsigned long long num,
						char *radix)
{
	if (num != 0 || !specif->precision.isgiven || specif->precision.value)
		print_digits_ull(num, radix);
	else if (specif->width.isgiven && specif->zero)
		buffered_putchar('0');
	else if (specif->width.isgiven)
		buffered_putchar(' ');
	return (0);
}

static int	print_left_aligned(t_specifier *specif, void *data)
{
	unsigned long long	num;

	num = *(unsigned long long *)data;
	if (specif->zero)
	{
		buffered_putnchar('0', specif->npad_precision);
		buffered_putnchar('0', specif->npad_width);
		print_digits(specif, num, "0123456789");
	}
	else
	{
		buffered_putnchar('0', specif->npad_precision);
		print_digits(specif, num, "0123456789");
		buffered_putnchar(' ', specif->npad_width);
	}
	return (0);
}

static int	print_right_aligned(t_specifier *specif, void *data)
{
	unsigned long long	num;

	num = *(unsigned long long *)data;
	if (specif->zero)
	{
		buffered_putnchar('0', specif->npad_precision);
		buffered_putnchar('0', specif->npad_width);
		print_digits(specif, num, "0123456789");
	}
	else
	{
		buffered_putnchar(' ', specif->npad_width);
		buffered_putnchar('0', specif->npad_precision);
		print_digits(specif, num, "0123456789");
	}
	return (0);
}

int			print_data_u(t_specifier *specif, void *data)
{
	if (specif->minus)
		print_left_aligned(specif, data);
	else
		print_right_aligned(specif, data);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_data_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 20:30:59 by unite             #+#    #+#             */
/*   Updated: 2020/03/29 16:44:02 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

static int	print_digits(t_specifier *specif, long long num, char *radix)
{
	if (num != 0 || !specif->precision.isgiven || specif->precision.value)
		print_digits_ll(num, radix);
	else if (specif->width.isgiven && specif->zero)
		buffered_putchar('0');
	else if (specif->width.isgiven)
		buffered_putchar(' ');
	return (0);
}

static int	print_sign(t_specifier *specif, int isnegative)
{
	if (isnegative)
		buffered_putchar('-');
	else if (specif->space)
		buffered_putchar(' ');
	else if (specif->plus)
		buffered_putchar('+');
	return (0);
}

static int	print_left_aligned(t_specifier *specif, void *data)
{
	long long	num;

	num = *(long long *)data;
	if (specif->zero)
	{
		print_sign(specif, num < 0);
		buffered_putnchar('0', specif->npad_precision);
		buffered_putnchar('0', specif->npad_width);
		print_digits(specif, num, "01");
	}
	else
	{
		print_sign(specif, num < 0);
		buffered_putnchar('0', specif->npad_precision);
		print_digits(specif, num, "01");
		buffered_putnchar(' ', specif->npad_width);
	}
	return (0);
}

static int	print_right_aligned(t_specifier *specif, void *data)
{
	long long	num;

	num = *(long long *)data;
	if (specif->zero)
	{
		print_sign(specif, num < 0);
		buffered_putnchar('0', specif->npad_precision);
		buffered_putnchar('0', specif->npad_width);
		print_digits(specif, num, "01");
	}
	else
	{
		buffered_putnchar(' ', specif->npad_width);
		print_sign(specif, num < 0);
		buffered_putnchar('0', specif->npad_precision);
		print_digits(specif, num, "01");
	}
	return (0);
}

int			print_data_b(t_specifier *specif, void *data)
{
	if (specif->minus)
		print_left_aligned(specif, data);
	else
		print_right_aligned(specif, data);
	return (0);
}
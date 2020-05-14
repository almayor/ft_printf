/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_data_xx.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 20:30:59 by unite             #+#    #+#             */
/*   Updated: 2020/05/14 23:10:35 by unite            ###   ########.fr       */
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

static int	print_prefix(t_specifier *specif, int iszero)
{
	if (specif->hash && !iszero)
		buffered_puts("0X");
	return (0);
}

static int	print_left_aligned(t_specifier *specif, void *data)
{
	unsigned long long	num;

	num = *(unsigned long long *)data;
	if (specif->zero)
	{
		print_prefix(specif, num == 0);
		buffered_putnchar('0', specif->npad_precision);
		buffered_putnchar('0', specif->npad_width);
		print_digits(specif, num, "0123456789ABCDEF");
	}
	else
	{
		print_prefix(specif, num == 0);
		buffered_putnchar('0', specif->npad_precision);
		print_digits(specif, num, "0123456789ABCDEF");
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
		print_prefix(specif, num == 0);
		buffered_putnchar('0', specif->npad_precision);
		buffered_putnchar('0', specif->npad_width);
		print_digits(specif, num, "0123456789ABCDEF");
	}
	else
	{
		buffered_putnchar(' ', specif->npad_width);
		print_prefix(specif, num == 0);
		buffered_putnchar('0', specif->npad_precision);
		print_digits(specif, num, "0123456789ABCDEF");
	}
	return (0);
}

int			print_data_xx(t_specifier *specif, void *data)
{
	if (specif->minus)
		print_left_aligned(specif, data);
	else
		print_right_aligned(specif, data);
	return (0);
}

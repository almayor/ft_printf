/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_specifier_o.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 20:30:59 by unite             #+#    #+#             */
/*   Updated: 2020/06/30 13:33:48 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

static int	print_digits(t_specifier *specif, unsigned long long num,
						char *radix)
{
	if (num)
		buffered_putull(num, radix);
	else if (!specif->precision.isgiven || specif->precision.value ||
			specif->hash)
		buffered_putchar('0');
	return (0);
}

static int	print_prefix(t_specifier *specif, unsigned long long num)
{
	if (specif->hash && num != 0)
		buffered_puts("0");
	return (0);
}

static int	print_left_aligned(t_specifier *specif, void *data)
{
	unsigned long long	num;

	num = *(unsigned long long *)data;
	if (specif->zero)
	{
		print_prefix(specif, num);
		buffered_putnchar('0', specif->npad_precision);
		buffered_putnchar('0', specif->npad_width);
		print_digits(specif, num, "01234567");
	}
	else
	{
		print_prefix(specif, num);
		buffered_putnchar('0', specif->npad_precision);
		print_digits(specif, num, "01234567");
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
		print_prefix(specif, num);
		buffered_putnchar('0', specif->npad_precision);
		buffered_putnchar('0', specif->npad_width);
		print_digits(specif, num, "01234567");
	}
	else
	{
		buffered_putnchar(' ', specif->npad_width);
		print_prefix(specif, num);
		buffered_putnchar('0', specif->npad_precision);
		print_digits(specif, num, "01234567");
	}
	return (0);
}

int			print_specifier_o(t_specifier *specif, void *data)
{
	if (specif->minus)
		print_left_aligned(specif, data);
	else
		print_right_aligned(specif, data);
	return (0);
}

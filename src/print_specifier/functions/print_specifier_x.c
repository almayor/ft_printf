/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_specifier_x.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 20:30:59 by unite             #+#    #+#             */
/*   Updated: 2020/06/30 17:44:07 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

static int	print_digits(t_specifier *specif, uintmax_t num, char *radix)
{
	if (num != 0 || !specif->precision.isgiven || specif->precision.val)
		pf_putuint(num, radix);
	else if (specif->width.isgiven && specif->zero)
		pf_putchar('0');
	else if (specif->width.isgiven)
		pf_putchar(' ');
	return (0);
}

static int	print_prefix(t_specifier *specif, int iszero)
{
	if (specif->hash && !iszero)
		pf_puts("0x");
	return (0);
}

static int	print_left_aligned(t_specifier *specif, void *data)
{
	uintmax_t	num;

	num = *(uintmax_t *)data;
	if (specif->zero)
	{
		print_prefix(specif, num == 0);
		pf_putnchar('0', specif->npad_precision);
		pf_putnchar('0', specif->npad_width);
		print_digits(specif, num, "0123456789abcdef");
	}
	else
	{
		print_prefix(specif, num == 0);
		pf_putnchar('0', specif->npad_precision);
		print_digits(specif, num, "0123456789abcdef");
		pf_putnchar(' ', specif->npad_width);
	}
	return (0);
}

static int	print_right_aligned(t_specifier *specif, void *data)
{
	uintmax_t	num;

	num = *(uintmax_t *)data;
	if (specif->zero)
	{
		print_prefix(specif, num == 0);
		pf_putnchar('0', specif->npad_precision);
		pf_putnchar('0', specif->npad_width);
		print_digits(specif, num, "0123456789abcdef");
	}
	else
	{
		pf_putnchar(' ', specif->npad_width);
		print_prefix(specif, num == 0);
		pf_putnchar('0', specif->npad_precision);
		print_digits(specif, num, "0123456789abcdef");
	}
	return (0);
}

int			print_specifier_x(t_specifier *specif, void *data)
{
	if (specif->minus)
		print_left_aligned(specif, data);
	else
		print_right_aligned(specif, data);
	return (0);
}

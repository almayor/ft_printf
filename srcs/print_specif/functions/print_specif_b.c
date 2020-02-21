/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_specif_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 20:30:59 by unite             #+#    #+#             */
/*   Updated: 2020/02/21 16:46:09 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

static int	print_digits_proxy(t_specifier *specif, long long num, char *radix)
{
	if (num != 0 || !specif->precision.isgiven || specif->precision.value)
		print_digits_ll(num, radix);
	else if (specif->width.isgiven && specif->zero)
		buffered_nprint('0', 1, 0, 0);
	else if (specif->width.isgiven)
		buffered_nprint(' ', 1, 0, 0);
	return (0);
}

static int	print_sign(t_specifier *specif, int isnegative)
{
	if (isnegative)
		buffered_nprint('-', 1, 0, 0);
	else if (specif->space)
		buffered_nprint(' ', 1, 0, 0);
	else if (specif->plus)
		buffered_nprint('+', 1, 0, 0);
	return (0);
}

static int	print_left_aligned(t_specifier *specif, void *data)
{
	long long	num;

	num = *(long long *)data;
	if (specif->zero)
	{
		print_sign(specif, num < 0);
		buffered_nprint('0', specif->npad_precision, 0, 0);
		buffered_nprint('0', specif->npad_width, 0, 0);
		print_digits_proxy(specif, num, "01");
	}
	else
	{
		print_sign(specif, num < 0);
		buffered_nprint('0', specif->npad_precision, 0, 0);
		print_digits_proxy(specif, num, "01");
		buffered_nprint(' ', specif->npad_width, 0, 0);
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
		buffered_nprint('0', specif->npad_precision, 0, 0);
		buffered_nprint('0', specif->npad_width, 0, 0);
		print_digits_proxy(specif, num, "01");
	}
	else
	{
		buffered_nprint(' ', specif->npad_width, 0, 0);
		print_sign(specif, num < 0);
		buffered_nprint('0', specif->npad_precision, 0, 0);
		print_digits_proxy(specif, num, "01");
	}
	return (0);
}

int			print_specif_i(t_specifier *specif, void *data)
{
	if (specif->minus)
		print_left_aligned(specif, data);
	else
		print_right_aligned(specif, data);
	return (0);
}

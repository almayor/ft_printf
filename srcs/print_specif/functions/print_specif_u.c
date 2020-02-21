/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_specif_u.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 20:30:59 by unite             #+#    #+#             */
/*   Updated: 2020/02/21 02:17:46 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

static int	print_digits_proxy(t_specifier *specif, long long num, char *radix)
{
	if (num != 0 || !specif->precision.isgiven || specif->precision.value)
		print_digits_ull(num, radix);
	else if (specif->width.isgiven && specif->zero)
		buffered_nprint('0', 1, 0, 0);
	else if (specif->width.isgiven)
		buffered_nprint(' ', 1, 0, 0);
	return (0);
}

static int	print_left_aligned(t_specifier *specif, void *data)
{
	unsigned long long	num;

	num = *(unsigned long long *)data;
	if (specif->zero)
	{
		buffered_nprint('0', specif->npad_precision, 0, 0);
		buffered_nprint('0', specif->npad_width, 0, 0);
		print_digits_proxy(specif, num, "0123456789");
	}
	else
	{
		buffered_nprint('0', specif->npad_precision, 0, 0);
		print_digits_proxy(specif, num, "0123456789");
		buffered_nprint(' ', specif->npad_width, 0, 0);
	}
	return (0);
}

static int	print_right_aligned(t_specifier *specif, void *data)
{
	unsigned long long	num;

	num = *(unsigned long long *)data;
	if (specif->zero)
	{
		buffered_nprint('0', specif->npad_precision, 0, 0);
		buffered_nprint('0', specif->npad_width, 0, 0);
		print_digits_proxy(specif, num, "0123456789");
	}
	else
	{
		buffered_nprint(' ', specif->npad_width, 0, 0);
		buffered_nprint('0', specif->npad_precision, 0, 0);
		print_digits_proxy(specif, num, "0123456789");
	}
	return (0);
}

int			print_specif_u(t_specifier *specif, void *data)
{	
	if (specif->minus)
		print_left_aligned(specif, data);
	else
		print_right_aligned(specif, data);
	return (0);
}

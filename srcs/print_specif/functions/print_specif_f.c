/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_specif_f.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 20:30:59 by unite             #+#    #+#             */
/*   Updated: 2020/02/20 22:01:35 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

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
	long double	num;
	size_t		precision;

	num = *(long double *)data;
	precision = specif->precision.isgiven ? specif->precision.value : 6;
	if (specif->zero)
	{
		print_sign(specif, num < 0);
		buffered_nprint('0', specif->npad_width, 0, 0);
		print_digits_lf(num, "0123456789", precision, specif->hash);
	}
	else
	{
		print_sign(specif, num < 0);
		print_digits_lf(num, "0123456789", precision, specif->hash);
		buffered_nprint(' ', specif->npad_width, 0, 0);
	}
	return (0);
}

static int	print_right_aligned(t_specifier *specif, void *data)
{
	long double	num;
	size_t		precision;

	num = *(long double *)data;
	precision = specif->precision.isgiven ? specif->precision.value : 6;
	if (specif->zero)
	{
		print_sign(specif, num < 0);
		buffered_nprint('0', specif->npad_width, 0, 0);
		print_digits_lf(num, "0123456789", precision, specif->hash);
	}
	else
	{
		buffered_nprint(' ', specif->npad_width, 0, 0);
		print_sign(specif, num < 0);
		print_digits_lf(num, "0123456789", precision, specif->hash);
	}
	return (0);
}

int			print_specif_f(t_specifier *specif, void *data)
{
	if (specif->minus)
		print_left_aligned(specif, data);
	else
		print_right_aligned(specif, data);
	return (0);
}

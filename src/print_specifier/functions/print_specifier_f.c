/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_specifier_f.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 20:30:59 by unite             #+#    #+#             */
/*   Updated: 2020/06/30 13:34:08 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"
#include <math.h>

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
	long double	num;

	num = *(long double *)data;
	if (specif->zero)
	{
		print_sign(specif, num < 0);
		buffered_putnchar('0', specif->npad_width);
		buffered_putlf(num, "0123456789", specif->precision.value,
						specif->hash);
	}
	else
	{
		print_sign(specif, num < 0);
		buffered_putlf(num, "0123456789", specif->precision.value,
						specif->hash);
		buffered_putnchar(' ', specif->npad_width);
	}
	return (0);
}

static int	print_right_aligned(t_specifier *specif, void *data)
{
	long double	num;

	num = *(long double *)data;
	if (specif->zero)
	{
		print_sign(specif, num < 0);
		buffered_putnchar('0', specif->npad_width);
		buffered_putlf(num, "0123456789", specif->precision.value,
						specif->hash);
	}
	else
	{
		buffered_putnchar(' ', specif->npad_width);
		print_sign(specif, num < 0);
		buffered_putlf(num, "0123456789", specif->precision.value,
						specif->hash);
	}
	return (0);
}

static int	print_special(t_specifier *specif, void *data)
{
	long double	num;

	num = *(long double *)data;
	if (!specif->minus)
		buffered_putnchar(' ', specif->npad_width);
	if (isnan(num))
		buffered_puts("(null)");
	else if (!isfinite(num) && num > 0)
		buffered_puts("(inf)");
	else if (!isfinite(num) && num < 0)
		buffered_puts("(-inf)");
	if (specif->minus)
		buffered_putnchar(' ', specif->npad_width);
	return (0);
}

int			print_specifier_f(t_specifier *specif, void *data)
{
	long double	num;

	num = *(long double *)data;
	if (isnan(num) || !isfinite(num))
		return (print_special(specif, data));
	if (specif->minus)
		return (print_left_aligned(specif, data));
	else
		return (print_right_aligned(specif, data));
}

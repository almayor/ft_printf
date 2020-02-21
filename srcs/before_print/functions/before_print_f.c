/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   before_print_f.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 20:02:50 by unite             #+#    #+#             */
/*   Updated: 2020/02/21 16:38:41 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"
#include <math.h>

static int	get_npad_width(t_specifier *specif, void *data)
{
	long double	num;
	size_t		precision;
	size_t		sign;
	size_t		dot;
	size_t		nchar;

	specif->npad_width = 0;
	if (!specif->width.isgiven)
		return (0);
	num = *(long double *)data;
	precision = specif->precision.isgiven ? specif->precision.value : 6;
	sign = num < 0 || specif->space || specif->plus;
	dot = (precision > 0) || (specif->hash);
	nchar = sign + get_ndigits_ll(num, 10) + dot + precision;
	if (specif->width.value > nchar)
		specif->npad_width = specif->width.value - nchar;
	return (0);
}

static int	get_npad_width_proxy(t_specifier *specif, void *data)
{
	long double num;

	num = *(long double *)data;
	if (specif->width.isgiven)
		return (0);
	else if (num != num && specif->width.value > 3)
		specif->npad_width -= 3;
	else if (num == INFINITY && specif->width.value > 3)
		specif->npad_width -= 3;
	else if (num == -INFINITY && specif->width.value > 3)
		specif->npad_width -= 3;
	else
		return (get_npad_width(specif, data));
	return (0);
}

int			before_print_f(t_specifier *specif, void *data)
{
	return (get_npad_width_proxy(specif, data));
}

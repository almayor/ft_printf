/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   before_print_i.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 21:17:51 by unite             #+#    #+#             */
/*   Updated: 2020/02/21 02:02:05 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

int	before_print_i(t_specifier *specif, void *data)
{
	long long	num;
	size_t		ndigits;
	size_t		sign;

	num = *(long long *)data;
	ndigits = get_ndigits_ll(num, 10);
	sign = num < 0 || specif->space || specif->plus;
	specif->npad_width = 0;
	specif->npad_precision = 0;
	if (specif->precision.isgiven && specif->precision.value > ndigits)
	{
		specif->npad_precision = specif->precision.value - ndigits;
		if (specif->width.isgiven &&
			specif->width.value > specif->precision.value + sign)
			specif->npad_width = specif->width.value -
			specif->precision.value - sign;
	}
	else
	{
		if (specif->width.isgiven &&
			specif->width.value > ndigits + sign)
			specif->npad_width = specif->width.value -
			ndigits - sign;
	}
	return (0);
}

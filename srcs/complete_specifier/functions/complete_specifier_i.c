/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complete_specifier_i.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 21:17:51 by unite             #+#    #+#             */
/*   Updated: 2020/03/30 01:25:52 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

int	complete_specifier_i(t_specifier *specif, void *data)
{
	long long	num;
	size_t		ndigits;
	size_t		sign;

	num = *(long long *)data;
	if (num)
		ndigits = get_ndigits_ll(num, 10);
	else
		ndigits = !specif->precision.isgiven || specif->precision.value;
	sign = num < 0 || specif->space || specif->plus;
	specif->npad_precision = 0;
	specif->npad_width = 0;
	if (specif->precision.isgiven)
		specif->npad_precision = specif->precision.value -
			MIN(specif->precision.value, ndigits);
	if (specif->width.isgiven)
		specif->npad_width = specif->width.value -
			MIN(specif->width.value, specif->npad_precision + ndigits + sign);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complete_specifier_i.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 21:17:51 by unite             #+#    #+#             */
/*   Updated: 2020/06/30 19:45:05 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

int	complete_specifier_i(t_specifier *specif, void *data)
{
	intmax_t	num;
	size_t		ndigits;
	size_t		sign;

	num = *(intmax_t *)data;
	if (num)
		ndigits = get_ndigits_int(num, 10);
	else
		ndigits = !specif->precision.isgiven || specif->precision.val;
	sign = num < 0 || specif->space || specif->plus;
	specif->npad_precision = 0;
	specif->npad_width = 0;
	if (specif->precision.isgiven)
		specif->npad_precision = specif->precision.val -
			min(specif->precision.val, ndigits);
	if (specif->width.isgiven)
		specif->npad_width = specif->width.val -
			min(specif->width.val, specif->npad_precision + ndigits + sign);
	return (0);
}

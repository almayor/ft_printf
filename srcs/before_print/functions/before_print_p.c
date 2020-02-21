/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   before_print_p.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 21:17:51 by unite             #+#    #+#             */
/*   Updated: 2020/02/20 08:18:19 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

int	before_print_p(t_specifier *specif, void *data)
{
	unsigned long long	num;
	size_t				ndigits;
	size_t				prefix;

	num = *(unsigned long long *)data;
	ndigits = get_ndigits_ull(num, 16);
	prefix = 2;
	specif->npad_width = 0;
	specif->npad_precision = 0;
	if (specif->precision.isgiven && specif->precision.value > ndigits)
	{
		specif->npad_precision = specif->precision.value - ndigits;
		if (specif->width.isgiven &&
			specif->width.value > specif->precision.value + prefix)
			specif->npad_width = specif->width.value -
			specif->precision.value - prefix;
	}
	else
	{
		if (specif->width.isgiven &&
			specif->width.value > ndigits + prefix)
			specif->npad_width = specif->width.value - 
			ndigits - prefix;
	}
	return (0);
}

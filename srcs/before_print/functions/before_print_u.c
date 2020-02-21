/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   before_print_u.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 21:17:51 by unite             #+#    #+#             */
/*   Updated: 2020/02/20 18:20:13 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

int	before_print_u(t_specifier *specif, void *data)
{
	unsigned long long	num;
	size_t				ndigits;

	num = *(unsigned long long *)data;
	ndigits = get_ndigits_ull(num, 10);
	specif->npad_width = 0;
	specif->npad_precision = 0;
	if (specif->precision.isgiven && specif->precision.value > ndigits)
	{
		specif->npad_precision = specif->precision.value - ndigits;
		if (specif->width.isgiven &&
			specif->width.value > specif->precision.value)
			specif->npad_width = specif->width.value -
			specif->precision.value;
	}
	else
	{
		if (specif->width.isgiven &&
			specif->width.value > ndigits)
			specif->npad_width = specif->width.value - 
			ndigits;
	}
	return (0);
}

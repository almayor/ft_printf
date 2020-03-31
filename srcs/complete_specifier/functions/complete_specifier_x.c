/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complete_specifier_x.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 21:17:51 by unite             #+#    #+#             */
/*   Updated: 2020/03/31 17:51:48 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

int	complete_specifier_x(t_specifier *specif, void *data)
{
	unsigned long long	num;
	size_t				ndigits;
	size_t				prefix;

	num = *(unsigned long long *)data;
	ndigits = get_ndigits_ull(num, 16);
	prefix = (specif->hash && num > 0) ? 2 : 0;
	specif->npad_precision = 0;
	specif->npad_width = 0;
	if (specif->precision.isgiven)
		specif->npad_precision = specif->precision.value -
				min(specif->precision.value, ndigits);
	if (specif->width.isgiven)
		specif->npad_width = specif->width.value -
				min(specif->width.value,
					specif->npad_precision + ndigits + prefix);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   before_print_s.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 21:17:51 by unite             #+#    #+#             */
/*   Updated: 2020/02/20 08:18:17 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

int	before_print_s(t_specifier *specif, void *data)
{
	char	*str;
	size_t	strlen;

	str = *(char **)data;
	strlen = ft_strlen(str);
	specif->npad_width = 0;
	if (specif->precision.isgiven && specif->precision.value <= strlen &&
		specif->width.isgiven && specif->width.value > specif->precision.value)
		specif->npad_width = specif->width.value - specif->precision.value;
	else if (specif->width.isgiven && specif->width.value > strlen)
		specif->npad_width = specif->width.value - strlen;
	return (0);
}

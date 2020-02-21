/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_specif_c.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 23:01:54 by unite             #+#    #+#             */
/*   Updated: 2020/02/20 23:04:49 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

int	check_specif_c(t_specifier *specif)
{
	if (specif->plus)
		return (1);
	if (specif->space)
		specif->space = 0;
	if (specif->hash)
		return (1);
	if (specif->zero)
		return (1);
	if (specif->length != NONE)
		return (1);
	if (specif->precision.isgiven)
		specif->precision.isgiven = 0;
	return (0);
}

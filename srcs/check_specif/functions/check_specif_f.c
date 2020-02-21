/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_specif_f.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 23:01:54 by unite             #+#    #+#             */
/*   Updated: 2020/02/20 08:18:51 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

int	check_specif_f(t_specifier *specif)
{
	if (specif->plus && specif->space)
		specif->space = 0;
	if (specif->zero && specif->minus && specif->width.isgiven)
		specif->zero = 0;
	if (specif->length != NONE && specif->length != l && specif->length != L)
		return (1);
	if (specif->precision.isgiven && specif->precision.value > 18)
		return (1);
	return (0);
}

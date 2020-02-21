/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_specif_i.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 23:01:54 by unite             #+#    #+#             */
/*   Updated: 2020/02/20 23:27:26 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

int	check_specif_i(t_specifier *specif)
{
	if (specif->plus && specif->space)
		specif->space = 0;
	if (specif->hash)
		return (1);
	if (specif->zero && specif->minus && specif->width.isgiven)
		specif->zero = 0;
	if (specif->zero && specif->precision.isgiven)
		specif->zero = 0;
	if (specif->length == L)
		return (1);
	return (0);
}

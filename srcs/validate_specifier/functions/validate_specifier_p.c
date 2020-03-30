/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_specif_p.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 23:01:54 by unite             #+#    #+#             */
/*   Updated: 2020/03/29 16:46:37 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

int	validate_specifier_p(t_specifier *specif)
{
	if (specif->plus)
		specif->plus = 0;
	if (specif->space)
		specif->space = 0;
	if (specif->hash)
		return (1);
	if (specif->zero && specif->minus && specif->width.isgiven)
		specif->zero = 0;
	if (specif->length != NONE)
		return (1);
	if (specif->precision.isgiven)
		specif->precision.isgiven = 0;
	return (0);
}

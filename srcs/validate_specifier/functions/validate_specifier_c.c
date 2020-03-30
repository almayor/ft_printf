/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_specif_c.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/29 16:45:15 by unite             #+#    #+#             */
/*   Updated: 2020/03/29 16:46:53 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

int	validate_specifier_c(t_specifier *specif)
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

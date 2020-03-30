/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_specif_f.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/29 16:45:15 by unite             #+#    #+#             */
/*   Updated: 2020/03/29 16:46:48 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

int	validate_specifier_f(t_specifier *specif)
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

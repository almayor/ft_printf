/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_specif_s.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/29 16:45:15 by unite             #+#    #+#             */
/*   Updated: 2020/03/29 16:47:00 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

int	validate_specifier_s(t_specifier *specif)
{
	if (specif->plus)
		return (1);
	if (specif->space)
		return (1);
	if (specif->hash)
		return (1);
	if (specif->zero)
		return (1);
	if (specif->length != NONE)
		return (1);
	return (0);
}

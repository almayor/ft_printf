/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complete_specifier_c.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 21:17:51 by unite             #+#    #+#             */
/*   Updated: 2020/03/31 17:51:07 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

int	complete_specifier_c(t_specifier *specif, void *data)
{
	(void)data;
	if (specif->width.isgiven)
		specif->npad_width = specif->width.value - min(specif->width.value, 1);
	else
		specif->npad_width = 0;
	return (0);
}

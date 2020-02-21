/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   before_print_c.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 21:17:51 by unite             #+#    #+#             */
/*   Updated: 2020/02/20 18:19:00 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

int	before_print_c(t_specifier *specif, void *data)
{
	(void)data;
	specif->npad_width = 0;
	if (specif->width.isgiven && specif->width.value > 1)
		specif->npad_width = specif->width.value - 1;
	return (0);
}

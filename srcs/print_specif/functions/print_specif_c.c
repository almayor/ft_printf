/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_specif_c.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 20:30:59 by unite             #+#    #+#             */
/*   Updated: 2020/02/21 02:58:25 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

int	print_specif_c(t_specifier *specif, void *data)
{
	if (specif->minus)
	{
		buffered_nprint(*(char *)data, 1, 0, 0);
		buffered_nprint(' ', specif->npad_width, 0, 0);
	}
	else
	{
		buffered_nprint(' ', specif->npad_width, 0, 0);
		buffered_nprint(*(char *)data, 1, 0, 0);
	}
	return (0);
}

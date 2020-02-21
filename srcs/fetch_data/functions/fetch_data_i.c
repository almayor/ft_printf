/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fetch_data_i.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 19:17:47 by unite             #+#    #+#             */
/*   Updated: 2020/02/21 01:23:51 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

int	fetch_data_i(t_specifier *specif, void **data, va_list ap)
{
	if (!(*data = malloc(sizeof(long long))))
		return (1);
	if (specif->length == NONE)
		*(long long *)*data = va_arg(ap, int);
	else if (specif->length == h)
		*(long long *)*data = (short int)va_arg(ap, int);
	else if (specif->length == l)
		*(long long *)*data = va_arg(ap, long);
	else if (specif->length == ll)
		*(long long *)*data = va_arg(ap, long long);
	else if (specif->length == hh)
		*(long long *)*data = (signed char)va_arg(ap, int);
	return (0);
}

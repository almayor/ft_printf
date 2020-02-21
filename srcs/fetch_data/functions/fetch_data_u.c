/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fetch_data_u.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 19:17:38 by unite             #+#    #+#             */
/*   Updated: 2020/02/20 18:15:36 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

int	fetch_data_u(t_specifier *specif, void **data, va_list ap)
{
	if (!(*data = malloc(sizeof(unsigned long long))))
		return (1);
	if (specif->length == NONE)
		*(unsigned long long *)*data = va_arg(ap, unsigned);
	else if (specif->length == h)
		*(unsigned long long *)*data = va_arg(ap, unsigned);
	else if (specif->length == l)
		*(unsigned long long *)*data = va_arg(ap, unsigned long);
	else if (specif->length == ll)
		*(unsigned long long *)*data = va_arg(ap, unsigned long long);
	else if (specif->length == hh)
		*(unsigned long long *)*data = va_arg(ap, unsigned);
	return (0);
}

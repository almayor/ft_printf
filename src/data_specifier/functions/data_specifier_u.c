/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_specifier_u.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 19:17:38 by unite             #+#    #+#             */
/*   Updated: 2020/06/29 17:04:04 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

int	data_specifier_u(t_specifier *specif, void **data, va_list ap)
{
	if (!(*data = malloc(sizeof(unsigned long long))))
		return ((errno = ENOMEM));
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

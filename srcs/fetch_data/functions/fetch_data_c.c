/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fetch_data_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 19:17:15 by unite             #+#    #+#             */
/*   Updated: 2020/05/13 18:47:26 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

int	fetch_data_c(t_specifier *specif, void **data, va_list ap)
{
	(void)specif;
	if (!(*data = malloc(sizeof(char))))
		return ((errno = ENOMEM));
	*(char *)*data = va_arg(ap, int);
	return (0);
}

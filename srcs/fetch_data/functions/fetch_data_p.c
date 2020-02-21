/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fetch_data_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 19:17:43 by unite             #+#    #+#             */
/*   Updated: 2020/02/20 18:12:46 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

int	fetch_data_p(t_specifier *specif, void **data, va_list ap)
{
	(void)specif;
	if (!(*data = malloc(sizeof(unsigned long long))))
		return (1);
	*(unsigned long long *)*data = va_arg(ap, unsigned long long);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fetch_data_pc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 19:17:41 by unite             #+#    #+#             */
/*   Updated: 2020/02/20 18:13:28 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

int	fetch_data_pc(t_specifier *specif, void **data, va_list ap)
{
	(void)ap;
	(void)specif;
	if (!(*data = malloc(sizeof(char))))
		return (1);
	*(char *)*data = '%';
	return (0);
}

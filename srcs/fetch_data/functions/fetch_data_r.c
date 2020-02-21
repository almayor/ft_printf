/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fetch_data_r.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 19:17:40 by unite             #+#    #+#             */
/*   Updated: 2020/02/21 17:06:15 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

int	fetch_data_r(t_specifier *specif, void **data, va_list ap)
{
	static char	*null_str = "(null)";
	char		*ptr;
	char		sub;

	(void)specif;
	if (!(*data = malloc(sizeof(char *))))
		return (1);
	if (!(*(char **)*data = va_arg(ap, char *)))
		*(char **)*data = null_str;
	ptr = (char **)*data;
	if (specif->hash)
		sub = '*';
	else
		sub = '.';
	while (**ptr)
	{
		if (!ft_isprint(**ptr))
			**ptr = sub;
		*ptr += 1;
	}
	return (0);
}

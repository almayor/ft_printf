/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fetch_data_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 19:17:40 by unite             #+#    #+#             */
/*   Updated: 2020/05/13 18:47:13 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

int	fetch_data_s(t_specifier *specif, void **data, va_list ap)
{
	static char	*null_str = "(null)";

	(void)specif;
	if (!(*data = malloc(sizeof(char *))))
		return ((errno = ENOMEM));
	if (!(*(char **)*data = va_arg(ap, char *)))
		*(char **)*data = null_str;
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_data_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 20:30:59 by unite             #+#    #+#             */
/*   Updated: 2020/03/31 17:35:44 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

static size_t	get_nchars(t_specifier *specif, size_t strlen)
{
	if (specif->precision.isgiven &&
		specif->precision.value < strlen)
		return (specif->precision.value);
	else
		return (strlen);
}

int				print_data_s(t_specifier *specif, void *data)
{
	char	*str;
	size_t	nchars;
	size_t	i;

	str = *(char **)data;
	nchars = get_nchars(specif, ft_strlen(str));
	if (specif->minus)
	{
		i = 0;
		while (i < nchars)
			buffered_putchar(str[i++]);
		buffered_putnchar(' ', specif->npad_width);
	}
	else
	{
		buffered_putnchar(' ', specif->npad_width);
		i = 0;
		while (i < nchars)
			buffered_putchar(str[i++]);
	}
	return (0);
}

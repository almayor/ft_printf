/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_specif_s.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 20:30:59 by unite             #+#    #+#             */
/*   Updated: 2020/02/20 22:00:04 by unite            ###   ########.fr       */
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

int	print_specif_s(t_specifier *specif, void *data)
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
			buffered_nprint(str[i++], 1, 0, 0);
		buffered_nprint(' ', specif->npad_width, 0, 0);
	}
	else
	{
		buffered_nprint(' ', specif->npad_width, 0, 0);
		i = 0;
		while (i < nchars)
			buffered_nprint(str[i++], 1, 0, 0);
	}
	return (0);
}

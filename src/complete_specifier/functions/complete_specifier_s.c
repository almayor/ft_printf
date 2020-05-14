/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complete_specifier_s.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 21:17:51 by unite             #+#    #+#             */
/*   Updated: 2020/03/31 17:51:17 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

int	complete_specifier_s(t_specifier *specif, void *data)
{
	char	*str;
	size_t	nchar;

	if (!specif->width.isgiven)
		return (0);
	str = *(char **)data;
	if (specif->precision.isgiven)
		nchar = min(specif->precision.value, ft_strlen(str));
	else
		nchar = ft_strlen(str);
	specif->npad_width = specif->width.value - min(specif->width.value, nchar);
	return (0);
}

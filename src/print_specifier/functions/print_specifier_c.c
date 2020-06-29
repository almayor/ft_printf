/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_specifier_c.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 20:30:59 by unite             #+#    #+#             */
/*   Updated: 2020/06/29 17:06:19 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

int	print_specifier_c(t_specifier *specif, void *data)
{
	if (specif->minus)
	{
		buffered_putchar(*(char *)data);
		buffered_putnchar(' ', specif->npad_width);
	}
	else
	{
		buffered_putnchar(' ', specif->npad_width);
		buffered_putchar(*(char *)data);
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 08:17:40 by unite             #+#    #+#             */
/*   Updated: 2020/02/21 21:50:03 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		rc;

	va_start(ap, format);
	rc = ft_vprintf(format, ap);
	va_end(ap);
	return (rc);
}

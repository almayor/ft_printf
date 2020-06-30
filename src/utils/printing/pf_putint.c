/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 22:44:49 by unite             #+#    #+#             */
/*   Updated: 2020/06/30 23:12:34 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

int	pf_putint(intmax_t num, const char *radix)
{
	size_t		base_len;
	intmax_t	factor;

	base_len = ft_strlen(radix);
	factor = 1;
	while (num / factor >= (intmax_t)base_len && num >= 0)
		factor *= base_len;
	while (num / factor <= -(intmax_t)base_len && num < 0)
		factor *= base_len;
	while (factor >= 1)
	{
		if (num >= 0)
			pf_putchar(radix[num / factor]);
		else
			pf_putchar(radix[-(num / factor)]);
		num %= factor;
		factor /= base_len;
	}
	return (0);
}

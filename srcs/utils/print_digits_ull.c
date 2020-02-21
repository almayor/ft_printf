/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_digits_ull.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 22:44:49 by unite             #+#    #+#             */
/*   Updated: 2020/02/20 22:01:55 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

int	print_digits_ull(unsigned long long num, char *radix)
{
	size_t				base_len;
	unsigned long long	factor;

	base_len = ft_strlen(radix);
	factor = 1;
	while (num / factor >= base_len)
		factor *= base_len;
	while (factor >= 1)
	{
		buffered_nprint(radix[num / factor], 1, 0, 0);
		num %= factor;
		factor /= base_len;
	}
	return (0);
}

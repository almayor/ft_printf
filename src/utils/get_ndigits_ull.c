/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ndigits_ull.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 22:44:49 by unite             #+#    #+#             */
/*   Updated: 2020/02/21 02:13:13 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

size_t	get_ndigits_ull(unsigned long long num, size_t base_len)
{
	size_t				ndigits;
	unsigned long long	factor;

	if (num == 0)
		return (1);
	ndigits = 0;
	factor = base_len;
	while (num >= 1)
	{
		ndigits += 1;
		num /= factor;
	}
	return (ndigits);
}

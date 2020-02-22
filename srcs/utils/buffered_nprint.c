/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffered_nprint.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 21:09:50 by unite             #+#    #+#             */
/*   Updated: 2020/02/22 19:19:20 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

size_t	buffered_nprint(char c, size_t n, int flush, int cleanup)
{
	size_t	i;
	size_t	nprinted;

	if (flush || cleanup)
		return (buffered_print(0, flush, cleanup));
	i = 0;
	nprinted = 0;
	while (i < n)
	{
		nprinted = buffered_print(c, flush, cleanup);
		++i;
	}
	return (nprinted);
}

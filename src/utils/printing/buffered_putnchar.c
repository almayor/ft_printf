/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffered_putnchar.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 21:09:50 by unite             #+#    #+#             */
/*   Updated: 2020/03/29 16:41:01 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

size_t	buffered_putnchar(char c, size_t n)
{
	size_t	i;
	size_t	nprinted;

	nprinted = 0;
	i = 0;
	while (i < n)
	{
		nprinted = buffered_putchar(c);
		i++;
	}
	return (nprinted);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putnchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 21:09:50 by unite             #+#    #+#             */
/*   Updated: 2020/06/30 23:12:30 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

int	pf_putnchar(char c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		pf_putchar(c);
		i++;
	}
	return (0);
}
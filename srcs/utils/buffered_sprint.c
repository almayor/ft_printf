/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffered_sprint.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 21:09:50 by unite             #+#    #+#             */
/*   Updated: 2020/02/21 21:55:28 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

size_t	buffered_sprint(char *str, int flush, int cleanup)
{
	size_t	i;
	size_t	nprinted;

	if (flush || cleanup)
		return buffered_print(0, flush, cleanup);
	i = 0;	
	while (str[i])
	{
		nprinted = buffered_print(str[i], flush, cleanup);
		i++;
	}
	return (nprinted);
}

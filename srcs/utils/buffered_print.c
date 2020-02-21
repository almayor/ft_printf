/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffered_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 19:02:14 by unite             #+#    #+#             */
/*   Updated: 2020/02/21 03:11:46 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

size_t buffered_print(unsigned char c, int flush, int cleanup)
{
	static unsigned char		buffer[BUFFER_SIZE];
	static size_t				inbuffer = 0;
	static size_t				nprinted = 0;
	size_t						tmp;

	if (inbuffer == BUFFER_SIZE || flush)
	{
		write(1, buffer, inbuffer);
		inbuffer = 0;
	}
	if (!cleanup && !flush)
	{
		buffer[inbuffer] = c;
		inbuffer += 1;
		nprinted += 1;
		return (nprinted);
	}
	else
	{
		tmp = nprinted;
		inbuffer = 0;
		nprinted = 0;
		return (tmp);
	}
}

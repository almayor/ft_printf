/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffered_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 19:02:14 by unite             #+#    #+#             */
/*   Updated: 2020/02/22 18:37:15 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

static int	g_fd = 1;

int			get_fd(void)
{
	return (g_fd);
}

void		set_fd(int fd)
{
	g_fd = fd;
}

size_t 		buffered_print(char c, int flush, int cleanup)
{
	static char		buffer[BUFFER_SIZE];
	static size_t	inbuffer = 0;
	static size_t	nprinted = 0;
	size_t			tmp;

	if (inbuffer == BUFFER_SIZE || flush)
	{
		write(g_fd, buffer, inbuffer);
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

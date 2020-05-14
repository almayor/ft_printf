/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffered_putchar.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 19:02:14 by unite             #+#    #+#             */
/*   Updated: 2020/05/14 23:09:09 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

static t_buffer		g_buffer;
static size_t		g_nprinted;
static int			g_fd = 1;

int			get_fd(void)
{
	return (g_fd);
}

void		set_fd(int fd)
{
	g_fd = fd;
}

void		cleanup_buffer(void)
{
	g_buffer.inbuffer = 0;
	g_nprinted = 0;
	g_fd = 1;
}

size_t		flush_buffer(void)
{
	write(g_fd, g_buffer.buffer, g_buffer.inbuffer);
	g_buffer.inbuffer = 0;
	return (g_nprinted);
}

size_t		buffered_putchar(char c)
{
	if (g_buffer.inbuffer == BUFFER_SIZE)
	{
		write(g_fd, g_buffer.buffer, BUFFER_SIZE);
		g_buffer.inbuffer = 0;
		g_nprinted += BUFFER_SIZE;
	}
	g_buffer.buffer[g_buffer.inbuffer] = c;
	g_buffer.inbuffer += 1;
	g_nprinted += 1;
	return (g_nprinted);
}

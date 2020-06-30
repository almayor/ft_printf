/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffered_putchar.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 19:02:14 by unite             #+#    #+#             */
/*   Updated: 2020/06/30 14:31:05 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

static t_mode		g_mode = T_FILE;
static char			g_buffer[BUFFER_SIZE];
static size_t		g_inbuffer;
static size_t		g_nprinted;
static int			g_fd = 1;
static char			*g_string;
static size_t		g_string_size;

void		set_fd(int fd)
{
	g_fd = fd;
	g_mode = T_FILE;
}

void		set_output_string(char *str, size_t size)
{
	g_string = str;
	g_string_size = size;
	g_mode = T_STRING;
}

void		cleanup_buffer(void)
{
	g_inbuffer = 0;
	g_nprinted = 0;
	set_fd(1);
}

size_t		flush_buffer(void)
{
	if (g_mode == T_FILE)
		write(g_fd, g_buffer, g_inbuffer);
	if (g_mode == T_STRING && g_string_size > 0)
		g_string[g_nprinted] = 0;
	g_nprinted += g_inbuffer;
	g_inbuffer = 0;
	return (g_nprinted);
}

size_t		buffered_putchar(char c)
{
	if (g_mode == T_STRING)
	{
		if (g_nprinted + 1 < g_string_size)
			g_string[g_nprinted] = c;
		g_nprinted++;
	}
	if (g_mode == T_FILE)
	{
		if (g_inbuffer == BUFFER_SIZE)
			flush_buffer();
		g_buffer[g_inbuffer++] = c;
	}
	return (g_nprinted + g_inbuffer);
}

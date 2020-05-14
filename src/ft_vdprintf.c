/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vdprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 08:17:40 by unite             #+#    #+#             */
/*   Updated: 2020/02/21 21:52:06 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

int	ft_vdprintf(int fd, const char *format, va_list ap)
{
	int rc;
	int	fd_bk;

	fd_bk = get_fd();
	set_fd(fd);
	rc = ft_vprintf(format, ap);
	set_fd(fd_bk);
	return (rc);
}

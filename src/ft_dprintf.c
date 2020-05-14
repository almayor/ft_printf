/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 08:17:40 by unite             #+#    #+#             */
/*   Updated: 2020/02/21 21:46:09 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

int	ft_dprintf(int fd, const char *format, ...)
{
	va_list	ap;
	int		rc;
	int		fd_bk;

	fd_bk = get_fd();
	set_fd(fd);
	va_start(ap, format);
	rc = ft_vdprintf(fd, format, ap);
	va_end(ap);
	set_fd(fd_bk);
	return (rc);
}

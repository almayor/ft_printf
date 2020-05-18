/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 08:17:40 by unite             #+#    #+#             */
/*   Updated: 2020/05/18 03:37:49 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

/*
** @ingroup ft_printf
** @brief Replicates behaviour of `dprintf(3)`.
** @param[in] fd File descriptor where to print output.
** @param[in] format Format string that specifies how subsequent arguments
** are converted for output
** @param[in] ... Variadic arguments
** @return Number of characters printed or `-1` if an error occurs. Additionaly,
** in case of an error, `errno` is set to `ENOMEM` (memory allocation error),
** `EINVAL` (invalid format placeholder specification), `ENOTSUP` (type field
** value not supported).
*/

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

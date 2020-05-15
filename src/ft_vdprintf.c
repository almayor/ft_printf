/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vdprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 08:17:40 by unite             #+#    #+#             */
/*   Updated: 2020/05/15 03:36:10 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

/*
** @ingroup ft_printf
** @brief Replicates behaviour of `vdprintf(3)`.
** @param[in] fd File descriptor where to print output
** @param[in] format Format string that specifies how subsequent arguments 
** are converted for output
** @param[in] ap A variable used by `stdarg(3)` to step through a list of
** variadic arguments.
** @return Number of characters printed or `-1` if an error occurs. Additionaly,
** in case of an error, `errno` is set to `ENOMEM` (memory allocation error),
** `EINVAL` (invalid format placeholder specification), `ENOTSUP` (type field
** value not supported) or other values set by `write(2)` (e.g. due to an
** invalid file descriiptor).
*/
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

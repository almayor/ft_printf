/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vsprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 08:17:40 by unite             #+#    #+#             */
/*   Updated: 2020/06/30 14:31:30 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

/*
** @ingroup ft_printf
** @brief Replicates behaviour of `vsprintf(3)`.
** @param[in] str String where to print output.
** @param[in] format Format string that specifies how subsequent arguments
** are converted for output
** @param[in] ap A variable used by `stdarg(3)` to step through a list of
** variadic arguments.
** @return Number of characters printed or `-1` if an error occurs. Additionaly,
** in case of an error, `errno` is set to `ENOMEM` (memory allocation error),
** `EINVAL` (invalid format placeholder specification), `ENOTSUP` (type field
** value not supported).
*/

int	ft_vsprintf(char *str, const char *format, va_list ap)
{
	set_output_string(str, (size_t)INT_MAX + 1);
	return (ft_vprintf(format, ap));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 08:17:40 by unite             #+#    #+#             */
/*   Updated: 2020/05/23 17:55:51 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

static void	formatted_print(const char **format, va_list ap)
{
	static t_specifier	specif;
	void				*data;

	data = NULL;
	ft_memset(&specif, 0, sizeof(t_specifier));
	(void)(parse_specifier(&specif, format, ap) ||
		validate_specifier(&specif) ||
		fetch_data(&specif, &data, ap) ||
		complete_specifier(&specif, data) ||
		print_data(&specif, data));
	if (data)
		free(data);
}

static void	colors_print(const char **format, va_list ap)
{
	(void)ap;
	if (ft_strnequ(*format, "{eoc}", 5))
		buffered_puts(KNRM);
	else if (ft_strnequ(*format, "{cyan}", 6))
		buffered_puts(KCYN);
	else if (ft_strnequ(*format, "{red}", 5))
		buffered_puts(KRED);
	else if (ft_strnequ(*format, "{green}", 7))
		buffered_puts(KGRN);
	else if (ft_strnequ(*format, "{yellow}", 8))
		buffered_puts(KYEL);
	else if (ft_strnequ(*format, "{blue}", 6))
		buffered_puts(KBLU);
	else if (ft_strnequ(*format, "{magenta}", 9))
		buffered_puts(KMAG);
	else
	{
		errno = ENOTSUP;
		return ;
	}
	while (**format != '}')
		*format += 1;
	*format += 1;
}

static void	simple_print(const char **format)
{
	buffered_putchar(**format);
	*format += 1;
}

/*
** @ingroup ft_printf
** @brief Replicates behaviour of `vprintf(3)`.
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

int			ft_vprintf(const char *format, va_list ap)
{
	size_t		nprinted;
	static void	(*const dispatch_table[128])(const char **, va_list) = {
		['%'] = &formatted_print,
		['{'] = &colors_print,
	};

	while (*format)
	{
		if (*format < 0 || !dispatch_table[(unsigned char)*format])
			simple_print(&format);
		else
			dispatch_table[(unsigned char)*format](&format, ap);
		if (errno)
		{
			cleanup_buffer();
			return (-1);
		}
	}
	nprinted = flush_buffer();
	cleanup_buffer();
	return (nprinted);
}

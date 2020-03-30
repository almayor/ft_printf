/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 08:17:40 by unite             #+#    #+#             */
/*   Updated: 2020/03/30 15:47:26 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

static int	formatted_print(const char **format, va_list ap)
{
	static t_specifier	specif;
	void 				*data;
	int					rc;

	data = 0;
	ft_memset(&specif, 0, sizeof(t_specifier));
	rc = (parse_specifier(&specif, format, ap) ||
		  validate_specifier(&specif) ||
		  fetch_data(&specif, &data, ap) ||
		  complete_specifier(&specif, data) ||
		  print_data(&specif, data));
	if (data)
		free(data);
	return (rc);
}

static int	colors_print(const char **format, va_list ap)
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
		return (1);
	while (**format != '}')
		*format += 1;
	*format += 1;
	return (0);
}

static int	simple_print(const char **format)
{
	buffered_putchar(**format);
	*format += 1;
	return (0);
}

int			ft_vprintf(const char *format, va_list ap)
{
	size_t		nprinted;
	static int	(* const dispatch_table[128])(const char **, va_list) =
	{
		['%'] = &formatted_print,
		['{'] = &colors_print,
	};

	while (*format)
	{
		if (*format < 0 || !dispatch_table[(unsigned char)*format])
			simple_print(&format);
		else if (dispatch_table[(unsigned char)*format](&format, ap))
		{
			write(2, "(error)\n", 8);
			cleanup_buffer();
			return (-1);
		}
	}
	nprinted = flush_buffer();
	cleanup_buffer();
	return (nprinted);
}

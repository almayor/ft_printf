/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 08:17:40 by unite             #+#    #+#             */
/*   Updated: 2020/02/21 02:23:43 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

int specif_print(const char **format, va_list ap)
{
	void 		*data;
	t_specifier	*specif;
	int			rc;

	data = 0;
	if (!(specif = ft_memalloc(sizeof(t_specifier))) ||
		parse_specif(specif, format, ap) ||
		check_specif(specif) ||
		fetch_data(specif, &data, ap) ||
		before_print(specif, data) ||
		print_specif(specif, data))
		rc = 1;
	else
		rc = 0;
	if (specif)
		free(specif);
	if (data)
		free(data);
	return (rc);
}

int	colors_print(const char **format, va_list ap)
{
	(void)ap;
	if (ft_strnequ(*format, "{eoc}", 5))
		buffered_sprint(KNRM, 0, 0);
	else if (ft_strnequ(*format, "{cyan}", 6))
		buffered_sprint(KCYN, 0, 0);
	else if (ft_strnequ(*format, "{red}", 5))
		buffered_sprint(KRED, 0, 0);
	else if (ft_strnequ(*format, "{green}", 7))
		buffered_sprint(KGRN, 0, 0);
	else if (ft_strnequ(*format, "{yellow}", 8))
		buffered_sprint(KYEL, 0, 0);
	else if (ft_strnequ(*format, "{blue}", 6))
		buffered_sprint(KBLU, 0, 0);
	else if (ft_strnequ(*format, "{magenta}", 9))
		buffered_sprint(KMAG, 0, 0);
	while (**format != '}')
		*format += 1;
	*format += 1;
	return (0);
}

int simple_print(const char **format, va_list ap)
{
	(void)ap;
	buffered_nprint(**format, 1, 0, 0);
	*format += 1;
	return (0);
}

int print_dispatcher(const char **format, va_list ap)
{
	if (**format == '%')
		return (specif_print(format, ap));
	if (**format == '{')
		return (colors_print(format, ap));
	else
		return (simple_print(format, ap));
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;

	va_start(ap, format);
	while (*format)
	{	
		if (print_dispatcher(&format, ap))
		{
			va_end(ap);
			buffered_sprint("(error)\n", 0, 1);
			return (-1);	
		}
	}
	va_end(ap);
	return (buffered_nprint(0, 0, 1, 1));
}

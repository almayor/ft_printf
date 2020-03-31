/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fetch_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 21:00:44 by unite             #+#    #+#             */
/*   Updated: 2020/03/31 17:31:37 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

int	fetch_data_c(t_specifier *specif, void **data, va_list ap);
int	fetch_data_f(t_specifier *specif, void **data, va_list ap);
int	fetch_data_i(t_specifier *specif, void **data, va_list ap);
int	fetch_data_p(t_specifier *specif, void **data, va_list ap);
int	fetch_data_pc(t_specifier *specif, void **data, va_list ap);
int	fetch_data_s(t_specifier *specif, void **data, va_list ap);
int	fetch_data_u(t_specifier *specif, void **data, va_list ap);

int	fetch_data(t_specifier *specif, void **data, va_list ap)
{
	static int (*const dispatch_table[128])(t_specifier *, void **, va_list) = {
		['c'] = &fetch_data_c,
		['s'] = &fetch_data_s,
		['i'] = &fetch_data_i,
		['d'] = &fetch_data_i,
		['x'] = &fetch_data_u,
		['X'] = &fetch_data_u,
		['o'] = &fetch_data_u,
		['u'] = &fetch_data_u,
		['f'] = &fetch_data_f,
		['p'] = &fetch_data_p,
		['%'] = &fetch_data_pc,
		['b'] = &fetch_data_i,
	};

	if (dispatch_table[specif->formatid])
		return (dispatch_table[specif->formatid](specif, data, ap));
	else
		return (1);
}

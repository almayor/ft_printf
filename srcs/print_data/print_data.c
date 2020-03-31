/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 21:00:33 by unite             #+#    #+#             */
/*   Updated: 2020/03/31 17:33:41 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

int	print_data_c(t_specifier *specif, void *data);
int	print_data_f(t_specifier *specif, void *data);
int	print_data_i(t_specifier *specif, void *data);
int	print_data_o(t_specifier *specif, void *data);
int	print_data_p(t_specifier *specif, void *data);
int	print_data_s(t_specifier *specif, void *data);
int	print_data_u(t_specifier *specif, void *data);
int	print_data_x(t_specifier *specif, void *data);
int	print_data_xx(t_specifier *specif, void *data);
int	print_data_b(t_specifier *specif, void *data);

int	print_data(t_specifier *specif, void *data)
{
	static int		(*const dispatch_table[128])(t_specifier *, void *) = {
		['c'] = &print_data_c,
		['s'] = &print_data_s,
		['i'] = &print_data_i,
		['d'] = &print_data_i,
		['x'] = &print_data_x,
		['X'] = &print_data_xx,
		['o'] = &print_data_o,
		['u'] = &print_data_u,
		['f'] = &print_data_f,
		['p'] = &print_data_p,
		['%'] = &print_data_c,
		['b'] = &print_data_b
	};

	if (dispatch_table[specif->formatid])
		return (dispatch_table[specif->formatid](specif, data));
	else
		return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   before_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 21:00:33 by unite             #+#    #+#             */
/*   Updated: 2020/02/21 22:13:29 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

int	before_print_c(t_specifier *specif, void *data);
int	before_print_f(t_specifier *specif, void *data);
int	before_print_i(t_specifier *specif, void *data);
int	before_print_o(t_specifier *specif, void *data);
int	before_print_p(t_specifier *specif, void *data);
int	before_print_s(t_specifier *specif, void *data);
int	before_print_u(t_specifier *specif, void *data);
int	before_print_x(t_specifier *specif, void *data);
int	before_print_b(t_specifier *specif, void *data);

int before_print(t_specifier *specif, void *data)
{
	static int 		(*dispatch_table[128])(t_specifier *, void *) =
	{
		['c'] = &before_print_c,
		['s'] = &before_print_s,
		['i'] = &before_print_i,
		['d'] = &before_print_i,
		['x'] = &before_print_x,
		['X'] = &before_print_x,
		['o'] = &before_print_o,
		['u'] = &before_print_u,
		['f'] = &before_print_f,
		['p'] = &before_print_p,
		['%'] = &before_print_c,
		['b'] = &before_print_b,
	};

	if (dispatch_table[specif->formatid])
		return (dispatch_table[specif->formatid](specif, data));
	else
		return (1);
}

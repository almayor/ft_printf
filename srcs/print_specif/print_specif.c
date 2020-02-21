/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_specif.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 21:00:33 by unite             #+#    #+#             */
/*   Updated: 2020/02/21 22:13:45 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

int	print_specif_c(t_specifier *specif, void *data);
int	print_specif_f(t_specifier *specif, void *data);
int	print_specif_i(t_specifier *specif, void *data);
int	print_specif_o(t_specifier *specif, void *data);
int	print_specif_p(t_specifier *specif, void *data);
int	print_specif_s(t_specifier *specif, void *data);
int	print_specif_u(t_specifier *specif, void *data);
int	print_specif_x(t_specifier *specif, void *data);
int	print_specif_xx(t_specifier *specif, void *data);
int	print_specif_b(t_specifier *specif, void *data);

int print_specif(t_specifier *specif, void *data)
{
	static int 		(*dispatch_table[128])(t_specifier *, void *) =
	{
		['c'] = &print_specif_c,
		['s'] = &print_specif_s,
		['i'] = &print_specif_i,
		['d'] = &print_specif_i,
		['x'] = &print_specif_x,
		['X'] = &print_specif_xx,
		['o'] = &print_specif_o,
		['u'] = &print_specif_u,
		['f'] = &print_specif_f,
		['p'] = &print_specif_p,
		['%'] = &print_specif_c,
		['b'] = &print_specif_b
	};

	if (dispatch_table[specif->formatid])
		return (dispatch_table[specif->formatid](specif, data));
	else
		return (1);
}

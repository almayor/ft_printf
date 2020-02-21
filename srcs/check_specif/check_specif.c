/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_specif.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 21:00:33 by unite             #+#    #+#             */
/*   Updated: 2020/02/21 17:06:28 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

int	check_specif_c(t_specifier *specif);
int	check_specif_f(t_specifier *specif);
int	check_specif_i(t_specifier *specif);
int	check_specif_p(t_specifier *specif);
int	check_specif_s(t_specifier *specif);
int	check_specif_u(t_specifier *specif);
int	check_specif_x(t_specifier *specif);
int	check_specif_b(t_specifier *specif);
int	check_specif_r(t_specifier *specif);

int check_specif(t_specifier *specif)
{
	static int 		(*dispatch_table[128])(t_specifier *) =
	{
		['c'] = &check_specif_c,
		['s'] = &check_specif_s,
		['i'] = &check_specif_i,
		['d'] = &check_specif_i,
		['x'] = &check_specif_x,
		['X'] = &check_specif_x,
		['o'] = &check_specif_x,
		['u'] = &check_specif_u,
		['f'] = &check_specif_f,
		['p'] = &check_specif_p,
		['%'] = &check_specif_c,
		['b'] = &check_specif_b,
		['r'] = &check_specif_r
	};

	if (dispatch_table[specif->formatid])
		return (dispatch_table[specif->formatid](specif));
	else
		return (1);
}

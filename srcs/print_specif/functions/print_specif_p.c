/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_specif_p.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 20:30:59 by unite             #+#    #+#             */
/*   Updated: 2020/02/20 22:00:28 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

static int	print_prefix(t_specifier *specif)
{
	(void)specif;
	buffered_nprint('0', 1, 0, 0);
	buffered_nprint('x', 1, 0, 0);
	return (0);
}

static int	print_left_aligned(t_specifier *specif, void *data)
{
	unsigned long long	num;

	num = *(unsigned long long *)data;
	if (specif->zero)
	{
		print_prefix(specif);
		buffered_nprint('0', specif->npad_precision, 0, 0);
		buffered_nprint('0', specif->npad_width, 0, 0);
		print_digits_ull(num, "0123456789abcdef");
	}
	else
	{
		print_prefix(specif);
		buffered_nprint('0', specif->npad_precision, 0, 0);
		print_digits_ull(num, "0123456789abcdef");
		buffered_nprint(' ', specif->npad_width, 0, 0);
	}
	return (0);
}

static int	print_right_aligned(t_specifier *specif, void *data)
{
	unsigned long long	num;

	num = *(unsigned long long *)data;
	if (specif->zero)
	{
		print_prefix(specif);
		buffered_nprint('0', specif->npad_precision, 0, 0);
		buffered_nprint('0', specif->npad_width, 0, 0);
		print_digits_ull(num, "0123456789abcdef");
	}
	else
	{
		buffered_nprint(' ', specif->npad_width, 0, 0);
		print_prefix(specif);
		buffered_nprint('0', specif->npad_precision, 0, 0);
		print_digits_ull(num, "0123456789abcdef");
	}
	return (0);
}

int			print_specif_p(t_specifier *specif, void *data)
{
	if (specif->minus)
		print_left_aligned(specif, data);
	else
		print_right_aligned(specif, data);
	return (0);
}

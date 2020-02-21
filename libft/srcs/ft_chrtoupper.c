/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chrtoupper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 23:12:40 by unite             #+#    #+#             */
/*   Updated: 2019/09/06 23:16:12 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	ft_chrtoupper(char c)
{
	if (c >= 'a' && c <= 'z')
		return (c + 'A' - 'a');
	else
		return (c);
}

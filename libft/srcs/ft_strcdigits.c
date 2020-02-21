/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcdigits.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 16:12:30 by unite             #+#    #+#             */
/*   Updated: 2019/12/20 16:12:41 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strcdigits(char *str)
{
	size_t	count;

	count = 0;
	while (*str)
	{
		if (ft_chrisdigit(*str))
			count++;
		str++;
	}
	return (count);
}

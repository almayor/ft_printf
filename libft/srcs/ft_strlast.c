/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 04:51:37 by unite             #+#    #+#             */
/*   Updated: 2019/10/01 04:52:31 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	ft_strlast(char const *str)
{
	size_t	i;

	i = 0;
	while (str[i + 1])
		i++;
	return (str[i]);
}

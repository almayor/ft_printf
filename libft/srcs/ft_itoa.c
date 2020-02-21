/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 14:16:34 by unite             #+#    #+#             */
/*   Updated: 2020/01/03 20:01:47 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		*ft_itoa(int n)
{
	char	*str1;
	char	*str2;
	int		neg;
	size_t	i;

	if (!(str1 = ft_strnew(ft_intlen(n))))
		return (NULL);
	i = 0;
	neg = (n < 0);
	str1[i++] = ft_abs(n % 10) + '0';
	n = ft_abs(n / 10);
	while (n > 9)
	{
		str1[i++] = n % 10 + '0';
		n /= 10;
	}
	str1[i++] = n % 10 + '0';
	if (neg)
		str1[i++] = '-';
	str2 = ft_strrev(str1);
	free(str1);
	return (str2);
}

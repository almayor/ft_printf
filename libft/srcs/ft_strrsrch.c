/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrsrch.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 18:10:35 by unite             #+#    #+#             */
/*   Updated: 2019/09/22 20:41:33 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrsrch(const char *s, int (*f)(char))
{
	size_t	i;

	if (!f || !s)
		return (NULL);
	i = ft_strlen(s);
	while (i > 0)
	{
		if (f(s[i - 1]))
			return ((char *)(s + i - 1));
		i--;
	}
	return (NULL);
}

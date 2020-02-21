/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_variadic.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 03:15:42 by unite             #+#    #+#             */
/*   Updated: 2020/01/04 19:40:45 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>

char	*ft_strjoin_variadic(const char *str, ...)
{
	va_list	arglist;
	char	*s1;
	char	*s2;

	if (!(s1 = ft_strdup(str)))
		return (NULL);
	va_start(arglist, str);
	s2 = va_arg(arglist, char *);
	while (s2)
	{
		if (!(s1 = ft_strjoin(s1, s2)))
			return (NULL);
		s2 = va_arg(arglist, char *);
	}
	va_end(arglist);
	return (s1);
}

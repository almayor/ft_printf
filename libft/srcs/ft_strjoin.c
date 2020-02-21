/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 11:53:04 by unite             #+#    #+#             */
/*   Updated: 2019/10/06 00:13:09 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*s_joined;

	if (!s1 && !s2)
		return (NULL);
	else if (!s1)
		return (char *)s2;
	else if (!s2)
		return (char *)s1;
	if (!(s_joined = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
		return (NULL);
	s_joined = ft_strcpy(s_joined, s1);
	s_joined = ft_strcat(s_joined, s2);
	return (s_joined);
}

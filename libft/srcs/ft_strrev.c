/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 14:44:25 by unite             #+#    #+#             */
/*   Updated: 2019/09/06 21:42:52 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(const char *s)
{
	size_t	len;
	size_t	i;
	char	*srev;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	if (!(srev = ft_strnew(len)))
		return (NULL);
	i = 0;
	while (i < len)
	{
		srev[i] = s[len - i - 1];
		i++;
	}
	return (srev);
}

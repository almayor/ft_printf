/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 11:57:03 by unite             #+#    #+#             */
/*   Updated: 2019/10/01 05:16:38 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isnotspace(char c)
{
	return (c != ' ' && c != '\n' && c != '\t');
}

char		*ft_strtrim(char const *s)
{
	const char	*start;
	const char	*end;

	start = ft_strsrch(s, &ft_isnotspace);
	if (!start)
		return (ft_strdup(""));
	end = ft_strrsrch(s, &ft_isnotspace) + 1;
	return (ft_strndup(start, end - start));
}

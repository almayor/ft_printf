/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 22:51:50 by unite             #+#    #+#             */
/*   Updated: 2020/02/20 18:33:40 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_chrisnotalnum(char c)
{
	return (!ft_chrisalnum(c));
}

char		*ft_strcapitalize(char *str)
{
	char	*start;
	char	*end;

	str = ft_strmap_inplace(str, &ft_chrtolower);
	start = ft_strsrch(str, &ft_chrisalnum);
	while (start)
	{
		*start = ft_toupper(*start);
		end = ft_strsrch(start, &ft_chrisnotalnum);
		start = ft_strsrch(end, &ft_chrisalnum);
	}
	return (str);
}

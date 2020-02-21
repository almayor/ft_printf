/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 13:31:18 by unite             #+#    #+#             */
/*   Updated: 2019/09/20 23:32:36 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_getwcount(const char *str, char delim)
{
	size_t	wcount;
	char	*start;
	char	*end;

	wcount = 0;
	start = ft_strnotchr(str, delim);
	while (start)
	{
		wcount++;
		end = ft_strchr(start, delim);
		start = ft_strnotchr(end, delim);
	}
	return (wcount);
}

static void	free_splitarr(char **arr)
{
	int i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

char		**ft_strsplit(char const *str, char delim)
{
	char		**tab;
	size_t		wcount;
	size_t		i;
	char		*start;
	char		*end;

	wcount = ft_getwcount(str, delim);
	if (!(tab = ft_memalloc(sizeof(char *) * (wcount + 1))))
		return (NULL);
	i = 0;
	end = (char *)str;
	while (i < wcount)
	{
		start = ft_strnotchr(end, delim);
		end = ft_strchr(start, delim);
		tab[i] = end ? ft_strndup(start, end - start) : ft_strdup(start);
		if (!tab[i])
		{
			free_splitarr(tab);
			return (NULL);
		}
		i++;
	}
	tab[i++] = NULL;
	return (tab);
}

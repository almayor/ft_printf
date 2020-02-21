/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strprepend.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 22:59:48 by unite             #+#    #+#             */
/*   Updated: 2020/01/03 20:04:36 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int		ft_strprepend(char **str1, char *str2)
{
	char	*str_join;
	size_t	size1;
	size_t	size2;

	size1 = ft_strlen(*str1);
	size2 = ft_strlen(str2);
	if (!(str_join = ft_strnew(size1 + size2)))
		return (1);
	str_join = ft_strcat(str_join, str2);
	str_join = ft_strcat(str_join, *str1);
	free(*str1);
	free(str2);
	*str1 = str_join;
	return (0);
}

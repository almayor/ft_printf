/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <unite@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 22:59:28 by unite             #+#    #+#             */
/*   Updated: 2020/02/10 11:44:25 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

int	ft_strappend(char **str1, char *str2)
{
	char	*str_join;
	size_t	size1;
	size_t	size2;

	size1 = ft_strlen(*str1);
	size2 = ft_strlen(str2);
	if (!(str_join = ft_strnew(size1 + size2)))
		return (1);
	str_join = ft_strcat(str_join, *str1);
	str_join = ft_strcat(str_join, str2);
	free(*str1);
	free(str2);
	*str1 = str_join;
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpsub.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 23:40:16 by unite             #+#    #+#             */
/*   Updated: 2019/10/02 03:03:40 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strpsub(const char *start, const char *end)
{
	char	*sub;

	if (!start || !end || !(sub = ft_strnew(end - start)))
		return (NULL);
	ft_strncpy(sub, start, end - start);
	return (sub);
}

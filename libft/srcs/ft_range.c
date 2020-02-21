/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 00:11:22 by unite             #+#    #+#             */
/*   Updated: 2019/09/21 00:14:54 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	*ft_range(int lbound, int ubound)
{
	int	*range;
	int i;

	if (lbound <= ubound ||
		!(range = ft_memalloc(sizeof(int) * (ubound - lbound))))
		return (NULL);
	i = 0;
	while (i < (ubound - lbound))
	{
		range[i] = ubound + i;
		i++;
	}
	return (range);
}

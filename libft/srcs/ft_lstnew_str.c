/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 04:02:25 by unite             #+#    #+#             */
/*   Updated: 2019/10/01 04:05:47 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew_str(char const *str)
{
	t_list	*link;

	if (!str)
		return (NULL);
	if (!(link = ft_memalloc(sizeof(t_list))) ||
		!(link->content = ft_strdup(str)))
		return (NULL);
	link->content_size = ft_strlen(str) + 1;
	return (link);
}

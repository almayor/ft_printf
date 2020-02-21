/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <unite@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 23:25:25 by unite             #+#    #+#             */
/*   Updated: 2019/09/30 00:05:51 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew_str_empty(size_t content_size)
{
	t_list	*link;

	if (!(link = (t_list *)ft_memalloc(sizeof(t_list))))
		return (NULL);
	if (!(link->content = ft_strnew(content_size - 1)))
	{
		ft_memdel((void **)&link);
		return (NULL);
	}
	link->content_size = content_size;
	link->next = NULL;
	return (link);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcpyone_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <unite@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 23:29:18 by unite             #+#    #+#             */
/*   Updated: 2019/09/29 23:30:27 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstcpyone_str(t_list const *alst)
{
	t_list	*new_list;

	new_list = (t_list *)ft_memalloc(sizeof(t_list));
	new_list->content_size = alst->content_size;
	new_list->content = ft_strdup(alst->content);
	return (new_list);
}

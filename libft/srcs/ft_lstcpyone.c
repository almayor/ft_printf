/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcpyone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <unite@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 21:42:33 by unite             #+#    #+#             */
/*   Updated: 2019/09/28 23:53:17 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstcpyone(t_list const *alst, void *(*f)(void *))
{
	t_list	*new_list;

	new_list = (t_list *)ft_memalloc(sizeof(t_list));
	new_list->content_size = alst->content_size;
	new_list->content = f(alst->content);
	return (new_list);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <unite@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 21:43:24 by unite             #+#    #+#             */
/*   Updated: 2019/09/29 00:01:08 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstcpy(t_list const *alst, void *(*f)(void *))
{
	t_list	*new_list;
	t_list	*current_link;

	if (!(new_list = ft_lstcpyone(alst, f)))
		return (NULL);
	current_link = new_list;
	while (alst->next)
	{
		alst = alst->next;
		if (!(current_link->next = ft_lstcpyone(alst, f)))
			return (NULL);
		current_link = current_link->next;
	}
	return (new_list);
}

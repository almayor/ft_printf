/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <unite@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 21:43:00 by unite             #+#    #+#             */
/*   Updated: 2019/09/28 23:53:37 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstncpy(t_list const *alst, int n, void *(*f)(void *))
{
	t_list	*new_list;
	t_list	*current_link;

	if (!(new_list = ft_lstcpyone(alst, f)))
		return (NULL);
	current_link = new_list;
	while (n-- > 1)
	{
		alst = alst->next;
		if (!(current_link->next = ft_lstcpyone(alst, f)))
			return (NULL);
		current_link = current_link->next;
	}
	return (new_list);
}

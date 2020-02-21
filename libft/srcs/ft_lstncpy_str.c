/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstncpy_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <unite@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 23:31:24 by unite             #+#    #+#             */
/*   Updated: 2019/09/29 23:32:18 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstncpy_str(t_list const *alst, int n)
{
	t_list	*new_list;
	t_list	*current_link;

	if (!(new_list = ft_lstcpyone_str(alst)))
		return (NULL);
	current_link = new_list;
	while (n-- > 1)
	{
		alst = alst->next;
		if (!(current_link->next = ft_lstcpyone_str(alst)))
			return (NULL);
		current_link = current_link->next;
	}
	return (new_list);
}

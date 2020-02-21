/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcpy_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <unite@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 23:30:36 by unite             #+#    #+#             */
/*   Updated: 2019/09/29 23:31:15 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstcpy_str(t_list const *alst)
{
	t_list	*new_list;
	t_list	*current_link;

	if (!(new_list = ft_lstcpyone_str(alst)))
		return (NULL);
	current_link = new_list;
	while (alst->next)
	{
		alst = alst->next;
		if (!(current_link->next = ft_lstcpyone_str(alst)))
			return (NULL);
		current_link = current_link->next;
	}
	return (new_list);
}

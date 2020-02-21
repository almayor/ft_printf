/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 16:53:17 by unite             #+#    #+#             */
/*   Updated: 2019/09/21 00:37:34 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new_head;
	t_list	*tmp_link;
	t_list	*current_link;
	t_list	*current_new_link;

	if (!lst || !f || !(new_head = f(lst)))
		return (NULL);
	tmp_link = new_head;
	current_link = lst->next;
	while (current_link)
	{
		if (!(current_new_link = f(current_link)))
		{
			ft_lstdel_str(&new_head);
			break ;
		}
		tmp_link->next = current_new_link;
		tmp_link = current_link;
		current_link = current_link->next;
		tmp_link = current_new_link;
	}
	return (new_head);
}

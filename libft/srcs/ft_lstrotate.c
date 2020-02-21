/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 21:44:00 by unite             #+#    #+#             */
/*   Updated: 2019/09/20 23:31:14 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstrotate(t_list **head)
{
	t_list	*new_head;
	t_list	*current_last;

	if (!head || !*head || !(*head)->next)
		return ;
	new_head = (*head)->next;
	current_last = ft_lstlast(*head);
	current_last->next = *head;
	(*head)->next = NULL;
	*head = new_head;
}

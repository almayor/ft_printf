/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 16:40:13 by unite             #+#    #+#             */
/*   Updated: 2019/09/22 20:58:23 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *head;
	t_list *new_head;

	if (!alst || !(*alst) || !del)
		return ;
	head = *alst;
	while (head)
	{
		new_head = head->next;
		del(head->content, head->content_size);
		free(head);
		head = new_head;
	}
	*alst = NULL;
}

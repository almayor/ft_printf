/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 16:40:13 by unite             #+#    #+#             */
/*   Updated: 2019/09/20 23:21:54 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdel_str(t_list **alst)
{
	t_list *head;
	t_list *new_head;

	if (!alst || !(*alst))
		return ;
	head = *alst;
	while (head)
	{
		new_head = head->next;
		free(head->content);
		free(head);
		head = new_head;
	}
	*alst = NULL;
}

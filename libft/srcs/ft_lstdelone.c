/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 16:38:22 by unite             #+#    #+#             */
/*   Updated: 2019/09/22 20:42:57 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*link;

	if (!alst || !(*alst) || !del || !(*del))
		return ;
	link = *alst;
	link->next = NULL;
	del(link->content, link->content_size);
	free(link);
	*alst = NULL;
}

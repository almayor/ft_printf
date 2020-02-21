/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 16:38:22 by unite             #+#    #+#             */
/*   Updated: 2019/09/21 00:22:56 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdelone_str(t_list **alst)
{
	t_list	*link;

	if (!alst || !(*alst))
		return ;
	link = *alst;
	free(link->content);
	free(link);
	*alst = NULL;
}

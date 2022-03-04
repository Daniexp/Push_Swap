/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dexposit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 18:40:18 by dexposit          #+#    #+#             */
/*   Updated: 2022/02/01 19:16:26 by dexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*prev;

	if (!lst)
		return ;
	while (*lst)
	{
		(*del)((*lst)->content);
		prev = *lst;
		*lst = (*lst)->next;
		free(prev);
	}
	*lst = 0;
}

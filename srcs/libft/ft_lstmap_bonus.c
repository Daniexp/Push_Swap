/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dexposit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 19:39:06 by dexposit          #+#    #+#             */
/*   Updated: 2022/02/02 12:13:26 by dexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lstnew;
	t_list	*aux;

	if (!lst || !f)
		return (0);
	lstnew = 0;
	while (lst)
	{
		aux = ft_lstnew((*f)(lst->content));
		if (!aux)
		{
			ft_lstclear(&aux, (*del));
			return (0);
		}
		ft_lstadd_back(&lstnew, aux);
		lst = lst->next;
	}	
	return (lstnew);
}

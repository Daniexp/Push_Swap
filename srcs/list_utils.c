/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dexposit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 18:51:30 by dexposit          #+#    #+#             */
/*   Updated: 2022/03/10 18:54:01 by dexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

void	sv_lst_nrpt(t_list **lst, int num)
{
	int		*ptr;
	t_list	*aux;

	ptr = ft_calloc(1, sizeof(int));
	if (!ptr)
		exit(EXIT_FAILURE);
	*ptr = num;
	aux = *lst;
	while (aux)
	{
		if (*(int *)aux->content == num)
			err_msg();
		aux = aux->next;
	}
	ft_lstadd_back(lst, ft_lstnew((void *)ptr));
}

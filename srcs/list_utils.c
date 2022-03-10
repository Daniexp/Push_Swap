/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dexposit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 18:51:30 by dexposit          #+#    #+#             */
/*   Updated: 2022/03/10 19:41:21 by dexposit         ###   ########.fr       */
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

t_list	*cnv_unsg(t_list *ini)
{
	t_list	*res;
	t_list	*first;
	t_list	*aux;
	int		*ptr;

	res = 0;
	first = ini;
	while (ini)
	{
		ptr = ft_calloc(1,sizeof(int));
		if (!ptr)
			exit(EXIT_FAILURE);
		*ptr = 0;
		aux = first;
		while (aux)
		{
			if (*(int *)ini->content > *(int *)aux->content)
				(*ptr)++;
			aux = aux->next;
		}
		ft_lstadd_back(&res, ft_lstnew((void *)ptr));
		ini = ini->next;
	}
	return (res);
}

size_t	in_order(t_list *lst)
{
	t_list	*sig;

	while (lst->next)
	{
		sig = lst->next;
		if (*(int*)lst->content > *(int*)sig->content)
			return (0);
		lst = lst->next;
	}
	return (1);
}

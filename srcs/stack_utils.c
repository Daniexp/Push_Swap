/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dexposit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 20:49:11 by dexposit          #+#    #+#             */
/*   Updated: 2022/03/13 20:30:16 by dexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

size_t	get_top(t_list *lst)
{
	return (*(int *)lst->content);
}

size_t	get_cnt(t_list *lst, size_t ind)
{
	size_t	i;

	i = 1;
	while (i++ < ind)
		lst = lst->next;
	return (*(int *)lst->content);
}

size_t	get_bottom(t_list *lst)
{
	t_list	*last;

	last = ft_lstlast(lst);
	return (*(int *)last->content);
}

int	dst_between(int n1, int n2)
{
	int	n;

	n = n1 - n2;
	if (n < 0)
		n *= -1;
	n--;
	return (n);
}

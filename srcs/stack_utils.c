/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dexposit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 20:49:11 by dexposit          #+#    #+#             */
/*   Updated: 2022/03/16 21:08:04 by dexposit         ###   ########.fr       */
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

void	mv_both(t_list **stc)
{
	//int	fa;
	//int	sa;
	int	fb;
	int sb;

	if (/*ft_lstsize(stc[0]) >= 2 &&*/ ft_lstsize(stc[1]) >= 2)
	{
		//fa = get_top(stc[0]);
		fb = get_top(stc[1]);
		//sa = get_cnt(stc[0], 2);
		sb = get_cnt(stc[1], 2);
		//if ((fa > sa) && (fb < sb))
		//	put_mv("ss", stc);
		//else if (fa > sa)
		//	put_mv("sa", stc);
		if (fb < sb)
			put_mv("sb", stc);
		//else
		//{
		//	sa = get_bottom(stc[0]);
		//	sb = get_bottom(stc[1]);
	//		if ((sa < fa) && (sb > fb))
	//			put_mvs("rrr", stc);
				//put_mvs("rrr ss rr", stc);
			/*else if (sa < fa)
				put_mvs("rra sa ra", stc);
			else if (sb > fb)
				put_mvs("rrb sb rb", stc);*/
		//}
	}
}

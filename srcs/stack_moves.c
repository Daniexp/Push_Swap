/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dexposit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 20:49:30 by dexposit          #+#    #+#             */
/*   Updated: 2022/03/12 19:39:11 by dexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

void	put_mv(char	*mv, t_list **stc)
{
	ft_putstr_fd(mv, 1);
	ft_putchar_fd('\n', 1);
	if (*mv == 's')
		flt_swap(*(mv + 1), stc);
	else
	{
		if (*mv == 'p')
			flt_push(*(mv + 1), stc);
		else
		{
			if (ft_strlen(mv) == 2)
				flt_rotate(*(mv + 1), stc);
			else
				flt_rev_rot(*(mv + 2), stc);
		}
	}
}

void	swap(t_list **stc)
{
	t_list	*fst;
	t_list	*scn;

	fst = *stc;
	scn = (*stc)->next;
	fst->next = scn->next;
	scn->next = fst;
	*stc = scn;
}

void	push(t_list **src, t_list **dst)
{
	t_list	*fst_src;
	t_list	*scn_src;
	t_list	*fst_dst;

	fst_src = *src;
	scn_src = (*src)->next;
	fst_dst = *dst;
	*src = scn_src;
	*dst = fst_src;
	fst_src->next = fst_dst;
}

void	rotate(t_list **stc)
{
	t_list	*fst;
	t_list	*snd;
	t_list	*lst;

	fst = *stc;
	snd = (*stc)->next;
	lst = ft_lstlast(*stc);
	*stc = snd;
	lst->next = fst;
	fst->next = 0;
}

void	rev_rot(t_list **stc)
{
	t_list	*fst;
	t_list	*prev_lst;
	t_list	*lst;

	fst = *stc;
	lst = ft_lstlast(*stc);
	prev_lst = *stc;
	while ((prev_lst->next)->next)
		prev_lst = prev_lst->next;
	*stc = lst;
	lst->next = fst;
	prev_lst->next = 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dexposit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 20:49:30 by dexposit          #+#    #+#             */
/*   Updated: 2022/03/10 21:55:51 by dexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

void	swap(t_list **stc)
{
	//cambiar el primero por el segundo
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
	//quitar el primero de src y ponerlo en dst
	t_list *fst_src;
	t_list	*scn_src;
	t_list *fst_dst;

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
	lst	= ft_lstlast(*stc);
	*stc = snd;
	lst->next = fst;
	fst->next = 0;
}

void	rev_rot(t_list **stc)
{
	//poner el ultimo como el primero
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

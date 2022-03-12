/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dexposit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 18:31:42 by dexposit          #+#    #+#             */
/*   Updated: 2022/03/12 19:02:03 by dexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

void	flt_swap(char c, t_list **stc)
{
	if (c == 'a')
		swap(&stc[0]);
	else
	{
		if (c == 'b')
			swap(&(stc[1]));
		else
		{
			swap(&stc[0]);
			swap(&stc[1]);
		}
	}
}

void	flt_push(char c, t_list **stc)
{
	if (c == 'a')
		push(&stc[1], &stc[0]);
	else
		push(&(stc[0]), &(stc[1]));
}

void	flt_rotate(char c, t_list **stc)
{
	if (c == 'a')
		rotate(&stc[0]);
	else
	{
		if (c == 'b')
			rotate(&stc[1]);
		else
		{
			rotate(&stc[0]);
			rotate(&stc[1]);
		}
	}
}

void	flt_rev_rot(char c, t_list **stc)
{
	if (c == 'a')
		rev_rot(&stc[0]);
	else
	{
		if (c == 'b')
			rev_rot(&stc[1]);
		else
		{
			rev_rot(&stc[0]);
			rev_rot(&stc[1]);
		}
	}
}

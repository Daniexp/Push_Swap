/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dexposit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 18:31:42 by dexposit          #+#    #+#             */
/*   Updated: 2022/03/26 20:35:06 by dexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

void	put_mvs(char *mvs, t_list **stc)
{
	char	**mv;
	char	**aux;

	mv = ft_split(mvs, ' ');
	if (!mv)
		exit(EXIT_FAILURE);
	aux = mv;
	while (*mv)
	{
		put_mv(*mv, stc, 1);
		mv++;
	}
	free_split(aux);
}

void	flt_swap(char c, t_list **stc)
{
	if (c == 'a')
		swap(&stc[0]);
	else if (c == 'b')
		swap(&(stc[1]));
	else
	{
		swap(&stc[0]);
		swap(&stc[1]);
	}
}

void	flt_push(char c, t_list **stc)
{
	if (c == 'a')
		push(&stc[1], &stc[0]);
	else if (c == 'b')
		push(&(stc[0]), &(stc[1]));
}

void	flt_rotate(char c, t_list **stc)
{
	if (c == 'a')
		rotate(&stc[0]);
	else if (c == 'b')
		rotate(&stc[1]);
	else
	{
		rotate(&stc[0]);
		rotate(&stc[1]);
	}
}

void	flt_rev_rot(char c, t_list **stc)
{
	if (c == 'a')
		rev_rot(&stc[0]);
	else if (c == 'b')
		rev_rot(&stc[1]);
	else
	{
		rev_rot(&stc[0]);
		rev_rot(&stc[1]);
	}
}

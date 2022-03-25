/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dexposit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 20:49:51 by dexposit          #+#    #+#             */
/*   Updated: 2022/03/25 19:33:28 by dexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

int	chase_sa(t_list *stc)
{
	int	n1;
	int	n2;
	int	n3;

	n1 = get_top(stc);
	n2 = get_cnt(stc, 2);
	n3 = get_bottom(stc);
	return ((n1 < n3 && n1 > n2) || (n1 > n2 && n2 > n3)
		|| (n1 < n2 && n1 < n3));
}

int	chase_ra(t_list *stc)
{
	int	n1;
	int	n2;
	int	n3;

	n1 = get_top(stc);
	n2 = get_cnt(stc, 2);
	n3 = get_bottom(stc);
	return ((n1 > n2) && (n2 < n3));
}

int	chase_rra(t_list *stc)
{
	int	n1;
	int	n2;
	int	n3;

	n1 = get_top(stc);
	n2 = get_cnt(stc, 2);
	n3 = get_bottom(stc);
	return ((n1 < n2) && (n1 > n3));
}

void	three_num(t_list **stc)
{
	while (!in_order(stc[0]))
	{
		if (chase_sa(stc[0]) || ft_lstsize(stc[0]) == 2)
			put_mv("sa", stc, 1);
		if (chase_ra(stc[0]))
			put_mv("ra", stc, 1);
		if (chase_rra(stc[0]))
			put_mv("rra", stc, 1);
	}
}
/*
void	threenum(t_list **stc)
{
	while (!in_order(stc[0]))
	{
		if (get_top(stc[0]) - get_cnt(stc[0], 2) == 1)
			put_mv("sa", stc);
		else
		{	if (get_bottom(stc[0]) - get_cnt(stc[0],2) == 1)
				put_mv("ra", stc);
			else
			{
				if (get_top(stc[0]) - get_bottom(stc[0]) == 1)
					put_mv("rra", stc);
				else
				{
					put_mv("sa", stc);
					put_mv("ra", stc);
				}
			}
		}
	}	
}*/

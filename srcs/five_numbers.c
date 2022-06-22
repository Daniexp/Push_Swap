/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_numbers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dexposit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 13:19:12 by dexposit          #+#    #+#             */
/*   Updated: 2022/06/22 16:10:49 by dexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

size_t	move_b(t_list **stc)
{
	int	num;
	int	size;
	int	pvt;

	size = ft_lstsize(stc[0]);
	num = size - 3;
	pvt = size / 2 + size % 2 - 1;
	while (num > 0)
	{
		if (get_top(stc[0]) != pvt)
			put_mv("pb", stc, 1);
		else
			put_mvs("rra pb", stc);
		num--;
	}
	return (size);
}

void	five_num(t_list **stc)
{
	size_t	size;

	size = move_b(stc);
	three_num(stc);
	while (ft_lstsize(stc[0]) != size)
	{
		if (dst_between(get_top(stc[0]), get_top(stc[1])) == 0)
		{
			put_mv("pa", stc, 1);
			if (get_top(stc[0]) > get_cnt(stc[0], 2))
				put_mv("sa", stc, 1);
		}
		else
		{
			if (!dst_between(get_top(stc[1]), get_bottom(stc[0])))
			{
				if (get_top(stc[1]) > get_bottom(stc[0]))
					put_mvs("pa ra", stc);
				else
					put_mvs("rra pa ra ra", stc);
			}
			else
				put_mv("rb", stc, 1);
		}
	}
}

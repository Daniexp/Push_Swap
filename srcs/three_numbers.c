/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dexposit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 20:49:51 by dexposit          #+#    #+#             */
/*   Updated: 2022/03/13 12:33:27 by dexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

void	three_num(t_list **stc)
{
	while (ft_lstsize(stc[1]) != 0 || !in_order(stc[0]))
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
}

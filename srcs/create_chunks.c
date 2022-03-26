/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_chunks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dexposit <dexposit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 22:08:33 by dexposit          #+#    #+#             */
/*   Updated: 2022/03/26 20:55:18 by dexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

int	calc_chks(int n)
{
	int	sz;

	if (n == 100)
		sz = 15;
	else if (n == 500)
		sz = 33;
	else if (sz == 0)
		sz = n / 2;
	else
		sz = n / 10;
	return (sz);
}

int	min_chk(int s, int n)
{
	return (s * (n - 1));
}

int	max_chk(int s, int n)
{
	return (s * n);
}

int	do_mv(char *str, int nm, t_list **stc, int prev)
{
	int	res;

	res = 0;
	while (nm > 0)
	{
		if (!res && prev != 0 && (get_top(stc[1]) == prev
				|| (ft_lstsize(stc[0]) > 0 && get_top(stc[0]) != prev
					&& get_top(stc[1]) == prev - 1)))
		{
			put_mv("pa", stc, 1);
			res = 1;
			if (!ft_strncmp(str, "rb", 2))
				nm--;
		}
		else
		{
			put_mv(str, stc, 1);
			nm--;
		}
	}
	return (res);
}

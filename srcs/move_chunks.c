/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_chunks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dexposit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 19:39:24 by dexposit          #+#    #+#             */
/*   Updated: 2022/03/24 20:27:13 by dexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

int	src_cdts(int max, int min, t_list **stc)
{
	t_list	*aux;
	int		res;

	aux = stc[0];
	res = 0;
	while (aux && !res)
	{
		if (*(int *)aux->content <= max && *(int *)aux->content >= min)
			res = 1;
		aux = aux->next;
	}
	return (res);
}

int	ind_chk(int max, int min, t_list *stc, int mode)
{
	int	res;
	int	i;
	int	tp;

	tp = ft_lstsize(stc);
	if (min < 0)
		min = 0;
	//if (tp == 1 && get_top(stc) >= min && get_top(stc) <= max)
	res = 0;
	i = 1;
	if (mode == 0)
	{
//		printf("tamaño de a: %d\nmax chk: %d\nmin chk: %d\n", tp, max, min);
		while (i <= tp && (get_cnt(stc, i) < min || get_cnt(stc, i) > max))
			i++;
		res = i - 1;
		//res = 1000000;
	}
	else if (mode == 1)
	{
		while (i <= tp && (get_cnt(stc, tp) < min || get_cnt(stc, tp) > max))
			tp--;
	//	res = ft_lstsize(stc) - tp + 1;
		res = 1000000;
	}
	return (res);
}

int	mv_chks(int cnt, int sz, t_list **stc, int flag)
{
	int	mid_vl;
	int	ind_up;
	int	ind_down;

	mid_vl = (ft_lstsize(stc[0]) + ft_lstsize(stc[1])) / 2;
	if ((ft_lstsize(stc[0]) + ft_lstsize(stc[1])) % 2 != 0)
		mid_vl++;
	while (src_cdts(mid_vl + cnt * sz, mid_vl - cnt * sz, stc))
	{
		ind_up = ind_chk(mid_vl + cnt * sz, mid_vl - cnt * sz, stc[0], 0);
		ind_down = ind_chk(mid_vl + cnt * sz, mid_vl - cnt * sz, stc[0], 1);
		if (ind_up <= ind_down)
			do_mv("ra", ind_up, stc, 0);
		else if (ind_down < ind_up)
			do_mv("rra", ind_down, stc, 0);
//		print_stc(stc[0]);
		put_mv("pb", stc);
		if (get_top(stc[1]) < mid_vl && flag == 1)
			put_mv("rb", stc);
		else if (flag == 0 && get_top(stc[1]) > mid_vl)
			flag = 1;
		//if (ft_lstsize(stc[1]) > 1 && get_top(stc[1]) < get_cnt(stc[1], 2))
		//	put_mv("sb", stc);
	}
	return (flag);
}

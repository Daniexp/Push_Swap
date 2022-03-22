/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dexposit <dexposit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 20:23:34 by dexposit          #+#    #+#             */
/*   Updated: 2022/03/22 19:35:26 by dexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

/*
	RESUMEN DEL ALGORITMO
	Dividir nuestro array en grupos de números de x a y.
	Mover de a los números pertenecientes a un chunk x para b.
	Sacar un chunk de b ordenado para a.

*/

void	chunk(t_list **stc)
{
	int sz;
	int cnt;
	int	n_chk;

/*	sz = (ft_lstsize(stc[0]) / 13) + 22;;
	if (sz % 2 == 0)
		sz++;
	n_chk = ft_lstsize(stc[0]) / sz;
	if ((sz * n_chk) < ft_lstsize(stc[0]))
		n_chk++;*/
//	sz  = calc_chks(ft_lstsize(stc[0]));
//	n_chk = ft_lstsize(stc[0]) / sz;
//	if (ft_lstsize(stc[0]) % sz)
//			n_chk++;
	sz = 19;
	n_chk = ft_lstsize(stc[0]) / sz;
	if (ft_lstsize(stc[0]) % sz)
		n_chk++;
	cnt = 1;
	while (cnt <= n_chk)
	{
		sch_mv(max_chk(sz, cnt), stc);
		cnt++;
	}
	while (cnt-- > 0)
		order_chk(min_chk(sz, cnt), stc);
}

void	order_chk(int min, t_list **stc)
{
	int	ind_max;
	int	vl_max;
	int	ind_md;
	int	prev;

	prev = 0;
	while (ft_lstsize(stc[1]) && src_chk(min, stc[1]))
	{
		ind_max =  pos_max(stc[1]);
		if (ind_max == 1)
		{
			put_mv("pa", stc);
			if (prev == 1 && (get_top(stc[0]) > get_cnt(stc[0], 2)))
				put_mv("sa", stc);
		}
		else
		{
			vl_max = get_cnt(stc[1], ind_max);
			ind_md = ft_lstsize(stc[1]) / 2;
			if (ft_lstsize(stc[1]) % 2 != 0)
				ind_md++;
			if (ind_md > ind_max)
				prev = do_mv("rb", ind_max - 1, stc, vl_max  - 1);
			else if (ind_md <= ind_max)
				 prev = do_mv("rrb", ft_lstsize(stc[1]) - ind_max + 1, stc, vl_max - 1);
		}
	}
}

int	src_chk(int min, t_list *stc)
{
	int		res;
	t_list	*aux;
	
	aux = stc;
	res = 0;
	while (aux && !res)
	{
		if (*(int *)aux->content >= min)
			res = 1;
		aux = aux->next;
	}
	return (res);
}

int	pos_max(t_list *stc)
{
	t_list	*aux;
	int		max;
	int		ind;
	int		res;

	ind = 1;
	max = -1;
	aux = stc;
	while (aux)
	{
		if (*(int *)aux->content > max)
		{
			max = *(int *)aux->content;
			res = ind;
		}
		ind++;
		aux = aux->next;
	}
	return (res);
}

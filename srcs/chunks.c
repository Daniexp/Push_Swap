/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dexposit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 20:23:34 by dexposit          #+#    #+#             */
/*   Updated: 2022/03/16 19:07:49 by dexposit         ###   ########.fr       */
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

	sz = (ft_lstsize(stc[0]) / 13) + 22;;
	if (sz % 2 == 0)
		sz++;
	n_chk = ft_lstsize(stc[0]) / sz;
	if ((sz * n_chk) < ft_lstsize(stc[0]))
		n_chk++;
//	sz  = calc_chks(ft_lstsize(stc[0]));
	cnt = 1;
//		printf(" hola %d ", max_chk(sz, cnt));
	while (cnt <= n_chk)
	{
//		printf(" hola %d ", cnt);
		sch_mv(max_chk(sz, cnt), stc);
		cnt++;
	}
	//order_lst_chk(stc);
	while (cnt-- > 0)
		order_chk(min_chk(sz, cnt), stc);
		//cnt--;
	//printf("sz %d cnt %d", sz, cnt);
	//order_chk(min_chk(sz, cnt - 1), stc);
}

void	order_chk(int min, t_list **stc)
{
	int	ind_max;
	int	vl_max;
	int	ind_md;

	while (ft_lstsize(stc[1]) && src_chk(min, stc[1]))
	{
		//max_min???
		ind_max =  pos_max(stc[1]);
		if (ind_max == 1)
		{
			put_mv("pa", stc);
			//mv_both(stc);
		}
		else
		{
		vl_max = get_cnt(stc[1], ind_max);
		ind_md = ft_lstsize(stc[1]) / 2;
		if (ft_lstsize(stc[1]) % 2 != 0)
			ind_md++;
		//printf ("ind max %d,  ind min %d\n", ind_max, ind_md);
		if (ind_md >= ind_max)
			//usar rb;
			do_mv("rb", ind_max - 1, stc);
		else if (ind_md < ind_max)
				do_mv("rrb", ft_lstsize(stc[1]) - ind_max + 1, stc);	
		}
		//usar rrb;
		//move_top(src_biggest(stc[1]));
		//mv_both(stc); //si puedo ordenar lso primeros de a y b o primero y ult
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

	ind = 0;
	max = -1;
	aux = stc;
	while (aux)
	{
		if (*(int *)aux->content > max)
		{
			max = *(int *)aux->content;
			ind++;
		}
		aux = aux->next;
	}
	return (ind);
}

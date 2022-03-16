/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dexposit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 20:23:34 by dexposit          #+#    #+#             */
/*   Updated: 2022/03/16 01:58:23 by dexposit         ###   ########.fr       */
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

	sz  = calc_chks(ft_lstsize(stc[0]));
	cnt = 1;
		printf(" hola %d ", max_chk(sz, cnt));
	while (cnt < sz)
	{
		printf(" hola %d ", cnt);
		sch_mv(max_chk(sz, cnt), stc);
		cnt++;
	}
}

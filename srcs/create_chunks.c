/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_chunks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dexposit <dexposit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 22:08:33 by dexposit          #+#    #+#             */
/*   Updated: 2022/03/24 20:19:22 by dexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

/*
	Los números van de 0 hasta n - 1
	0 1 2 3 ... n
	n = size de la lista de números a  ordenar.
	Lo quiero dividir en x grupos de tamaño
	x = raiz cuadrada de n.
	por lo que nuestro numero de grupos es 
		n / x + 1 si (n % x).
		la raiz cuadrada es entera ej si n es 12.
		tendremos grupos de 3 numeros pero 4 grupos.
	Cada grupo tiene un max y un mín.
		para un grupo  llamado z
		max del grupo z es: z * tmñ del grupo.
		min es z - 1 * tmñ del grupo.
	min >=  datos < max

*/

int calc_chks(int n)
{
	int pow;

	pow = 1;
	while(pow * pow < n)
		pow++;
	return (pow);
}

int min_chk(int s, int n)
{
	return (s * (n - 1));
}

int	max_chk(int s, int n)
{
	return (s * n);
}

/*
	Para buscar los candidatos
	necesitamos saber cuantos numeros nos quedan por mover
		necesitamos el numero de ra hasta encontrar un candidato y el
		numero de rra para buscar desde abajo
		nos quedamos el menor y lo metemos en b
		repetir hasta que no queden candidatos en a
*/

void 	sch_mv(int max, t_list **stc)
{
	while (cnt_cdt(max, stc))
	{
	//		printf("%d\n", max);
			src_cdt(max, stc);
	}
}

int	cnt_cdt(int max, t_list **stc)
{
	int 	res;
	t_list	*aux;

	res = 0;
	aux = *stc;
	while (aux)
	{
	//		printf("%d\n", res);
		if (*(int *)aux->content < max)
			res++;
		aux = aux->next;
	}
	return (res);
}

void	src_cdt(int max, t_list **stc)
{
	int 	ra;
	int 	rra;
	char	*mv;
	int		cnt;
	//se puede mejorar si comprobamos 3 números antes de enviarlos
	//para meterlos mas ordenados si se da ambiguedad
	//		printf("%d\n", max);
	//mv_both(stc);
	if ((int) get_top(stc[0]) < max)
	{
		put_mv("pb", stc);
//		if (ft_lstsize(stc[1]) >= 2 && get_top(stc[1]) < get_cnt(stc[1], 2))
//			put_mv("sb", stc);
	}
	else
	{
		//se podria mejorar en el caso de ser igual calcular el camino mas perqueño del siguiente candidato
		ra = cnt_mv(0 , max, stc[0]);
		rra = cnt_mv(1 , max, stc[0]);
		if (ra < rra)
			do_mv("ra", ra, stc, 0);
		if (ra > rra)
			do_mv("rra", rra, stc, 0);
		if (ra == rra)
		{
			if (get_cnt(stc[0], ra + 1) <
					get_cnt(stc[0], ft_lstsize(stc[0]) - rra - 1))
				do_mv("ra", ra, stc, 0);
			else
				do_mv("rra", rra, stc, 0);
		}
	}
}

int	check_prev(t_list **stc, int prev, int mv, char *str)
{
	int	res;
	int	ind_prev;
	int ind_max;

	if (ft_lstsize(stc[1]) < 6)
		return (1);
	res = 1;
	ind_prev = get_ind(prev, stc[1]);
	if (!ft_strncmp(str, "rb", 2))
	{
		//buscar si esta prev en antes de llegar a mv desde el principio de la lista
		//si esta comprobar la distancia de el anterior es decir su indice
		if (ind_prev < mv /*&& ((ind_prev - 1) < (mv - ind_prev))*/)
			res = 0;
	}
	else if (!ft_strncmp(str, "rrb", 3))
	{
		ind_max = ft_lstsize(stc[1]) - mv - 2;
		if (ind_max < ind_prev/* && ((ind_prev - ind_max) > (ft_lstsize(stc[1]) - ind_prev + 1))*/)
			res = 0;
	}
	return (res);
}

int	get_ind(int vl, t_list *stc)
{
	int 	res;
	t_list	*aux;

	aux = stc;
	res = 1;
	while (aux && *(int *)aux->content != vl)
	{
		res++;
		aux = aux->next;
	}
	if (!aux)
		res = -1;
	return (res);
}

int	do_mv(char *str, int nm, t_list **stc, int prev)
{
	int	res;

	res = 0;
	//printf("valor movimientos: %d\n", nm);
	while (nm > 0)
	{
		if (!res && prev != 0 && (get_top(stc[1]) == prev || (ft_lstsize(stc[0]) > 0 && get_top(stc[0]) != prev && get_top(stc[1]) == prev - 1)))
		{
			//if (get_top(stc[1]) == prev || (get_top(stc[1]) == prev - 1 && check_prev(stc, prev, nm + 1, str))) 
			//{
			put_mv("pa", stc);
			res = 1;
			if (!ft_strncmp(str, "rb", 2))
				nm--;
			//}
		}
		else
		{
			put_mv(str, stc);
			nm--;
		}
	}
	return (res);
}

int		cnt_mv(int mv, int max, t_list *stc)
{
	int		cnt;
	int		i;
	int		tp;
	int		pr;

	cnt = 0;
	i = 1;
	tp = ft_lstsize(stc);
	if (mv == 0)
	{
		while (i <= tp && get_cnt(stc, i) >= max)
		{
			cnt++;
			i++;
		}
	}
	else
	{
		cnt = 1;
		while (get_cnt(stc, tp) >= max)
		{
			cnt++;
			tp--;
		}
	}
	return (cnt);
}

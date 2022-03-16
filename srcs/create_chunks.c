/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_chunks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dexposit <dexposit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 22:08:33 by dexposit          #+#    #+#             */
/*   Updated: 2022/03/16 02:12:49 by dexposit         ###   ########.fr       */
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
			printf("%d\n", max);
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
			printf("%d\n", res);
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
			printf("%d\n", max);
	if ((int) get_top(stc[0]) < max)
		put_mv("pb", stc);
	else
	{
		//se podria mejorar en el caso de ser igual calcular el camino mas perqueño del siguiente candidato
		ra = cnt_mv(0 , max, stc[0]);
		rra = cnt_mv(1 , max, stc[0]);
		if (ra < rra)
			do_mv("ra", ra, stc);
		else
			do_mv("rra", rra, stc);
	}
}

void	do_mv(char *str, int nm, t_list **stc)
{
	while (nm > 0)
	{
			printf("3\n");
		put_mv(str, stc);
		nm--;
	}
}

int		cnt_mv(int mv, int max, t_list *stc)
{
	int		cnt;
	int		i;
	int		tp;

	cnt = 0;
	i = 1;
	tp = ft_lstsize(stc);
	if (mv == 0)
	{
		printf("%d %d %d", i, tp, max);
		while (i <= tp && get_cnt(stc, i) >= max)
		{
			printf("1\n");
			cnt++;
			i++;
		}
	}
	else
	{
		while (tp <= i && get_cnt(stc, tp) >= max)
		{
			printf("2\n");
			cnt++;
			tp--;
		}
	}
	return (cnt);
}

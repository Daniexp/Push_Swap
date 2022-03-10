/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dexposit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 15:29:53 by dexposit          #+#    #+#             */
/*   Updated: 2022/03/10 21:56:02 by dexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./incl/push_swap.h"

/*
 *	The push_swap must to take several numbers in the sanme argument and split
 *	then with a space ex "2 3 4" this are 2->3->4
 *	repeat this process for all the arguments.
 *	the split give us a **str with the strings of the number for position so
 *	we have to convert it with the atoi to and int.
 *	if we can´t convert some split result in to a int we stop the program and
 *	exit and error.
 *		stop the program -> free the split and the list
 *	if the convert was success we put it in a t_list
 */

int main(int argc, char **argv)
{
	t_list	*arg_lst;
	t_list	*aux;
	t_list	**aa;

	arg_lst = svarg(argc - 1, argv);
	if (!in_order(arg_lst))
		aa = create_stacks(arg_lst);
	swap(&(aa[0]));
	//push(&aa[0], &aa[1]);
	//rotate(&aa[0]);
	//printf("tmñ: %d\n", ft_lstsize(aa[0]));
	aux = aa[0];
		//aux = cnv_unsg(arg_lst);
	while (aux)
	{
		printf("%d\n", *(int *)aux->content);
		aux = aux->next;
	}
	//printf("b : %d\n", *(int *)aa[1]->content);
	exit(EXIT_SUCCESS);
}

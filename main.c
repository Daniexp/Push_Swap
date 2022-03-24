/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dexposit <dexposit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 15:29:53 by dexposit          #+#    #+#             */
/*   Updated: 2022/03/24 21:29:31 by dexposit         ###   ########.fr       */
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
	if (in_order(arg_lst))
		return (0);	
	aa = create_stacks(arg_lst);
	if (ft_lstsize(aa[0]) <= 5)
		five_num(aa);
	else
		chunk(aa);
	//swap(&(aa[0]));
	//put_mv("sa", aa);
	//push(&aa[0], &aa[1]);
	//rotate(&aa[0]);
	//printf("tmñ: %d\n", ft_lstsize(aa[0]));
	aux = aa[0];
		//aux = cnv_unsg(arg_lst);
/*	printf("stack a\n");
	print_stc(aux);
	aux = aa[1];
	printf("stack b\n");
	print_stc(aux);*/
//	if (in_order(aa[0]))
//			printf("OK");
	//printf("\n tercer puesto: %zu\n", get_cnt(aa[0], 3)); 
	//printf("b : %d\n", *(int *)aa[1]->content);
	free_lst(&(aa[0]));
	free_lst(&(aa[1]));
	free(aa);
	//printf("%d\n", *(int *)(aa[0])->content);
	return (0);
}

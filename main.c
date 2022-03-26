/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dexposit <dexposit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 15:29:53 by dexposit          #+#    #+#             */
/*   Updated: 2022/03/26 22:01:15 by dexposit         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_list	*arg_lst;
	t_list	**stacks;

	arg_lst = svarg(argc - 1, argv);
	if (!arg_lst || in_order(arg_lst))
		return (0);
	stacks = create_stacks(arg_lst);
	if (ft_lstsize(stacks[0]) <= 5)
		five_num(stacks);
	else
		chunk(stacks);
	free_lst(&(stacks[0]));
	free_lst(&(stacks[1]));
	free(stacks);
	return (0);
}

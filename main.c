/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dexposit <dexposit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 15:29:53 by dexposit          #+#    #+#             */
/*   Updated: 2022/06/24 11:54:19 by dexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./incl/push_swap.h"

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

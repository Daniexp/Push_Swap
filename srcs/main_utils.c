/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dexposit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 18:51:06 by dexposit          #+#    #+#             */
/*   Updated: 2022/03/26 22:02:12 by dexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

void	err_msg(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

void	print_stc(t_list *stc)
{
	t_list	*aux;

	aux = stc;
	while (aux)
	{
		printf("%d\n", *(int *)aux->content);
		aux = aux->next;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dexposit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 20:49:09 by dexposit          #+#    #+#             */
/*   Updated: 2022/03/24 21:03:43 by dexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

int main(int argc, char **argv)
{
	if (in_order(stc[0]) && ft_lstsize(stc[1]) == 0)
	ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);

}

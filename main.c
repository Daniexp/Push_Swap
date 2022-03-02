/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dexposit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 15:29:53 by dexposit          #+#    #+#             */
/*   Updated: 2022/03/02 17:57:03 by dexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	argc--;
	char c;
	while (	argc >= 0)
	{
		c = (char) *argv[argc];
		ft_putchar_fd(c, 1);
		ft_putchar_fd('\n', 1);
		argc--;
	}
	return (0);
}

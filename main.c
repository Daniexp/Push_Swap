/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dexposit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 15:29:53 by dexposit          #+#    #+#             */
/*   Updated: 2022/03/04 21:27:03 by dexposit         ###   ########.fr       */
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
	if (!svarg(argc - 1, argv))
		exit(EXIT_FAILURE);
	//si no pasamos argumentos salgo del programa
	if (argc <= 1)
		exit(EXIT_FAILURE);
	//ahora toca convertir los argumentos a int.
	//haremos uso del split y atoi de la lib.
	//printf("ra\n");	
}

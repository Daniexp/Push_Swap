/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dexposit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 14:14:37 by dexposit          #+#    #+#             */
/* ************************************************************************** */

#include "../incl/push_swap.h"

void	str_valid(char *str)
{
	size_t	cnt;

	cnt = 0;
	while (*str)
	{
		if (*str == '-' || *str == '+')
		{
			if (ft_isdigit(*(str -1)) || !*(str + 1))
				exit(EXIT_FAILURE);
			cnt++;
		}
		else
			if (*str != ' ' && !ft_isdigit(*str))
				exit(EXIT_FAILURE);
		str++;
	}
	if (cnt >= 2)
		exit(EXIT_FAILURE);
	return ;
}

void	error_msg(void)
{
	char	*str;

	str = "Error\n";
	write(2, str, 6);
	exit(EXIT_FAILURE);
}

size_t	svarg(int argc, char **argv)
{	
	size_t	i;
	char	**splitarg;
	char	**aux;

	if (argc == 0)
		error_msg();
		i = 1;
		while (i <= argc)
		{
			if (*(argv[i]))
			{
				splitarg = ft_split(argv[i], ' ');
				if (!*splitarg)
					exit(EXIT_FAILURE);
			}
			else
				exit(EXIT_FAILURE);
			aux = splitarg;
			while (*splitarg)
			{
				str_valid(*splitarg);
				printf("%d\n", ft_atoi(*splitarg));//meter en lista
				splitarg++;
			}
			free(aux);
			i++;
		}
	return (1);
}

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

size_t	str_valid(char *str)
{
	size_t	ok;
	size_t	cnt;

	ok = 1;
	cnt = 0;
	while (*str)
	{
		if (*str == '-' || *str == '+')
		{
			if ((*(str - 1)) && ft_isdigit(*(str -1)))
					return (0);
			cnt++;
		}
		else
			if (*str != ' ' && !ft_isdigit(*str))
				return (0);
		str++;
	}
	if (cnt >= 2)
		ok = 0;
	return (ok);
}

size_t	svarg(int argc, char **argv)
{	
	size_t	i;
	char	**splitarg;
	char	**aux;

	if (argc == 0)
		return (0);
	{
		i = 1;
		while (i <= argc)
		{
			if (*(argv[i]))
				splitarg = ft_split(argv[i], ' ');
			else
				return (0);
			aux = splitarg;
			while (*splitarg)
			{
				//antes de hacer el atoi comprobar si hay algún caracter
				//o dos signos seguidos
				//printf("%s\n", *aux);
				//printf("len: %zu\n", ft_strlen(*aux)); 
				if (str_valid(*splitarg))
					printf("%d\n", ft_atoi(*splitarg));//meter en lista
				else
					return (0);
				splitarg++;
			}
			free(aux);
			i++;
		}
	}	
	return (1);
}

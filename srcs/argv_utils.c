/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dexposit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 14:14:37 by dexposit          #+#    #+#             */
/*   Updated: 2022/06/22 16:07:55 by dexposit         ###   ########.fr       */
/*                                                                            */
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
				err_msg();
			cnt++;
		}
		else if (*str != ' ' && !ft_isdigit(*str))
				err_msg();
		str++;
	}
	if (cnt >= 2)
		err_msg();
	return ;
}

char	**arg_split(char **arg)
{
	char	**res;

	res = ft_split(*arg, ' ');
	if (!**arg || !*res)
		err_msg();
	return (res);
}

int	chk_atoi(char *str)
{
	int	res;

	res = ft_atoi(str);
	if (res == 0 && ft_strlen(str) > 2)
		err_msg();
	return (res);
}

void	free_split(char **split)
{
	char	**cpy;
	char	*aux;

	cpy = split;
	while (*split)
	{
		aux = *split;
		free(aux);
		split++;
	}
	free(cpy);
}

t_list	*svarg(int argc, char **argv)
{	
	size_t	i;
	char	**splitarg;
	char	**aux;
	t_list	*lst;

	if (argc == 0)
		return (0);
	i = 1;
	lst = 0;
	while (i <= argc)
	{
		splitarg = arg_split(&(argv[i]));
		aux = splitarg;
		while (*splitarg)
		{
			str_valid(*splitarg);
			sv_lst_nrpt(&lst, chk_atoi(*splitarg));
			splitarg++;
		}
		free_split(aux);
		i++;
	}
	return (lst);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dexposit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 16:11:22 by dexposit          #+#    #+#             */
/*   Updated: 2022/02/01 16:09:23 by dexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	space(const char c)
{
	return (c == ' ' || c == '\t' || c == '\n'
		|| c == '\r' || c == '\v' || c == '\f');
}

int	ft_atoi(const char *nptr)
{
	int				sign;
	unsigned int	res;

	while (space(*nptr))
		nptr++;
	sign = 1;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign *= -1;
		nptr++;
	}
	res = 0;
	while (ft_isdigit(*nptr))
	{
		res *= 10;
		res += *nptr - '0';
		nptr++;
		if (res > 2147483657 && sign == 1)
			return (-1);
		if (res > 2147483648 && sign == -1)
			return (0);
	}
	return (sign * res);
}

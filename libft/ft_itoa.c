/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dexposit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 17:33:50 by dexposit          #+#    #+#             */
/*   Updated: 2022/02/02 12:17:50 by dexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_digits(int n)
{
	size_t	count;

	count = 1;
	while (n / 10 != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static int	abs_value(int n)
{
	if (n < 0)
		n *= -1;
	return (n);
}

static void	fill_string(char *str, size_t len, int n, size_t sign)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		str[i] = abs_value(n % 10) + '0';
		n = n / 10;
		i++;
	}
	if (sign)
	{
		str[i] = '-';
		i++;
	}
	str[i] = '\0';
}

static	void	rvs_string(char *str)
{
	int		len;
	int		mid;
	int		i;
	char	aux;

	i = 0;
	len = ft_strlen(str) - 1;
	mid = len / 2;
	while (i <= mid)
	{
		aux = str[i];
		str[i] = str[len - i];
		str[len - i] = aux;
		i++;
	}
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t	strlen;
	size_t	sign;

	sign = 0;
	if (n < 0)
		sign = 1;
	strlen = count_digits(n) + sign + 1;
	str = malloc(sizeof(char) * strlen);
	if (!str)
		return (0);
	if (sign)
	{
		strlen--;
		n = abs_value(n);
	}
	fill_string(str, strlen - 1, n, sign);
	rvs_string(str);
	return (str);
}

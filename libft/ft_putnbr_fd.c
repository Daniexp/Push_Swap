/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dexposit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 13:05:35 by dexposit          #+#    #+#             */
/*   Updated: 2022/02/01 18:01:10 by dexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_digits(long n)
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

static int	calc_div(size_t nd)
{
	int	res;

	res = 1;
	while (nd > 1)
	{
		res *= 10;
		nd--;
	}
	return (res);
}

void	ft_putnbr_fd(int n, int fd)
{
	long	nl;
	int		div;

	nl = n;
	if (nl < 0)
	{
		write(fd, "-", 1);
		nl *= -1;
	}
	div = calc_div(count_digits(nl));
	while (div > 0)
	{
		ft_putchar_fd(nl / div + '0', fd);
		nl %= div;
		div /= 10;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dexposit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 12:24:34 by dexposit          #+#    #+#             */
/*   Updated: 2022/02/02 11:36:56 by dexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	char			*aux;
	unsigned int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		aux = &s[i];
		(*f)(i, aux);
		i++;
	}
}

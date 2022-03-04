/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dexposit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 18:04:03 by dexposit          #+#    #+#             */
/*   Updated: 2022/02/01 16:33:21 by dexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	i;

	if (!s)
		return (0);
	str = ft_strdup(s);
	if (!str)
		return (0);
	if (f)
	{
		i = 0;
		while (str[i])
		{
			str[i] = (*f)(i, str[i]);
			i++;
		}
	}
	return (str);
}

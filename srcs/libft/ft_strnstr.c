/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dexposit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 13:46:29 by dexposit          #+#    #+#             */
/*   Updated: 2022/01/26 16:08:34 by dexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	ls1;
	size_t	ls2;

	if (!*s2)
		return ((char *)s1);
	ls1 = 0;
	while (s1[ls1])
	{
		ls2 = 0;
		while ((s2[ls2] == s1[ls1 + ls2]) && ((ls1 + ls2) < len))
		{
			if (s1[ls1 + ls2] == '\0' || s2[ls2] == '\0')
				return ((char *)&s1[ls1]);
			ls2++;
		}
		if (!s2[ls2])
			return ((char *)s1 + ls1);
		ls1++;
	}
	return (0);
}

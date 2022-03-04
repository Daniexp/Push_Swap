/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dexposit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 17:02:36 by dexposit          #+#    #+#             */
/*   Updated: 2022/01/25 22:43:07 by dexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	srclen;

	srclen = ft_strlen(src);
	if (srclen + 1 < size)
	{
		ft_memcpy(dst, src, srclen + 1);
	}
	else
	{
		if (size != 0)
		{
			ft_memcpy(dst, src, size - 1);
			dst[size - 1] = '\0';
		}
	}
	return (srclen);
}

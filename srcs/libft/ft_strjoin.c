/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dexposit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 19:40:38 by dexposit          #+#    #+#             */
/*   Updated: 2022/02/01 16:15:30 by dexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	len;

	if (!s1 || !s2)
		return (0);
	len = 1 + ft_strlen(s1) + ft_strlen(s2);
	res = malloc(sizeof(char) * len);
	if (!res)
		return (0);
	ft_strlcpy(res, s1, ft_strlen(s1) + 1);
	ft_strlcat(res, s2, len);
	return (res);
}

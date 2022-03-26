/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dexposit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 19:29:27 by dexposit          #+#    #+#             */
/*   Updated: 2022/02/26 22:45:48 by dexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*subs;
	size_t	i;
	size_t	j;

	if (!s)
		return (0);
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	if (start > ft_strlen(s))
		len = 0;
	subs = (char *)malloc(len + 1);
	if (!subs)
		return (0);
	i = start;
	j = 0;
	while (j < len)
	{
		subs[j++] = s[i++];
	}
	subs[j] = '\0';
	return (subs);
}

char	*ft_strchr(const char *s, int c)
{
	while ((*s != (unsigned char)c) && *s)
		s++;
	if (!*s && c != 0)
		return (0);
	return ((char *)s);
}

void	*ft_memcpy(void *dest, const void *src, size_t len)
{
	size_t	i;

	if (!dest && !src)
		return (0);
	i = 0;
	while (i < len)
	{
		((char *)dest)[i] = ((char *)src)[i];
		i++;
	}
	return (dest);
}

char	*cat(char *first, char *end)
{
	char	*res;
	size_t	len;

	if (!first)
	{
		free(first);
		res = ft_substr(end, 0, ft_strlen(end));
		if (!res)
			return (0);
	}
	else
	{
		len = 1 + ft_strlen(first) + ft_strlen(end);
		res = malloc(sizeof(char) * len);
		if (!res)
			return (0);
		ft_memcpy(res, first, ft_strlen(first));
		ft_memcpy(res + ft_strlen(first), end, ft_strlen(end));
		res[len - 1] = '\0';
		free(first);
	}
	return (res);
}

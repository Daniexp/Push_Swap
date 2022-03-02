/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dexposit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 12:43:48 by dexposit          #+#    #+#             */
/*   Updated: 2022/02/02 12:22:43 by dexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	size_t	count;
	size_t	word;

	count = 0;
	word = 0;
	while (*s)
	{
		if (!word && *s != c)
		{
			word = 1;
			count++;
		}
		if (word && *s == c)
			word = 0;
		s++;
	}
	return (count);
}

static void	save_word(char	**dst, char	**str, char c)
{
	char	*aux;

	while (**str == c)
		*str = *str + 1;
	aux = ft_strchr(*str, c);
	if (aux == 0)
		aux = *str + 1 + ft_strlen(*str);
	*dst = ft_substr(*str, 0, aux - *str);
	while ((aux - *str) != 0)
		*str = *str + 1;
}

static void	free_memory(char **res, size_t i)
{
	while (i-- >= 0)
		free(res[i]);
	free(res);
}

char	**ft_split(char const *s, char c)
{
	char	*str;
	size_t	nw;
	char	**res;
	size_t	i;

	if (!s)
		return (0);
	nw = count_words(s, c);
	str = (char *)s;
	res = malloc(sizeof(char *) * (nw + 1));
	if (!res)
		return (0);
	i = 0;
	while (i < nw)
	{
		save_word(&(res[i]), &str, c);
		if (res[i] == 0)
			free_memory(res, i);
		i++;
	}
	res[i] = 0;
	return (res);
}

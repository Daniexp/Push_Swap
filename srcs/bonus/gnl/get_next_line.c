/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dexposit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 19:29:14 by dexposit          #+#    #+#             */
/*   Updated: 2022/02/27 18:30:05 by dexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	cut(char **aux_str, char *ind_line, char **result, char **rest_read)
{
	if (ind_line)
	{
		*result = ft_substr(*aux_str, 0, ind_line - *aux_str + 1);
		if (ft_strlen(*result) != ft_strlen(*aux_str))
			*rest_read = ft_substr(ind_line + 1, 0, ft_strlen(ind_line + 1));
		free(*aux_str);
		return (1);
	}
	return (0);
}

char	*end_file(char **read_str, char **aux_str, char **result)
{
	free(*read_str);
	if (*aux_str)
	{
		*result = ft_substr(*aux_str, 0, ft_strlen(*aux_str));
		free(*aux_str);
	}
	return (*result);
}

int	cut_lines(int mode, char **aux, char **res, int fd)
{
	int	cnt;

	cnt = 0;
	if (mode == 1)
	{
		*aux = 0;
		*res = 0;
	}
	if (mode == 2)
	{
		*res = ft_substr(*aux, 0, ft_strlen(*aux));
		free(*aux);
	}
	if (mode == 3)
	{
		free(*aux);
		*aux = NULL;
	}
	if (mode == 4)
	{
		*aux = malloc(BUFFER_SIZE * sizeof(char) + 1);
		cnt = read(fd, *aux, BUFFER_SIZE);
		(*aux)[cnt] = '\0';
	}
	return (cnt);
}

char	*get_next_line(int fd)
{
	static char	*rest_read = 0;
	char		*aux_str;
	char		*read_str;
	char		*result;
	int			cnt_bytes;

	cut_lines(1, &aux_str, &result, 0);
	if (rest_read)
	{
		aux_str = ft_substr(rest_read, 0, ft_strlen(rest_read));
		cut_lines(3, &rest_read, 0, 0);
		cut(&aux_str, ft_strchr(aux_str, '\n'), &result, &rest_read);
	}
	while (!result)
	{
		cnt_bytes = cut_lines(4, &read_str, 0, fd);
		if (cnt_bytes <= 0)
			return (end_file(&read_str, &aux_str, &result));
		aux_str = cat(aux_str, read_str);
		if (!cut(&aux_str, ft_strchr(aux_str, '\n'), &result, &rest_read)
			&& cnt_bytes < BUFFER_SIZE)
			cut_lines(2, &aux_str, &result, 0);
		free(read_str);
	}
	return (result);
}

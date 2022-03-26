/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dexposit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 19:16:15 by dexposit          #+#    #+#             */
/*   Updated: 2022/03/26 18:37:04 by dexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/checker.h"

int	valid_move(char *mv)
{
	int	res;

	res = 1;
	if (ft_strlen(mv) < 2 || ft_strlen(mv) > 3 || ((ft_strlen(mv) == 2 && ft_strncmp(mv, "pa", 2) && ft_strncmp(mv, "pb", 2) && ft_strncmp(mv, "sa", 2) && ft_strncmp(mv, "sb", 2) && ft_strncmp(mv, "ss", 2) && ft_strncmp(mv, "ra", 2) && ft_strncmp(mv, "rb", 2) && ft_strncmp(mv, "rr", 2)) || (ft_strlen(mv) == 3 && ft_strncmp(mv, "rra", 3) && ft_strncmp(mv, "rrb", 3) && ft_strncmp(mv, "rrr", 3))))
	err_msg();
//	printf("mov dado como malo es: %s\n", mv);
	return (res);
}

char	*read_move(int fd)
{
	char	*read;
	char	*res;

	read = get_next_line(fd);
	if (!read)
		return (0);
//	if (read[ft_strlen(read)] == '\n')
	res = ft_substr(read, 0, ft_strlen(read) - 1);
	free(read);
	valid_move(res);
	return (res);
}

int main(int argc, char **argv)
{
	t_list	**stc;
	char	*mv;
	int		fd;

	fd = 0;
	stc = create_stacks(svarg(argc -1, argv));
	if (!stc)
		return (0);
	//mv = ft_strtrim(get_next_line(fd), "\n");
	//mv = read_move(fd);
	while (1)
	{
		//check_mv(mv);
		mv = read_move(fd);
		if (!mv)
			break ;
		put_mv(mv, stc, 0);
		free(mv);
		//mv = ft_strtrim(get_next_line(fd), "\n");
	}
	free(mv);
	if (in_order(stc[0]) && ft_lstsize(stc[1]) == 0)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
}

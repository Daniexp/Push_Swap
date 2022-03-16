/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dexposit <dexposit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 22:49:40 by dexposit          #+#    #+#             */
/*   Updated: 2022/03/16 02:08:39 by dexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHUNK_H
# define CHUNK_H

typedef struct	s_chunk
{
	int num;
	int	size;
}				t_chunk;

int		calc_chks(int n);
int		min_chk(int s, int n);
int		max_chk(int s, int n);
void	sch_mv(int max, t_list **stc); 
int		cnt_cdt(int max, t_list **stc);
void	src_cdt(int max, t_list **stc);
void	do_mv(char *str, int nm, t_list **stc);
int		cnt_mv(int mv, int max, t_list *stc);

#endif

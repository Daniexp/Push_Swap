/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dexposit <dexposit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 22:49:40 by dexposit          #+#    #+#             */
/*   Updated: 2022/03/26 20:54:17 by dexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHUNK_H
# define CHUNK_H

int		calc_chks(int n);
int		min_chk(int s, int n);
int		max_chk(int s, int n);
int		do_mv(char *str, int nm, t_list **stc, int prev);
void	order_chk(int min, t_list **stc);
int		src_chk(int min, t_list *stc);
int		pos_max(t_list *stc);
int		mv_chks(int cnt, int sz, t_list **stc, int flag);

#endif

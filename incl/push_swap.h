/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dexposit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 15:23:43 by dexposit          #+#    #+#             */
/*   Updated: 2022/03/13 17:31:33 by dexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../srcs/libft/libft.h"
# include <unistd.h>
# include <stdlib.h>

t_list	*svarg(int argc, char **argv);
void	err_msg(void);
void	sv_lst_nrpt(t_list **lst, int num);
t_list	*cnv_unsg(t_list *ini);
size_t	in_order(t_list *lst);
t_list	**create_stacks(t_list *lst);
void	free_lst(t_list **lst);
void	free_split(char **split);
void	put_mvs(char *mvs, t_list **stc);
void	put_mv(char *mv, t_list **stc);
void	flt_swap(char c, t_list **stc);
void	flt_push(char c, t_list **stc);
void	flt_rotate(char c, t_list **stc);
void	flt_rev_rot(char c, t_list **stc);
void	swap(t_list **stc);
void	push(t_list **src, t_list **dst);
void	rotate(t_list **stc);
void	rev_rot(t_list **stc);
size_t	get_cnt(t_list *lst, size_t ind);
size_t	get_top(t_list *lst);
size_t	get_bottom(t_list *lst);
int		dst_between(int n1, int n2);
void	three_num(t_list **stc);
void	five_num(t_list **stc);

#endif

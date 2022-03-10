/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dexposit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 15:23:43 by dexposit          #+#    #+#             */
/*   Updated: 2022/03/10 21:52:14 by dexposit         ###   ########.fr       */
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
void	swap(t_list **stc);
void	push(t_list **src, t_list **dst);
void	rotate(t_list **stc);
void	rev_rot(t_list **stc);

#endif

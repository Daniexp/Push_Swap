/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dexposit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 15:23:43 by dexposit          #+#    #+#             */
/*   Updated: 2022/03/04 21:27:08 by dexposit         ###   ########.fr       */
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

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dexposit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 18:40:49 by dexposit          #+#    #+#             */
/*   Updated: 2022/02/01 18:41:00 by dexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_block;

	new_block = malloc(sizeof(t_list));
	if (!new_block)
		return (0);
	new_block->content = content;
	new_block->next = 0;
	return (new_block);
}

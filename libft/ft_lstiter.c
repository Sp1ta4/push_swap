/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggevorgi <sp1tak.gg@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 20:47:45 by ggevorgi          #+#    #+#             */
/*   Updated: 2025/02/11 12:54:58 by ggevorgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_stack_node *lst, void (*f)(void *))
{
	t_stack_node	*i;

	if (!lst || !f)
		return ;
	i = lst;
	while (i)
	{
		f(i->data);
		i = i->next;
	}
}

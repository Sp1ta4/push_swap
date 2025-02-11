/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggevorgi <sp1tak.gg@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 17:14:56 by ggevorgi          #+#    #+#             */
/*   Updated: 2025/02/11 13:11:39 by ggevorgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_stack_node	*ft_lstnew(void *data, size_t index)
{
	t_stack_node	*nnode;

	nnode = (t_stack_node *)malloc(sizeof(t_stack_node));
	if (!nnode)
		return (NULL);
	nnode->data = data;
	nnode->index = index;
	nnode->next = NULL;
	return (nnode);
}

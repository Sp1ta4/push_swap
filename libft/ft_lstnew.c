/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggevorgi <sp1tak.gg@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 17:14:56 by ggevorgi          #+#    #+#             */
/*   Updated: 2024/11/02 20:03:50 by ggevorgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*nnode;

	nnode = (t_list *)malloc(sizeof(t_list));
	if (!nnode)
		return (NULL);
	nnode->content = content;
	nnode->next = NULL;
	return (nnode);
}

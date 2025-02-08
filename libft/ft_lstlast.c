/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggevorgi <sp1tak.gg@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 20:17:41 by ggevorgi          #+#    #+#             */
/*   Updated: 2024/11/02 20:22:31 by ggevorgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*lstcpy;

	if (!lst)
		return (NULL);
	lstcpy = lst;
	while (lstcpy->next)
	{
		lstcpy = lstcpy->next;
	}
	return (lstcpy);
}

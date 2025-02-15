/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_helpers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggevorgi <sp1tak.gg@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 17:11:02 by ggevorgi          #+#    #+#             */
/*   Updated: 2025/02/15 15:56:29 by ggevorgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	throw_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	free_ptr(void **p)
{
	if (p && *p)
	{
		free(*p);
		*p = NULL;
	}
}

void	free_split(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	free_list(t_stack *list)
{
	t_stack	*tmp;

	while (list)
	{
		tmp = list->next;
		free(list);
		list = tmp;
	}
}

size_t	ft_atol_strlen(const char *s)
{
	const char	*scp;
	int			i;
	size_t		len;

	len = 0;
	i = 0;
	scp = s;
	while (scp[i] != '\0')
	{
		if (scp[i] != '0')
			++len;
		++i;
	}
	return (len);
}

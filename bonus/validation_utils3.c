/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_utils3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggevorgi <sp1tak.gg@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:52:38 by ggevorgi          #+#    #+#             */
/*   Updated: 2025/02/17 09:14:16 by ggevorgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	check_null(void *arg)
{
	if (!arg)
	{
		free_ptr((void **)&arg);
		exit(1);
	}
}

void	check_idx_arr(size_t *i_array, int *n_array, char **char_nums)
{
	if (!i_array)
	{
		free_ptr((void **)n_array);
		free_split(char_nums);
		exit(1);
	}
}

void	success(void)
{
	write(1, "OK\n", 3);
}

void	fail(void)
{
	write(1, "KO\n", 3);
}

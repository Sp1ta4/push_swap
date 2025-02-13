/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_utils3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggevorgi <sp1tak.gg@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:52:38 by ggevorgi          #+#    #+#             */
/*   Updated: 2025/02/13 13:03:23 by ggevorgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
		
void	check_NULL(void *arg)
{
	if (!arg)
	{
		free_ptr((void **)&arg);
		exit(1);
	}
}
void check_nums_array(int *num_arr, char **char_nums_arr)
{
	if (!num_arr)
		exit(1);
	if (is_sorted(num_arr))
	{
		free_ptr((void**)&char_nums_arr);
		free_ptr((void**)&num_arr);
		exit(1);
	}
}

void check_indexes_arr(size_t *indexes_array, int *nums_array, char **char_nums_array)
{
	if (!indexes_array)
	{
		free_ptr((void **)nums_array);
		free_split(char_nums_array);
		exit(1);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggevorgi <sp1tak.gg@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 18:35:03 by ggevorgi          #+#    #+#             */
/*   Updated: 2025/02/16 18:46:38 by ggevorgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	init_stack(t_stack **stack, size_t *indexes_array, char **argv)
{
	char	**char_nums_array;
	int		*nums_array;
	size_t	nums_len;

	char_nums_array = create_splited_numbers(argv);
	check_null(char_nums_array);
	nums_len = array_length(char_nums_array);
	nums_array = check_and_create_atoi_array(char_nums_array);
	check_nums_arr(nums_array, char_nums_array, nums_len);
	indexes_array = take_sorted_indexes(nums_array, nums_len);
	check_idx_arr(indexes_array, nums_array, char_nums_array);
	free_split(char_nums_array);
	*stack = create_stack(nums_array, indexes_array, nums_len);
}

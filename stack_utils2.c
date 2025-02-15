/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggevorgi <sp1tak.gg@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 18:35:03 by ggevorgi          #+#    #+#             */
/*   Updated: 2025/02/15 15:30:13 by ggevorgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	create_butterfly(t_stack **a_stack, t_stack **b_stack)
{
	size_t	counter;
	size_t	available_number_range;
	t_stack	*tmp;

	counter = 0;
	available_number_range = get_available_number_range(ft_lstsize(*a_stack));
	while (*a_stack)
	{
		tmp = *a_stack;
		if (tmp->index <= counter)
		{
			push_s_to_f(b_stack, a_stack, "pb\n");
			rotate_begin_to_end(b_stack, "rb\n");
			++counter;
		}
		else if (tmp->index <= counter + available_number_range)
		{
			push_s_to_f(b_stack, a_stack, "pb\n");
			++counter;
		}
		else
			rotate_begin_to_end(a_stack, "ra\n");
	}
}

size_t	find_max_index_pos(t_stack *stack)
{
	size_t	max_index;
	size_t	pos;
	size_t	max_pos;

	max_index = 0;
	pos = 0;
	max_pos = 0;
	while (stack)
	{
		if (stack->index > max_index)
		{
			max_index = stack->index;
			max_pos = pos;
		}
		pos++;
		stack = stack->next;
	}
	return (max_pos);
}

void	rotate_begin_to_end_n(t_stack **stack, char *op, size_t n)
{
	while (n--)
		rotate_begin_to_end(stack, op);
}

void	rr_begin_to_end_n(t_stack **stack, char *op, size_t n)
{
	while (n--)
		reverse_rotate_begin_to_end(stack, op);
}

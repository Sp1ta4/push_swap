/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggevorgi <sp1tak.gg@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 18:35:03 by ggevorgi          #+#    #+#             */
/*   Updated: 2025/02/13 18:35:23 by ggevorgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void init_stack(t_stack_node **stack, size_t *indexes_array, char **argv)
{
	char			**char_nums_array;
	int				*nums_array;
	size_t				nums_len;
	
	char_nums_array = create_splited_numbers(argv);
	// printf("%s\n", char_nums_array[0]);
	check_NULL(char_nums_array);
	nums_len = array_length(char_nums_array);
	nums_array = check_and_create_atoi_array(char_nums_array);
	check_nums_array(nums_array, char_nums_array);	
	indexes_array = take_sorted_indexes(nums_array, nums_len);
	check_indexes_arr(indexes_array, nums_array, char_nums_array);
	free_split(char_nums_array);
	// print_numarray(nums_array, nums_len);
	// print_sizetarray(indexes_array, nums_len);
	*stack = create_stack(nums_array, indexes_array, nums_len);
}

void create_butterfly(t_stack_node **a_stack, t_stack_node **b_stack)
{
	size_t	counter;
	size_t	available_number_range;

	counter = 0;
	available_number_range = get_available_number_range(ft_lstsize(*a_stack));
	while ((*a_stack))
	{
		if ((*a_stack)->index <= counter)
		{
			push_second_to_first(b_stack, a_stack, "pb\n");
			rotate_begin_to_end(b_stack, "rb\n");
			++counter;
		}
		else if ((*a_stack)->index <= counter + available_number_range)
		{
			push_second_to_first(b_stack, a_stack, "pb\n");
			++counter;
		}
		else
			rotate_begin_to_end(a_stack, "ra");
	}
	
}

size_t find_last_index (t_stack_node *stack)
{
	size_t index;

	index = stack->index;
	stack = stack->next;
	while (stack)
	{
		if (stack->index > index)
			index = stack->index;
		stack = stack->next;	
	}
	return (index);
}
void fill_stack(t_stack_node **a_stack, t_stack_node **b_stack)
{
	
}

void sort_stack(t_stack_node **a_stack, t_stack_node **b_stack)
{
	// if (ft_lstsize(*a_stack) <= 5)
	// 	sort_for_less_steps(a_stack, b_stack);
	
	create_butterfly(a_stack, b_stack);
	fill_a_stack(a_stack, b_stack);
}

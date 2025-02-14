/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggevorgi <sp1tak.gg@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 18:35:03 by ggevorgi          #+#    #+#             */
/*   Updated: 2025/02/14 18:55:32 by ggevorgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void init_stack(t_stack_node **stack, size_t *indexes_array, char **argv)
{
	char	**char_nums_array;
	int		*nums_array;
	size_t	 nums_len;
	
	char_nums_array = create_splited_numbers(argv);
	check_NULL(char_nums_array);
	nums_len = array_length(char_nums_array);
	nums_array = check_and_create_atoi_array(char_nums_array);
	check_nums_array(nums_array, char_nums_array, nums_len);
	
	indexes_array = take_sorted_indexes(nums_array, nums_len);
	check_indexes_arr(indexes_array, nums_array, char_nums_array);
	free_split(char_nums_array);
	*stack = create_stack(nums_array, indexes_array, nums_len);
}

void create_butterfly(t_stack_node **a_stack, t_stack_node **b_stack)
{
	size_t counter = 0;
	size_t available_number_range = get_available_number_range(ft_lstsize(*a_stack));
	
	while (*a_stack)
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
			rotate_begin_to_end(a_stack, "ra\n");
	}
}

size_t find_last_index(t_stack_node *stack)
{
	size_t index = stack->index;
	stack = stack->next;
	while (stack)
	{
		if (stack->index > index)
			index = stack->index;
		stack = stack->next;
	}
	return (index);
}

size_t find_max_index_pos(t_stack_node *stack)
{
    size_t max_index = stack->index;
    size_t res = 0;
    size_t pos = 0;

    stack = stack->next;
    while (stack)
    {
        pos++;
        if (stack->index > max_index)
        {
            max_index = stack->index;
            res = pos;
        }
        stack = stack->next;
    }
    return (res);
}


void fill_stack(t_stack_node **a_stack, t_stack_node **b_stack)
{
	size_t max_index_pos;
	size_t b_size;
	size_t i;
	
	while (*b_stack)
	{
		max_index_pos = find_max_index_pos(*b_stack);
		b_size = ft_lstsize(*b_stack);
		i = 0;
		if (max_index_pos <= b_size / 2)
		{
			while (i++ < (b_size - max_index_pos))
				rotate_begin_to_end(b_stack, "rb\n");
		}
		else
		{
			while (i++ < (b_size - max_index_pos))
				reverse_rotate_begin_to_end(b_stack, "rrb\n");
		}
		push_second_to_first(a_stack, b_stack, "pa\n");
	}
}
void sort_three_elems_stack(t_stack_node **stack)
{
    size_t a = (*stack)->index;
    size_t b = (*stack)->next->index;
    size_t c = (*stack)->next->next->index;

    if (a > b && a > c && b > c) // 3 2 1
    {
        swap_begin_second(stack, "sa\n");
        reverse_rotate_begin_to_end(stack, "rra\n");
    }
    else if (a > b && a > c && b < c) // 3 1 2
        rotate_begin_to_end(stack, "ra\n");
    else if (a < b && a > c) // 2 3 1
        reverse_rotate_begin_to_end(stack, "rra\n");
    else if (a > b && a < c) // 2 1 3
        swap_begin_second(stack, "sa\n");
    else if (a < b && a < c && b > c) // 1 3 2
    {
        swap_begin_second(stack, "sa\n");
        rotate_begin_to_end(stack, "ra\n");
    }
}

void find_rotate_way(t_stack_node **stack, t_stack_node *node)
{
	t_stack_node	*tmp;
	size_t			stack_size;
	size_t			i;

	i = 0;
	stack_size = ft_lstsize(*stack);
	tmp = *stack;
	while ((*stack)->index != node->index)
	{
		*stack = (*stack)->next;
		i++;
	}
	*stack = tmp;
	if (i > stack_size / 2)
		while ((*stack)->data != node->data)
			reverse_rotate_begin_to_end(stack, "rra\n");
	else
		while ((*stack)->data != node->data)
			rotate_begin_to_end(stack, "ra\n");	
}

void sort_under_twelve(t_stack_node **a_stack, t_stack_node **b_stack)
{
	t_stack_node *tmp;
	size_t size;
	size_t i;
	
	size = ft_lstsize(*a_stack);
	i = 0;
	while (size > 3)
	{
		tmp = *a_stack;	
		while (tmp->index != i)
			tmp = tmp->next;
		find_rotate_way(a_stack, tmp);
		push_second_to_first(b_stack, a_stack, "pb\n");
		--size;
		i++;
	}
	sort_three_elems_stack(a_stack);
	while (*b_stack)
		push_second_to_first(a_stack, b_stack, "pa\n");
}
void sort_stack(t_stack_node **a_stack, t_stack_node **b_stack)
{
	// size_t stack_size = ft_lstsize(*a_stack);
	// if (stack_size == 2)
    //     swap_begin_second(a_stack, "sa\n");
	// else if (stack_size <= 12)
	// 	sort_under_twelve(a_stack, b_stack);
	// else
	// {
		create_butterfly(a_stack, b_stack);
		fill_stack(a_stack, b_stack);
	// }
}

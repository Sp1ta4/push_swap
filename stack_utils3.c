/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggevorgi <sp1tak.gg@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 14:17:45 by ggevorgi          #+#    #+#             */
/*   Updated: 2025/02/15 15:23:03 by ggevorgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_stack(t_stack **a_stack, t_stack **b_stack)
{
	size_t	max_index_pos;
	size_t	b_size;

	while (*b_stack)
	{
		max_index_pos = find_max_index_pos(*b_stack);
		b_size = ft_lstsize(*b_stack);
		if (max_index_pos <= b_size / 2)
			rotate_begin_to_end_n(b_stack, "rb\n", max_index_pos);
		else
			rr_begin_to_end_n(b_stack, "rrb\n", b_size - max_index_pos);
		push_s_to_f(a_stack, b_stack, "pa\n");
	}
}

void	sort_three_elems_stack(t_stack **stack)
{
	size_t	a;
	size_t	b;
	size_t	c;

	a = (*stack)->index;
	b = (*stack)->next->index;
	c = (*stack)->next->next->index;
	if (a > b && a > c && b > c)
	{
		swap_begin_second(stack, "sa\n");
		reverse_rotate_begin_to_end(stack, "rra\n");
	}
	else if (a > b && a > c && b < c)
		rotate_begin_to_end(stack, "ra\n");
	else if (a < b && a > c)
		reverse_rotate_begin_to_end(stack, "rra\n");
	else if (a > b && a < c)
		swap_begin_second(stack, "sa\n");
	else if (a < b && a < c && b > c)
	{
		swap_begin_second(stack, "sa\n");
		rotate_begin_to_end(stack, "ra\n");
	}
}

void	find_rotate_way(t_stack **stack, t_stack *node)
{
	t_stack	*tmp;
	size_t	stack_size;
	size_t	pos;

	tmp = *stack;
	pos = 0;
	stack_size = ft_lstsize(*stack);
	while (tmp && tmp->index != node->index)
	{
		pos++;
		tmp = tmp->next;
	}
	if (pos > stack_size / 2)
		rr_begin_to_end_n(stack, "rra\n", stack_size - pos);
	else
		rotate_begin_to_end_n(stack, "ra\n", pos);
}

void	sort_under_twelve(t_stack **a_stack, t_stack **b_stack)
{
	t_stack	*tmp;
	size_t	size;
	size_t	i;

	size = ft_lstsize(*a_stack);
	i = 0;
	while (size > 3)
	{
		tmp = *a_stack;
		while (tmp->index != i)
			tmp = tmp->next;
		find_rotate_way(a_stack, tmp);
		push_s_to_f(b_stack, a_stack, "pb\n");
		--size;
		i++;
	}
	sort_three_elems_stack(a_stack);
	while (*b_stack)
		push_s_to_f(a_stack, b_stack, "pa\n");
}

void	sort_stack(t_stack **a_stack, t_stack **b_stack)
{
	size_t	stack_size;

	stack_size = ft_lstsize(*a_stack);
	if (stack_size == 2)
		swap_begin_second(a_stack, "sa\n");
	else if (stack_size <= 12)
		sort_under_twelve(a_stack, b_stack);
	else
	{
		create_butterfly(a_stack, b_stack);
		fill_stack(a_stack, b_stack);
	}
}

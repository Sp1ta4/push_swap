/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggevorgi <sp1tak.gg@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 18:51:26 by ggevorgi          #+#    #+#             */
/*   Updated: 2025/02/17 09:04:43 by ggevorgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	check_op_and_null_terminate(char **operation)
{
	if (!operation || !*operation)
		throw_error();
	if ((*operation)[ft_strlen(*operation) - 1] == '\n')
		(*operation)[ft_strlen(*operation) - 1] = '\0';
}

void	do_operation(t_stack **a_stack, t_stack **b_stack, char **op)
{
	check_op_and_null_terminate(op);
	if (!ft_strncmp(*op, "sa", 2))
		swap_begin_second(a_stack, NULL);
	else if (!ft_strncmp(*op, "sb", 2))
		swap_begin_second(b_stack, NULL);
	else if (!ft_strncmp(*op, "pa", 2))
		push_s_to_f(a_stack, b_stack, NULL);
	else if (!ft_strncmp(*op, "pb", 2))
		push_s_to_f(b_stack, a_stack, NULL);
	else if (!ft_strncmp(*op, "ra", 2))
		rotate_begin_to_end(a_stack, NULL);
	else if (!ft_strncmp(*op, "rb", 2))
		rotate_begin_to_end(b_stack, NULL);
	else if (!ft_strncmp(*op, "rra", 3))
		reverse_rotate_begin_to_end(a_stack, NULL);
	else if (!ft_strncmp(*op, "rrb", 3))
		reverse_rotate_begin_to_end(b_stack, NULL);
	else
	{
		free(*op);
		throw_error();
	}
	free(*op);
	*op = get_next_line(0);
}

size_t	is_tmp_stack_empty(t_stack *stack)
{
	return (ft_lstsize(stack));
}

int	is_stack_sorted(t_stack *stack)
{
	while (stack->next)
	{
		if (stack->data > stack->next->data)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	check_result(t_stack *a_stack, t_stack *b_stack, char **op)
{
	if (is_stack_sorted(a_stack) && !is_tmp_stack_empty(b_stack))
		success();
	else
		fail();
	free(*op);
}

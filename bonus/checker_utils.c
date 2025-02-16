/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggevorgi <sp1tak.gg@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 18:51:26 by ggevorgi          #+#    #+#             */
/*   Updated: 2025/02/16 18:51:34 by ggevorgi         ###   ########.fr       */
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

void do_sorting_operation(t_stack **a_stack, t_stack **b_stack, char **operation)
{
    check_op_and_null_terminate(operation);
    if (!ft_strncmp(*operation, "sa", 2))
        swap_begin_second(a_stack, NULL);
    else if (!ft_strncmp(*operation, "sb", 2))
        swap_begin_second(b_stack, NULL);
    else if (!ft_strncmp(*operation, "pa", 2))
        push_s_to_f(a_stack, b_stack, NULL);
    else if (!ft_strncmp(*operation, "pb", 2))
        push_s_to_f(b_stack, a_stack, NULL);
    else if (!ft_strncmp(*operation, "ra", 2))
        rotate_begin_to_end(a_stack, NULL);
    else if (!ft_strncmp(*operation, "rb", 2))
        rotate_begin_to_end(b_stack, NULL);
    else if (!ft_strncmp(*operation, "rra", 3))
        reverse_rotate_begin_to_end(a_stack, NULL);
    else if (!ft_strncmp(*operation, "rrb", 3))
        reverse_rotate_begin_to_end(b_stack, NULL);
    else
    {
        free(*operation);
        throw_error();
    }
    free(*operation);
    *operation = get_next_line(0);
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

void check_result(t_stack *a_stack, t_stack *b_stack, char **op)
{
	if (is_stack_sorted(a_stack) && !is_tmp_stack_empty(b_stack))
		success();
	else
		fail();	
	free(*op);	
}

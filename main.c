/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggevorgi <sp1tak.gg@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 20:05:50 by ggevorgi          #+#    #+#             */
/*   Updated: 2025/02/14 18:57:08 by ggevorgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_numarray (int *arr, int length)
{
	int i;

	i = -1;
	write(1, "[", 1);
	while (++i < length)
	{
		i + 1 == length ? printf("%d]\n", arr[i]) : printf("%d, ", arr[i]);
	}
}
void print_sizetarray (size_t *arr, int length)
{
	int i;

	i = -1;
	write(1, "[", 1);
	while (++i < length)
	{
		i + 1 == length ? printf("%ld]\n", arr[i]) : printf("%ld, ", arr[i]);
	}
}
void print_stack(t_stack_node *stack)
{
	if (!stack)
	{
		printf("пусто\n");
		return;
	}
	while (stack)
	{
		printf("%d ", stack->data);
		stack = stack->next;
	}
	printf("\n");
}
void print_stacks(t_stack_node *stack_a, t_stack_node *stack_b)
{
	printf("Stack A: ");
	print_stack(stack_a);

	printf("Stack B: ");
	print_stack(stack_b);
}


int	main(int argc, char **argv)
{
	
	t_stack_node	*a_stack_begin;
	t_stack_node	*b_stack_begin;
	size_t				*indexes_array;

	if (argc > 2 && argv)
	{
		if (!is_valid_params(argv + 1, argc - 1))
			throw_error();
		b_stack_begin = NULL;
		a_stack_begin = NULL;
		indexes_array = NULL;
		init_stack(&a_stack_begin, indexes_array, argv + 1);
		// print_stack(a_stack_begin);j
		// print_stacks(a_stack_begin, b_stack_begin);
		sort_stack(&a_stack_begin, &b_stack_begin);
		// printf("size---------------->%d\n", ft_lstsize(a_stack_begin));
		// printf("-------------------->%d\n", b_stack_begin->data);
		print_stacks(a_stack_begin, b_stack_begin);
		free_list(a_stack_begin);
		free_list(b_stack_begin);
	}
	return (0);
}
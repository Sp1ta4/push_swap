/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggevorgi <sp1tak.gg@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 20:05:50 by ggevorgi          #+#    #+#             */
/*   Updated: 2025/02/15 15:41:20 by ggevorgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a_stack_begin;
	t_stack	*b_stack_begin;
	size_t	*indexes_array;

	if (argc >= 2 && argv && argv[1][0] != '\0')
	{
		if (argc == 2)
			if (ft_isnotdigit(argv[1]) && ft_isprint(argv[1][0]))
				throw_error();
		if (!is_valid_params(argv + 1, argc - 1))
			throw_error();
		b_stack_begin = NULL;
		a_stack_begin = NULL;
		indexes_array = NULL;
		init_stack(&a_stack_begin, indexes_array, argv + 1);
		sort_stack(&a_stack_begin, &b_stack_begin);
		free_list(a_stack_begin);
		free_list(b_stack_begin);
	}
	return (0);
}

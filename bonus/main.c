/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggevorgi <sp1tak.gg@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 17:25:52 by ggevorgi          #+#    #+#             */
/*   Updated: 2025/02/17 09:02:14 by ggevorgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int argc, char **argv)
{
	char	*command;
	t_stack	*a_stack_begin;	
	t_stack	*b_stack_begin;	
	size_t	*indexes_array;

	if (argc >= 2 && argv && argv[1][0] != '\0')
	{
		if (argc == 2)
			if (ft_isnotdigit(argv[1], 0, 0) && ft_isprint(argv[1][0]))
				throw_error();
		if (!is_valid_params(argv + 1, argc - 1))
			throw_error();
		b_stack_begin = NULL;
		a_stack_begin = NULL;
		indexes_array = NULL;
		init_stack(&a_stack_begin, indexes_array, argv + 1);
		command = get_next_line(0);
		while (command)
			do_operation(&a_stack_begin, &b_stack_begin, &command);
		check_result(a_stack_begin, b_stack_begin, &command);
		free_list(a_stack_begin);
		free_list(b_stack_begin);
	}
	return (0);
}

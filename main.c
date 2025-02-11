/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggevorgi <sp1tak.gg@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 20:05:50 by ggevorgi          #+#    #+#             */
/*   Updated: 2025/02/11 15:57:08 by ggevorgi         ###   ########.fr       */
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




int	main(int argc, char **argv)
{
	char			**char_nums_array;
	int				*nums_array;
	size_t				nums_len;
	t_stack_node	*a_stack_begin;
	t_stack_node	*b_stack_begin;
	size_t				*indexes_array;

	if (argc > 2 && argv)
	{
		if (!is_valid_params(argv + 1, argc - 1))
			throw_error();
		char_nums_array = create_splited_numbers(argv + 1);
		check_NULL(char_nums_array);
		nums_len = array_length(char_nums_array);
		nums_array = check_and_create_atoi_array(char_nums_array);
		check_nums_array(nums_array, char_nums_array);	
		indexes_array = take_sorted_indexes(nums_array, nums_len);
		check_indexes_arr(indexes_array, nums_array, char_nums_array);
		print_numarray(nums_array, nums_len);
		print_sizetarray(indexes_array, nums_len);
		a_stack_begin = create_stack(nums_array, indexes_array, nums_len);
		b_stack_begin = NULL;
		printf("%p\n", b_stack_begin);
		printf("size---------------->%d\n", ft_lstsize(a_stack_begin));
	}
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggevorgi <sp1tak.gg@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 20:05:50 by ggevorgi          #+#    #+#             */
/*   Updated: 2025/02/11 13:31:59 by ggevorgi         ###   ########.fr       */
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



t_stack_node *create_stack(int *nums_array, size_t *indexes_array, size_t length)
{
	t_stack_node	*stack;
	t_stack_node	*tmp_lst;
	size_t				i;

	stack = ft_lstnew(&nums_array[0], indexes_array[0]);
	if (!stack)
		return (NULL);
	i = 0;
	while (++i < length)
	{
		tmp_lst = ft_lstnew(&nums_array[i], indexes_array[i]);
		if (!tmp_lst)
			return (NULL);
		ft_lstadd_back(&stack, tmp_lst);	
	}
	return (stack);
}
void check_nums_array(int *num_arr, char **char_nums_arr)
{
	if (!num_arr)
		exit(1);
	if (is_sorted(num_arr))
	{
		free_ptr((void**)&char_nums_arr);
		free_ptr((void**)&num_arr);
		exit(1);
	}
}

void check_indexes_arr(size_t *indexes_array, int *nums_array, char **char_nums_array)
{
	if (!indexes_array)
	{
		free_ptr((void **)nums_array);
		free_ptr((void **)char_nums_array);
		exit(1);
	}
}

int	main(int argc, char **argv)
{
	char			**char_nums_array;
	int				*nums_array;
	size_t				nums_len;
	t_stack_node	*a_stack_begin;
	size_t				*indexes_array;

	if (argc > 1 && argv)
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
		printf("size---------------->%d\n", ft_lstsize(a_stack_begin));
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggevorgi <sp1tak.gg@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 20:05:50 by ggevorgi          #+#    #+#             */
/*   Updated: 2025/02/10 22:14:24 by ggevorgi         ###   ########.fr       */
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

void	check_NULL(void *arg)
{
	if (!arg)
		exit(1);
}

// t_stack_node *create_stack(int *nums_array)
// {
	
// }

void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
void sort_arr(int *arr, int length)
{
	int	i;
	int	j;
	int	is_swapped;

	i = 0;
	while(i < length -1)
	{
		is_swapped = 0;
		j = 0;
		while (j < length - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(&arr[j], &arr[j + 1]);
				is_swapped = 1;
			}
			j++;
		}
		if (!is_swapped)
			break;
		i++;
	}
}
int ft_index_of(int *arr, int num, int len)
{
	int i;

	i = -1;
	while (++i < len)
	{
		if (arr[i] == num)
			return (i);
	}
	return (-1);
}

int *take_sorted_indexes(int *arr, int length)
{
	int	*indexes;
	int	*sorted_arr;
	int	i;
	
	sorted_arr = (int *)malloc(sizeof(int) * length);
	indexes = (int *)malloc(sizeof(int) * length);
	i = -1;
	while (++i < length)
		sorted_arr[i] = arr[i];
	sort_arr(sorted_arr, length);
	i = -1;
	while (++i < length)
	{
		indexes[i] = ft_index_of(arr, sorted_arr[i], length);
	}
	print_numarray(sorted_arr, length);
	free(sorted_arr);
	return (indexes);
}

int	main(int argc, char **argv)
{
	char **char_nums_array;
	int *nums_array;
	int nums_len;
	// t_stack_node	*a_stack_begin;
	int				*indexes_array;

	if (argc > 1 && argv)
	{
		if (!is_valid_params(argv + 1, argc - 1))
			throw_error();
		char_nums_array = create_splited_numbers(argv + 1);
		check_NULL(char_nums_array);
		nums_len = array_length(char_nums_array);
		nums_array = check_and_create_atoi_array(char_nums_array);
		check_NULL(nums_array);
		indexes_array = take_sorted_indexes(nums_array, nums_len);
		// a_stack_begin = create_stack(nums_array);
		print_numarray(nums_array, nums_len);
		print_numarray(indexes_array, nums_len);
	}
	return (0);
}
